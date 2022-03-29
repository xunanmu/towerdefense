// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/EnemyAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemyAIController::AEnemyAIController()
{
	/*创建行为树组件*/
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	/*创建黑板组件*/
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AParagonTwinblastCharacter* ParagonTwinblast = Cast<AParagonTwinblastCharacter>(InPawn);
	if(ParagonTwinblast && ParagonTwinblast->BehaviorTree && ParagonTwinblast->BehaviorTree->BlackboardAsset)
	{
		BlackboardComponent->InitializeBlackboard(*ParagonTwinblast->BehaviorTree->BlackboardAsset);
		PlayerPawnKey = BlackboardComponent->GetKeyID("PlayerPawn");
		BehaviorTreeComponent->StartTree(*ParagonTwinblast->BehaviorTree);
	}
}

void AEnemyAIController::OnUnPossess()
{
	Super::OnUnPossess();
	BehaviorTreeComponent->StopTree();
}

