// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_GetPosition.h"

#include "NavigationSystem.h"
#include "AI/BaseAIController.h"
#include "Character/ParagonTwinblastCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"


EBTNodeResult::Type UBTTask_GetPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABaseAIController* AIController = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
	if (AIController)
	{
		APawn* Bot = AIController->GetPawn();
		AParagonTwinblastCharacter* Enemy = AIController->GetEnemy();
		if(Bot && Enemy)
		{
			const FVector Origin = Enemy->GetActorLocation();
			const float Radius = 800.f;
			const UNavigationSystemV1* NavigationSystemV1 =FNavigationSystem::GetCurrent<UNavigationSystemV1>(AIController);
			if (NavigationSystemV1)
			{
				FNavLocation Location;
				NavigationSystemV1->GetRandomReachablePointInRadius(Origin,Radius,Location);
				if (Location.Location != FVector::ZeroVector)
				{
					OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(),Location.Location);
					return  EBTNodeResult::Succeeded;
				}
			}
		}
	}
	return EBTNodeResult::Failed;
}
