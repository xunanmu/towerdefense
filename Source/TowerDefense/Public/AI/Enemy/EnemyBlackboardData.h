// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardData.h"
#include "EnemyBlackboardData.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UEnemyBlackboardData : public UBlackboardData
{
	GENERATED_BODY()
public:
	virtual void PostLoad() override;
};
