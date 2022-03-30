// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "AttackBTService.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UAttackBTService : public UBTService
{
	GENERATED_BODY()
public:
	UAttackBTService(const FObjectInitializer& ObjectInitializer);
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
};
