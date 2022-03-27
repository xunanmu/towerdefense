// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "ParagonTwinblastCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AParagonTwinblastCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AParagonTwinblastCharacter();
	virtual void Attack() override;
	virtual void SwitchCharacters() override;
	virtual void SwitchWeapon() override;
private:
	class USkeletalMesh* ParagonTwinblastSkeletalMesh;
	
};
