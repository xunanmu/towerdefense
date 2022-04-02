// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class TOWERDEFENSE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*属性复制*/
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProperties)const override;

	/*承受伤害的事件*/
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	

protected:
	/*武器粒子，如子弹，远程攻击治疗*/
	UPROPERTY(EditDefaultsOnly, Category="Gameplay|Projectile")
	TSubclassOf<class ABaseWeaponParticle> ProjectileClass;
	
	class USpringArmComponent* SpringArmComponent;
	class UCameraComponent* CameraComponent;
	class UCapsuleComponent* CapsuleComponent;
private:
	void MoveForWard(float Value);
	void MoveBack(float Value);
	void MoveRight(float Value);
	void MoveLeft(float Value);
public:
	/*玩家生命值*/
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int MaxHealth;
	/*玩家当前生命值，同步*/
	UPROPERTY(ReplicatedUsing=OnRep_CurrentHealth)
	int CurrentHealth;
	UFUNCTION()
	void OnRep_CurrentHealth();
	void OnHealthUpdate();
	UFUNCTION()
	FORCEINLINE int GetMaxHealth() const {return MaxHealth;}
	UFUNCTION()
	FORCEINLINE int GetCurrentHealth() const {return CurrentHealth;}
	/** 当前生命值的存值函数。将此值的范围限定在0到MaxHealth之间，并调用OnHealthUpdate。仅在服务器上调用。*/
	UFUNCTION()
	void SetCurrentHealth(int healthValue);
	
	
	/*攻击值*/
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int AttackValue;
	/*防御值*/
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int DefenseValue;
	// /*速度值*/
	// UPROPERTY(EditAnywhere,BlueprintReadOnly)
	// int SpeedValue;
	/**/
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UBehaviorTree *BehaviorTree;
	/*攻击函数*/
	virtual void Attack(){}
	/*切换人物*/
	virtual void SwitchCharacters(){}
	/*切换武器*/
	virtual void SwitchWeapon(){}
	
};
