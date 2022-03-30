// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/EnemyAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemyAIController::AEnemyAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
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

/*这个应该可以单独抽出来*/
void AEnemyAIController::FindPlayer()
{
	const ABaseCharacter* AIPawn = Cast<ABaseCharacter>(GetPawn());
	if (AIPawn)
	{
		/*后期多人玩家可以在改进一下算法*/
		const ABaseCharacter* PlayerPawn = Cast<ABaseCharacter>(*(GetWorld()->GetPlayerControllerIterator()));
		if (PlayerPawn)
		{
			if (HasPlayerPawn(PlayerPawn))
			{
				SetPlayerPawn(PlayerPawn);
			}
		}
	}
}

