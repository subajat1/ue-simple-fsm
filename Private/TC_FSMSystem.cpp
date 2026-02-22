// TwoCoins subajat1 Copyright 2026


#include "TC_FSMSystem.h"

#include "TC_FSMLog.h"
#include "TC_FSMState.h"


UTC_FSMState* UTC_FSMSystem::GetCurrentState() const
{
	return currentState;
}

void UTC_FSMSystem::AddState(UTC_FSMState* state)
{
	if (!state)
	{
		return;
	}

	if (states.Num() == 0)
	{
		states.Add(state);
		currentState = state;
		return;
	}

	for (const UTC_FSMState* _state : states)
	{
		if (_state->GetName() == state->GetStateName())
		{
			UE_LOG(LogTwoCoinsFSM, Error, TEXT("State to add [%s] exists in this FSM, Context: %s |%hs"), *state->GetStateName().ToString(), objectContext ? *objectContext.GetName() : TEXT("null"), __FUNCTION__);
			return;
		}
	}
	states.Add(state);
}

void UTC_FSMSystem::RemoveState(const UTC_FSMState* state)
{
	for (int i = 0; i < states.Num(); ++i)
	{
		if (states[i]->GetName() == state->GetName())
		{
			states[i]->OnLeave();
			states[i]->ConditionalBeginDestroy();
			states.RemoveAt(i);
			break;
		}
	}
}

void UTC_FSMSystem::TransitionTo(const FName transitionName)
{
	const FName stateNameToTransitTo = currentState->GetStateNameFromTransition(transitionName);
	if (stateNameToTransitTo == NAME_None)
	{
		UE_LOG(LogTwoCoinsFSM, Warning, TEXT("TransitionTo: %s is FAILED |%hs"), *transitionName.ToString(), __FUNCTION__);
		return;
	}

	for (UTC_FSMState* state : states)
	{
		const FName oldStateName = GetCurrentState()->GetStateName();
		if (state->GetStateName() == stateNameToTransitTo)
		{
			currentState->OnLeave();
			// ... TODO: data / object passing

			currentState = state;
			OnFSMStateTransitionedDelegate.Broadcast(transitionName, oldStateName, stateNameToTransitTo);

			currentState->OnEnter();
			break;
		}
	}
}

void UTC_FSMSystem::Update(const float deltaSecond) const
{
	if (!GetCurrentState())
	{
		return;
	}
	GetCurrentState()->Update(deltaSecond);
}

UTC_FSMState* UTC_FSMSystem::GetState(const FName stateName)
{
	for (UTC_FSMState* state : states)
	{
		if (state->GetName() == stateName)
		{
			return state;
		}
	}
	return nullptr;
}

TArray<UTC_FSMState*> UTC_FSMSystem::GetStates() const
{
	return states;
}

void UTC_FSMSystem::SetContext(UObject* context)
{
	objectContext = context;
}

UObject* UTC_FSMSystem::GetContext() const
{
	return objectContext;
}
