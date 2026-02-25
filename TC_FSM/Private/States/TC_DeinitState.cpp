// TwoCoins subajat1 Copyright 2026

#include "States/TC_DeinitState.h"

#include "TC_FSMLog.h"
#include "TC_FSMSystem.h"

void UTC_DeinitState::OnEnter()
{
	tickCounter = 0;
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("%hs | FSM %s; tickCounter=%d; tickCounterThreshold=%d"), __FUNCTION__, *fsmContextStr, tickCounter, tickCounterThreshold);
}

void UTC_DeinitState::Update(float deltaSecond)
{
	++tickCounter;
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("%hs | FSM %s; tickCounter/tickCounterThreshold = %d/%d"), __FUNCTION__, *fsmContextStr, tickCounter, tickCounterThreshold);
	if (tickCounter >= tickCounterThreshold)
	{
		GetFSM()->TransitionTo("TransitionToInit");
	}
}

void UTC_DeinitState::OnLeave()
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}
