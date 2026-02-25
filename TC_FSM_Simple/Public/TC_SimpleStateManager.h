// TwoCoins subajat1 Copyright 2026

#pragma once

#include "Components/ActorComponent.h"

#include "TC_SimpleStateManager.generated.h"


UCLASS(ClassGroup=(TC_FSM), meta=(BlueprintSpawnableComponent))
class TC_FSM_SIMPLE_API UTC_SimpleStateManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UTC_SimpleStateManager();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
public:
	UFUNCTION(BlueprintCallable)
	void StateTransitionTo(const FName stateNameToTransitTo);
	
private:
	bool InitializeFSM();
	void DeinitializeFSM() const;
	void BindFSM();
	void UnbindFSM() const;
	
	// handlers
private:
	void OnFsmStateTransitioned(const FName transitionName, const FName oldStateName, const FName newStateName) const;

public:
	class UTC_FSMSystem* GetFSM() const { return fsm; }

private:
	UPROPERTY(Transient)
	TObjectPtr<class UTC_FSMSystem> fsm;
};
