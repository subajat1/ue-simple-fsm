// TwoCoins subajat1 Copyright 2026

#pragma once

#include "UObject/Object.h"

#include "TC_FSMSystem.generated.h"

/**
 * 
 */
UCLASS()
class TC_FSM_API UTC_FSMSystem : public UObject
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnFSMStateTransitionedSignature, FName /* TransitionName */, FName /* OldState */, FName /* NewState */)
	FOnFSMStateTransitionedSignature OnFSMStateTransitionedDelegate;

public:
	class UTC_FSMState* GetCurrentState() const;
	void AddState(UTC_FSMState* state);
	void RemoveState(const UTC_FSMState* state);
	void TransitionTo(const FName transitionName);
	void Update(const float deltaSecond) const;

	UTC_FSMState* GetState(const FName stateName);
	TArray<UTC_FSMState*> GetStates() const;
	void SetContext(UObject* context);
	UObject* GetContext() const;

private:
	UPROPERTY()
	TArray<UTC_FSMState*> states;

	UPROPERTY()
	TObjectPtr<UObject> objectContext;

	UPROPERTY()
	TObjectPtr<UTC_FSMState> currentState = nullptr;
};
