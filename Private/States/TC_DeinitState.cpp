// TwoCoins subajat1 Copyright 2026

#include "States/TC_DeinitState.h"

#include "TC_FSMLog.h"
#include "TC_FSMSystem.h"

void UTC_DeinitState::OnEnter()
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}

void UTC_DeinitState::Update(float deltaSecond)
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}

void UTC_DeinitState::OnLeave()
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}
