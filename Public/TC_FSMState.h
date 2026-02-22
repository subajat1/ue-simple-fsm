// TwoCoins subajat1 Copyright 2026

#pragma once

#include "UObject/Object.h"

#include "TC_FSMState.generated.h"

/**
 * 
 */
UCLASS()
class UTC_FSMState : public UObject
{
	GENERATED_BODY()

public :
	virtual void OnEnter();
	virtual void Update(float deltaSecond);
	virtual void OnLeave();

	void SetStateName(FName inName);
	void AddTransition(FName transitionName, FName targetStateName);
	void AddTransition(const FName targetStateName);
	void DeleteTransition(FName transitionName);
	void SetFSM(class UTC_FSMSystem* fsm);
	void ToggleAllowedToSelfTransition(const bool bAllowed);

	FName GetStateName() const;
	FName GetStateNameFromTransition(FName transitionName);
	bool IsAllowedToSelfTransition() const { return bAllowedToSelfTransition; }

	UTC_FSMSystem* GetFSM() const;

protected:
	UPROPERTY()
	FName stateName = NAME_None;

	UPROPERTY()
	TObjectPtr<UTC_FSMSystem> fsmSystem = nullptr;

	UPROPERTY()
	TMap<FName, FName> transitions;

	UPROPERTY()
	bool bAllowedToSelfTransition = false;
};
