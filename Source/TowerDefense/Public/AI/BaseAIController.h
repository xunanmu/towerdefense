// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
public:
	ABaseAIController(const FObjectInitializer& ObjectInitializer);

	class UBehaviorTreeComponent* BehaviorTreeComponent;
	class UBlackboardComponent* BlackboardComponent;
};
