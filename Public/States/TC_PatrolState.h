// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TC_FSMState.h"

#include "TC_PatrolState.generated.h"

/**
 * 
 */
UCLASS()
class UTC_PatrolState : public UTC_FSMState
{
	GENERATED_BODY()

public:
	virtual void OnEnter() override;
	virtual void Update(float deltaSecond) override;
	virtual void OnLeave() override;
};
