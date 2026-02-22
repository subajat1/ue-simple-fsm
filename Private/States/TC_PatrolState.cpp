// TwoCoins subajat1 Copyright 2026

#include "States/TC_PatrolState.h"

#include "TC_FSMLog.h"
#include "TC_FSMSystem.h"

void UTC_PatrolState::OnEnter()
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}

void UTC_PatrolState::Update(float deltaSecond)
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}

void UTC_PatrolState::OnLeave()
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}
