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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Projectile")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Projectile")
	UParticleSystemComponent* LaunchParticle;    //烟火，开枪时

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Projectile")
	UProjectileMovementComponent *ProjectileMovementComponent = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Projectile_Fun")
	void LaunchProjectile(FVector Speed);
	
};
