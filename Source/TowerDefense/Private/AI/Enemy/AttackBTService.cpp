// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/AttackBTService.h"

#include "AI/Enemy/EnemyAIController.h"

UAttackBTService::UAttackBTService(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	bNotifyBecomeRelevant  = true;
}

void UAttackBTService::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyAIController* AIController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

	if (AIController)
	{
		AIController->AttackPlayerPawn();
	}
}
