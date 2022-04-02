// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponParticle/Bullet.h"

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*开启远程复制*/
	bReplicates = true;

	//定义将作为投射物及其碰撞的根组件的SphereComponent。
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	SphereComponent->InitSphereRadius(37.5f);
	SphereComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	RootComponent = SphereComponent;
	//在击中事件上注册此投射物撞击函数。服务端
	if (GetLocalRole() == ROLE_Authority)
	{
		SphereComponent->OnComponentHit.AddDynamic(this,&ABullet::OnHit);
	}

	//定义将作为视觉呈现的网格体。
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	UStaticMesh* StaticMesh  = LoadObject<UStaticMesh>(nullptr,
		TEXT("StaticMesh'/Game/Resources/Weapon/FPS_Weapon_Bundle/Weapons/Meshes/Ammunition/SM_Shell_762x51.SM_Shell_762x51'"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	StaticMeshComponent->SetStaticMesh(StaticMesh);
	StaticMeshComponent->SetRelativeLocation(FVector(0.f,0.f,-37.5f));
	StaticMeshComponent->SetRelativeScale3D(FVector(0.75f,0.75f,0.75f));
	
	/*设置子弹运动组件*/
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovementComponent->SetUpdatedComponent(SphereComponent);
	ProjectileMovementComponent->InitialSpeed = 1500.0f;
	ProjectileMovementComponent->MaxSpeed = 1500.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;

	DamageType = UDamageType::StaticClass();
	Damage = 10.0f;
    InitialLifeSpan = 5.0f;

	/*粒子效果*/
	static ConstructorHelpers::FObjectFinder<UParticleSystem> DefaultExplosionEffect(TEXT("ParticleSystem'/Game/Resources/Characters/ParagonTwinblast/FX/Particles/Abilities/Dive/FX/P_DiveBooster_Arms.P_DiveBooster_Arms'"));
	if (DefaultExplosionEffect.Succeeded())
	{
		ExplosionEffect = DefaultExplosionEffect.Object;
	}
	
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::Destroyed()
{
	FVector SpawnLocation = GetActorLocation();
	UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, SpawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
}

void ABullet::LaunchProjectile(FVector Speed)
{
	ProjectileMovementComponent->SetVelocityInLocalSpace(Speed);
	ProjectileMovementComponent->Activate();    //可以飞行了
}


//碰撞后发生的事件
void ABullet::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("ABullet::OnHit--OtherActor.Name=%s"),*OtherActor->GetName());    //撞击后给个提示

	if ( OtherActor )
	{
		//受伤害源OtherActor的TakeDamage()会被调用
		UGameplayStatics::ApplyPointDamage(OtherActor, Damage, NormalImpulse, Hit, GetInstigator()->Controller, this, DamageType);
	}

	Destroy();
}