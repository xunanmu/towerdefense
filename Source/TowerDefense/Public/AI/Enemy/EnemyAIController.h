// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI/BaseAIController.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AEnemyAIController : public ABaseAIController
{
	GENERATED_BODY()
public:
	AEnemyAIController(const FObjectInitializer& ObjectInitializer);
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	/*寻找玩家Pawn，用与*/
	UFUNCTION(BlueprintCallable,Category="MyAI")
	void FindPlayerPawn();
	/*攻击玩家Pawn*/
	UFUNCTION(BlueprintCallable,Category="MyAI")
	void AttackPlayerPawn();
	/*判断是否有玩家Pawn*/
	bool HasPlayerPawn(class ABaseCharacter* PlayerPawn);
	/*设置PlayerPawn绑定在黑板键上*/
	void SetPlayerPawn(class ABaseCharacter* PlayerPawn);
	/*获取黑板键绑定的玩家pawn*/
	ABaseCharacter* GetPlayerPawn();
	
private:
	FBlackboard::FKey PlayerPawnKey = 0;
	FBlackboard::FKey PositionKey = 0;
	
};
