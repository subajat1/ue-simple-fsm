// TwoCoins subajat1 Copyright 2026


#include "TC_FSMState.h"

#include "TC_FSMLog.h"

#define DEFAULT_TRANSITION_PREFIX_STR TEXT("TransitionTo")

void UTC_FSMState::OnEnter()
{
	UE_LOG(LogTwoCoinsFSM, Warning, TEXT("Virtual 'OnEnter' was called, which shouldn't! | %hs"), __FUNCTION__);
}

void UTC_FSMState::Update(float deltaSecond)
{
	UE_LOG(LogTwoCoinsFSM, Warning, TEXT("Virtual 'Update' was called, which shouldn't! | %hs"), __FUNCTION__);
}

void UTC_FSMState::OnLeave()
{
	UE_LOG(LogTwoCoinsFSM, Warning, TEXT("Virtual 'OnLeave' was called, which shouldn't! | %hs"), __FUNCTION__);
}

void UTC_FSMState::SetStateName(const FName inName)
{
	stateName = inName;
}

void UTC_FSMState::AddTransition(const FName transitionName, const FName targetStateName)
{
	if (transitions.Contains(transitionName))
	{
		return;
	}
	transitions.Add(transitionName, targetStateName);
}

void UTC_FSMState::AddTransition(const FName targetStateName)
{
	const FString transitionNameStr = DEFAULT_TRANSITION_PREFIX_STR + targetStateName.ToString();
	if (transitions.Contains(FName(transitionNameStr)))
	{
		return;
	}
	transitions.Add(FName(transitionNameStr), targetStateName);
}

void UTC_FSMState::DeleteTransition(const FName transitionName)
{
	if (!transitions.Contains(transitionName))
	{
		return;
	}
	transitions.Remove(transitionName);
}

void UTC_FSMState::SetFSM(UTC_FSMSystem* fsm)
{
	fsmSystem = fsm;
}

void UTC_FSMState::ToggleAllowedToSelfTransition(const bool bAllowed)
{
	bAllowedToSelfTransition = bAllowed;

	if (!bAllowed) // no more processing if SelfTransition is not allowed
	{
		return;
	}

	const FName* selfKeyName = transitions.FindKey(stateName);
	if (selfKeyName == nullptr)
	{
		AddTransition(stateName);
	}
}

FName UTC_FSMState::GetStateName() const
{
	return stateName;
}

FName UTC_FSMState::GetStateNameFromTransition(const FName transitionName)
{
	if (transitions.IsEmpty())
	{
		return NAME_None;
	}
	if (!transitions.Contains(transitionName))
	{
		return NAME_None;
	}
	return transitions[transitionName];
}

UTC_FSMSystem* UTC_FSMState::GetFSM() const
{
	return this->fsmSystem;
}
