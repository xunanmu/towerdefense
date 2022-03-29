// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Enemy/EnemyBlackboardData.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"

void UEnemyBlackboardData::PostLoad()
{
	Super::PostLoad();
	/*玩家位置*/
	FBlackboardEntry Position;
	Position.EntryName = FName("Position");
	Position.KeyType = NewObject<UBlackboardKeyType_Vector>();
	/*玩家控制的Pawn*/
	FBlackboardEntry PlayerPawn;
	PlayerPawn.EntryName = FName("PlayerPawn");
	PlayerPawn.KeyType = NewObject<UBlackboardKeyType_Object>();
	/*添加黑板键*/
	Keys.Add(Position);
	Keys.Add(PlayerPawn);
}
