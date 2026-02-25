// TwoCoins subajat1 Copyright 2026

#pragma once

#include "TC_FSMState.h"

#include "TC_NeutralState.generated.h"

/**
 * 
 */
UCLASS()
class UTC_NeutralState : public UTC_FSMState
{
	GENERATED_BODY()

public:
	virtual void OnEnter() override;
	virtual void Update(float deltaSecond) override;
	virtual void OnLeave() override;
};
