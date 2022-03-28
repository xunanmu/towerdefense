// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Character/ParagonTwinblastCharacter.h"
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

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	class UBehaviorTreeComponent* BehaviorTreeComponent;
	class UBlackboardComponent* BlackboardComponent;

	int32 EnemyKeyID;

	UFUNCTION(BlueprintCallable,Category="MyAI")
	void FindEnemy(AParagonTwinblastCharacter* Enemy);

	bool HasEenmy(AActor* Enemty);

	void SetEnemy(APawn* InPawn);
};
