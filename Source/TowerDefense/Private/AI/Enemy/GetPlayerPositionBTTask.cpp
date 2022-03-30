// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/GetPlayerPositionBTTask.h"

#include "NavigationSystem.h"
#include "AI/Enemy/EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Character/BaseCharacter.h"

EBTNodeResult::Type UGetPlayerPositionBTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyAIController* AIController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	
	if (AIController)
	{
		ABaseCharacter* AIPawn = Cast<ABaseCharacter>(AIController->GetPawn());
		ABaseCharacter* PlayerPawn = Cast<ABaseCharacter>(AIController->GetPlayerPawn());
		/*设置导航*/
		if (AIPawn && PlayerPawn)
		{
			const FVector Origin = PlayerPawn->GetActorLocation();
			constexpr  float Radius = 1000.f;
			const UNavigationSystemV1* NavigationSystemV1 = FNavigationSystem::GetCurrent<UNavigationSystemV1>(AIController);
			if (NavigationSystemV1)
			{
				FNavLocation Location;
				NavigationSystemV1->GetRandomReachablePointInRadius(Origin,Radius,Location);
				if (Location.Location != FVector::ZeroVector)
				{
					OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(),Location.Location);
					return EBTNodeResult::Succeeded;
				}
			}
		}
	}

	return EBTNodeResult::Failed;
}
