// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/EnemyAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

AEnemyAIController::AEnemyAIController(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	// BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	// BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	
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
void AEnemyAIController::FindPlayerPawn()
{
	const ABaseCharacter* AIPawn = Cast<ABaseCharacter>(GetPawn());
	if (AIPawn)
	{
		/*后期多人玩家可以在改进一下算法*/
		ABaseCharacter* PlayerPawn = Cast<ABaseCharacter>(*(GetWorld()->GetPlayerControllerIterator()));
		if (PlayerPawn && HasPlayerPawn(PlayerPawn))
		{
				SetPlayerPawn(PlayerPawn);
		}
	}
}

void AEnemyAIController::AttackPlayerPawn()
{
	ABaseCharacter* AIPawn = Cast<ABaseCharacter>(GetPawn());
	ABaseCharacter* PlayerPawn = GetPlayerPawn();
	if (AIPawn && PlayerPawn)
	{
		/*检查到玩家就攻击*/
		if (LineOfSightTo(PlayerPawn,AIPawn->GetActorLocation()))
		{
			AIPawn->Attack();
		}
	}
}

bool AEnemyAIController::HasPlayerPawn(ABaseCharacter* PlayerPawn)
{
	static FName Tag = FName(TEXT("PlayerPawn"));
	FCollisionQueryParams Params(Tag,true,GetPawn());
	Params.bReturnPhysicalMaterial = true;

	APawn* AIPawn = GetPawn();
	FVector Start = AIPawn->GetActorLocation();
	Start.Z += AIPawn->BaseEyeHeight;
	const FVector End = AIPawn->GetActorLocation();

	/*检查是否看见玩家*/
	FHitResult OutHit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(OutHit,Start,End,ECC_GameTraceChannel4,Params);
	if (OutHit.bBlockingHit)
	{
		AActor* HitActor = OutHit.GetActor();
		if(HitActor)
		{
			if(HitActor == PlayerPawn)
			{
				return true;
			}
		}
	}
	return false;
}

void AEnemyAIController::SetPlayerPawn(ABaseCharacter* PlayerPawn)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValue<UBlackboardKeyType_Object>(PlayerPawnKey,PlayerPawn);
		SetFocus(PlayerPawn);
	}
}

ABaseCharacter* AEnemyAIController::GetPlayerPawn()
{
	if (BlackboardComponent)
	{
		return Cast<ABaseCharacter>(BlackboardComponent->GetValue<UBlackboardKeyType_Object>(EnemyKeyID));
	}
	return nullptr;
}

