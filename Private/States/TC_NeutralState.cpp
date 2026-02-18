// Fill out your copyright notice in the Description page of Project Settings.


#include "States/TC_NeutralState.h"

#include "TC_FSMLog.h"

void UTC_NeutralState::OnEnter()
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Entered Neutral State"));
}

void UTC_NeutralState::Update(float deltaSecond)
{
}

void UTC_NeutralState::OnLeave()
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Left Neutral State"));
}
