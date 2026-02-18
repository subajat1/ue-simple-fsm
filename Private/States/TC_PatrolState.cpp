// Fill out your copyright notice in the Description page of Project Settings.


#include "States/TC_PatrolState.h"

#include "TC_FSMLog.h"

void UTC_PatrolState::OnEnter()
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Entered Patrol State"));
}

void UTC_PatrolState::Update(float deltaSecond)
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Update Patrol State"));
}

void UTC_PatrolState::OnLeave()
{
	UE_LOG(LogTwoCoinsFSM, Log, TEXT("Left Patrol State"));
}
