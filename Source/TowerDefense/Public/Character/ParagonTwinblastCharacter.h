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

	/** 射击之间的延迟，单位为秒。用于控制测试发射物的射击速度，还可防止服务器函数的溢出导致将SpawnProjectile直接绑定至输入。*/
	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	float FireRate;

	/** 若为true，则正在发射投射物。*/
	bool bIsFiringWeapon;

	/** 用于启动武器射击的函数。*/
	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void StartFire();

	/** 用于结束武器射击的函数。一旦调用这段代码，玩家可再次使用StartFire。*/
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void StopFire();  

	/** 用于生成投射物的服务器函数。*/
	UFUNCTION(Server, Reliable)
	void HandleFire();

	/** 定时器句柄，用于提供生成间隔时间内的射速延迟。*/
	FTimerHandle FiringTimer;
	
	class USkeletalMesh* ParagonTwinblastSkeletalMesh;
	UUserWidget* Aimat ;
};
