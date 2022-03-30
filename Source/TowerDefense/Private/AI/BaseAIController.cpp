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
}

