// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FindPlayerBTService.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UFindPlayerBTService : public UBTService
{
	GENERATED_BODY()
public:
	UFindPlayerBTService(const FObjectInitializer& ObjectInitializer);
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
