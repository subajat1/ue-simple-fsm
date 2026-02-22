// TwoCoins subajat1 Copyright 2026

#pragma once

#include "TC_FSMState.h"

#include "TC_DeinitState.generated.h"

/**
 * 
 */
UCLASS()
class UTC_DeinitState : public UTC_FSMState
{
	GENERATED_BODY()

public:
	virtual void OnEnter() override;
	virtual void Update(float deltaSecond) override;
	virtual void OnLeave() override;
	
private:
	UPROPERTY()
	int32 tickCounter = 0;
	
	UPROPERTY()
	int32 tickCounterThreshold = 4;
};
