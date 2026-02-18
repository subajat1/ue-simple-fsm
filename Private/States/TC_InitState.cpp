// Fill out your copyright notice in the Description page of Project Settings.


#include "States/TC_InitState.h"

#include "TC_FSMLog.h"

void UTC_InitState::OnEnter()
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Entered Init State"));
}

void UTC_InitState::Update(float deltaSecond)
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Update Init State"));
}

void UTC_InitState::OnLeave()
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Left Init State"));
}
