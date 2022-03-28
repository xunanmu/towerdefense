// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BaseAIController.h"

#include <BehaviorTree/BehaviorTreeComponent.h>
#include <BehaviorTree/BlackboardComponent.h>
#include <BehaviorTree/BehaviorTree.h>

#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Character/ParagonTwinblastCharacter.h"
#include "Kismet/GameplayStatics.h"

//准备开始时候的初始化数据
ABaseAIController::ABaseAIController(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard"));
	EnemyKeyID = 0;
	
}

void ABaseAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AParagonTwinblastCharacter* ParagonTwinblast = Cast<AParagonTwinblastCharacter>(InPawn);
	if(ParagonTwinblast && ParagonTwinblast->BehaviorTree && ParagonTwinblast->BehaviorTree->BlackboardAsset)
	{
		BlackboardComponent->InitializeBlackboard(*ParagonTwinblast->BehaviorTree->BlackboardAsset);
		EnemyKeyID = BlackboardComponent->GetKeyID("Enemy");
		BehaviorTreeComponent->StartTree(*ParagonTwinblast->BehaviorTree);
	}
}

void ABaseAIController::OnUnPossess()
{
	Super::OnUnPossess();
	BehaviorTreeComponent->StopTree();
}

void ABaseAIController::FindEnemy(AParagonTwinblastCharacter* Enemy)
{
	AParagonTwinblastCharacter* ParagonTwinblastCharacter = Cast<AParagonTwinblastCharacter>(GetCharacter());
	if (ParagonTwinblastCharacter )
	{
		AParagonTwinblastCharacter* EnemyParagonTwinblastCharacter = Cast<AParagonTwinblastCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
		if(EnemyParagonTwinblastCharacter)
		{
			if(Enemy)
			{
				if(HasEenmy(Enemy))
				{
					SetEnemy(Enemy);
				}
			}
		}
	}
}


bool ABaseAIController::HasEenmy(AActor* Enemty)
{
	static FName Tag = FName(TEXT("HasEnemy"));
	FCollisionQueryParams Params(Tag,true,GetPawn());
	Params.bReturnPhysicalMaterial = true;

	APawn* Bot = GetPawn();
	FVector Start = Bot->GetActorLocation();
	Start.Z += Bot->BaseEyeHeight;
	const FVector End = Enemty->GetActorLocation();

	FHitResult OutHit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(OutHit,Start,End,ECollisionChannel(0),Params);
	if (OutHit.bBlockingHit)
	{
		AActor* HitActor = OutHit.GetActor();
		if(HitActor)
		{
			if(HitActor == Enemty)
			{
				return true;
			}
		}
	}
}


void ABaseAIController::SetEnemy(APawn* InPawn)
{
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValue<UBlackboardKeyType_Object>(EnemyKeyID,InPawn);
		SetFocus(InPawn);
	}
}

