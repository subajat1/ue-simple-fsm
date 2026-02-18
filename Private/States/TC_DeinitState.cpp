// Fill out your copyright notice in the Description page of Project Settings.


#include "States/TC_DeinitState.h"

#include "TC_FSMLog.h"

void UTC_DeinitState::OnEnter()
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Enter Deinit State"));
}

void UTC_DeinitState::Update(float deltaSecond)
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Update Deinit State"));
}

void UTC_DeinitState::OnLeave()
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Leave Deinit State"));
}
