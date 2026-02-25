// TwoCoins subajat1 Copyright 2026

#include "States/TC_NeutralState.h"

#include "TC_FSMSimpleLog.h"
#include "TC_FSMSystem.h"

void UTC_NeutralState::OnEnter()
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSMSimple, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}

void UTC_NeutralState::Update(float deltaSecond)
{
	// nothing to update
}

void UTC_NeutralState::OnLeave()
{
	const FString fsmContextStr = FString::Printf(TEXT("Context: %s"), fsmSystem && fsmSystem->GetContext() ? *fsmSystem->GetContext()->GetName() : TEXT("no-context"));
	UE_LOG(LogTwoCoinsFSMSimple, Log, TEXT("%hs | FSM %s"), __FUNCTION__, *fsmContextStr);
}
