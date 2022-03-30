// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/FindPlayerBTService.h"

#include "AI/Enemy/EnemyAIController.h"

UFindPlayerBTService::UFindPlayerBTService(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	/*等同蓝图里 Receive Activation */
	bNotifyBecomeRelevant = true;
}

void UFindPlayerBTService::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyAIController* AIController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

	if (AIController)
	{
		AIController->FindPlayerPawn();
	}
}
