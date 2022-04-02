// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Weapon/WeaponParticle/BaseWeaponParticle.h"
#include "Bullet.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ABullet : public ABaseWeaponParticle
{
	GENERATED_BODY()
public:
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Destroyed() override;

	// 用于测试碰撞的球体组件。
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class USphereComponent* SphereComponent;

	// 用于提供对象视觉呈现效果的静态网格体。
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Projectile")
	class UStaticMeshComponent* StaticMeshComponent;
	
	//烟火，开枪时
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Projectile")
	class UParticleSystemComponent* ParticleSystemComponent;    

	// 在投射物撞击其他对象并爆炸时使用的粒子。
	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystem* ExplosionEffect;

	// 用于处理投射物移动的移动组件。
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Projectile")
	class UProjectileMovementComponent *ProjectileMovementComponent = nullptr;

	//此投射物将造成的伤害类型和伤害。
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	TSubclassOf<class UDamageType> DamageType;

	//此投射物造成的伤害。
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage")
	float Damage;

	UFUNCTION(BlueprintCallable, Category = "Projectile_Fun")
	void LaunchProjectile(FVector Speed);
	
};