// TwoCoins subajat1 Copyright 2026


#include "TC_SimpleStateManager.h"

#include "TC_FSMSimpleLog.h"
#include "TC_FSMState.h"
#include "TC_FSMSystem.h"
#include "States/TC_DeinitState.h"
#include "States/TC_InitState.h"
#include "States/TC_NeutralState.h"
#include "States/TC_PatrolState.h"


UTC_SimpleStateManager::UTC_SimpleStateManager()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetComponentTickInterval(1.f);
}

void UTC_SimpleStateManager::BeginPlay()
{
	Super::BeginPlay();

	BindFSM();
	InitializeFSM();
}

void UTC_SimpleStateManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	DeinitializeFSM();
	UnbindFSM();
	Super::EndPlay(EndPlayReason);
}

void UTC_SimpleStateManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (fsm)
	{
		fsm->Update(DeltaTime);
	}
}

void UTC_SimpleStateManager::StateTransitionTo(const FName stateNameToTransitTo)
{
	if (!fsm)
	{
		UE_LOG(LogTwoCoinsFSMSimple, Error, TEXT("FSM is not valid!"));
		return;
	}
	if (!fsm->GetCurrentState())
	{
		UE_LOG(LogTwoCoinsFSMSimple, Error, TEXT("FSM Current State is not valid!"));
		return;
	}

	UE_LOG(LogTwoCoinsFSMSimple, Warning, TEXT("FSM CurrentState: %s"), *fsm->GetCurrentState()->GetStateName().ToString());
	fsm.Get()->TransitionTo(stateNameToTransitTo);
}

bool UTC_SimpleStateManager::InitializeFSM()
{
	fsm = NewObject<UTC_FSMSystem>(this, "SimpleFSM", RF_Transient);
	if (!fsm)
	{
		return false;
	}

	fsm->SetContext(GetOwner());

	UTC_InitState* initState = NewObject<UTC_InitState>();
	initState->SetStateName("Init");
	initState->SetFSM(fsm.Get());
	initState->ToggleAllowedToSelfTransition(true);
	initState->AddTransition("Init");
	initState->AddTransition("Neutral");
	initState->AddTransition("Deinit");
	initState->ToggleAllowedToSelfTransition(true);
	fsm->AddState(initState);

	UTC_NeutralState* neutralState = NewObject<UTC_NeutralState>();
	neutralState->SetStateName("Neutral");
	neutralState->SetFSM(fsm.Get());
	neutralState->AddTransition("Neutral");
	neutralState->AddTransition("Patrol");
	neutralState->AddTransition("Deinit");
	fsm->AddState(neutralState);

	UTC_PatrolState* patrolState = NewObject<UTC_PatrolState>();
	patrolState->SetStateName("Patrol");
	patrolState->SetFSM(fsm.Get());
	patrolState->AddTransition("Neutral");
	patrolState->AddTransition("Deinit");
	fsm->AddState(patrolState);

	UTC_DeinitState* deinitState = NewObject<UTC_DeinitState>();
	deinitState->SetStateName("Deinit");
	deinitState->AddTransition("Init");
	deinitState->SetFSM(fsm.Get());
	fsm->AddState(deinitState);

	return true;
}

void UTC_SimpleStateManager::DeinitializeFSM() const
{
	if (!fsm)
	{
		return;
	}

	if (!fsm->GetStates().Num() == 0)
	{
		return;
	}

	// TODO: verify if there is race condition against another calls 
	// if (fsm->GetCurrentState()->GetStateName() != "Deinit")
	// {
	// 	fsm->TransitionTo("TransitionToDeinit");
	// }

	for (UTC_FSMState* state : fsm->GetStates())
	{
		if (!state->IsValidLowLevel())
		{
			continue;
		}
		state->ConditionalBeginDestroy();
	}
}

void UTC_SimpleStateManager::BindFSM()
{
	if (!fsm)
	{
		return;
	}
	fsm->OnFSMStateTransitionedDelegate.AddUObject(this, &UTC_SimpleStateManager::OnFsmStateTransitioned);
}

void UTC_SimpleStateManager::UnbindFSM() const
{
	if (!fsm)
	{
		return;
	}
	fsm->OnFSMStateTransitionedDelegate.RemoveAll(this);
}

void UTC_SimpleStateManager::OnFsmStateTransitioned(const FName transitionName, const FName oldStateName, const FName newStateName) const
{
	UE_LOG(LogTwoCoinsFSMSimple, Warning, TEXT("FSM Transitioned: %s, [%s] --> [%s] (:: %s) | %hs"),
	       *transitionName.ToString(),
	       *oldStateName.ToString(),
	       *newStateName.ToString(),
	       *GetNameSafe(GetOwner()),
	       __FUNCTION__);
	// TODO: add a trigger example here
}
