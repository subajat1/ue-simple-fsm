// TwoCoins subajat1 Copyright 2026

#include "TC_FSMComponent.h"

#include "TC_FSMLog.h"
#include "TC_FSMSystem.h"
#include "States/TC_DeinitState.h"
#include "States/TC_InitState.h"
#include "States/TC_NeutralState.h"
#include "States/TC_PatrolState.h"


UTC_FSMComponent::UTC_FSMComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetComponentTickInterval(2.f);
}

void UTC_FSMComponent::BeginPlay()
{
	Super::BeginPlay();

	fsm = NewObject<UTC_FSMSystem>();
	fsm->SetContext(GetOwner());

	fsm->OnFSMStateTransitionedDelegate.AddUObject(this, &UTC_FSMComponent::OnFsmStateTransitioned);

	UTC_InitState* initState = NewObject<UTC_InitState>();
	initState->SetStateName("Init");
	initState->SetFSM(fsm.Get());
	initState->ToggleAllowedToSelfTransition(true);
	initState->AddTransition("Init");
	initState->AddTransition("Neutral");
	initState->AddTransition("Deinit");
	initState->ToggleAllowedToSelfTransition(true);

	UTC_NeutralState* neutralState = NewObject<UTC_NeutralState>();
	neutralState->SetStateName("Neutral");
	neutralState->SetFSM(fsm.Get());
	neutralState->AddTransition("Neutral");
	neutralState->AddTransition("Patrol");
	neutralState->AddTransition("Deinit");

	UTC_PatrolState* patrolState = NewObject<UTC_PatrolState>();
	patrolState->SetStateName("Patrol");
	patrolState->SetFSM(fsm.Get());
	patrolState->AddTransition("Neutral");
	patrolState->AddTransition("Deinit");

	UTC_DeinitState* deinitState = NewObject<UTC_DeinitState>();
	deinitState->SetStateName("Deinit");
	deinitState->AddTransition("Init");
	deinitState->SetFSM(fsm.Get());

	fsm->AddState(initState);
	fsm->AddState(neutralState);
	fsm->AddState(patrolState);
	fsm->AddState(deinitState);
}

void UTC_FSMComponent::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	if (fsm)
	{
		fsm->OnFSMStateTransitionedDelegate.RemoveAll(this);

		for (UTC_FSMState* state : fsm->GetStates())
		{
			if (!state->IsValidLowLevel())
			{
				continue;
			}
			state->ConditionalBeginDestroy();
		}
	}

	Super::EndPlay(endPlayReason);
}

void UTC_FSMComponent::TickComponent(float deltaTime, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaTime, tickType, thisTickFunction);

	if (fsm)
	{
		fsm->Update(deltaTime);
	}
}

void UTC_FSMComponent::OnFsmStateTransitioned(const FName transitionName, const FName oldStateName, const FName newStateName)
{
	UE_LOG(LogTwoCoinsFSM, Warning, TEXT("FSM Transitioned: %s, [%s] --> [%s] (:: %s) | %hs"),
	       *transitionName.ToString(),
	       *oldStateName.ToString(),
	       *newStateName.ToString(),
	       *GetNameSafe(GetOwner()),
	       __FUNCTION__);
	// TODO: add a trigger example here
}

void UTC_FSMComponent::StateTransitionTo(const FName stateNameToTransitTo)
{
	if (!fsm)
	{
		UE_LOG(LogTwoCoinsFSM, Error, TEXT("FSM is not valid!"));
		return;
	}
	if (!fsm->GetCurrentState())
	{
		UE_LOG(LogTwoCoinsFSM, Error, TEXT("FSM Current State is not valid!"));
		return;
	}

	UE_LOG(LogTwoCoinsFSM, Warning, TEXT("FSM CurrentState: %s"), *fsm->GetCurrentState()->GetStateName().ToString());
	fsm.Get()->TransitionTo(stateNameToTransitTo);
}
