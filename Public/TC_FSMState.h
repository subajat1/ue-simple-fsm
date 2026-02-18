// Fill out your copyright notice in the Description page of Project Settings.

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
	void DeleteTransition(FName transitionName);
	void SetFSM(class UTC_FSMSystem* fsm);

	FName GetStateName() const;
	FName GetStateNameFromTransition(FName transitionName);

	class UTC_FSMSystem* GetFSM() const;

private :
	UPROPERTY()
	FName stateName = NAME_None;

	UPROPERTY()
	TObjectPtr<UTC_FSMSystem> fsmSystem = nullptr;

	UPROPERTY()
	TMap<FName, FName> transitions;
};
