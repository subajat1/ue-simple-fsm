// TwoCoins subajat1 Copyright 2026

#include "States/TC_InitState.h"

#include "TC_FSMSimpleLog.h"
#include "TC_FSMSystem.h"

void UTC_InitState::OnEnter()
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSMSimple, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}

void UTC_InitState::Update(float deltaSecond)
{
	// nothing to update
}

void UTC_InitState::OnLeave()
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSMSimple, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}
