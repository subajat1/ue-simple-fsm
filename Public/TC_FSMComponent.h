// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"

#include "TC_FSMComponent.generated.h"


UCLASS(ClassGroup=(TC_FSM), meta=(BlueprintSpawnableComponent))
class UTC_FSMComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTC_FSMComponent();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;
	virtual void TickComponent(float deltaTime, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;

	// handlers
private:
	void OnFsmStateTransitioned(const FName transitionName, const FName oldStateName, const FName newStateName);

public:
	UFUNCTION(BlueprintCallable)
	void StateTransitionTo(const FName stateNameToTransitTo);

private:
	UPROPERTY(Transient)
	TObjectPtr<class UTC_FSMSystem> fsm;
};
