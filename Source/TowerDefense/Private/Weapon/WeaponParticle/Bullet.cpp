// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponParticle/Bullet.h"

#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*设置子弹运动组件*/
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));    //生成组件
	ProjectileMovementComponent->InitialSpeed = 3000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	UStaticMesh* StaticMesh  = LoadObject<UStaticMesh>(nullptr,
		TEXT("StaticMesh'/Game/Resources/Weapon/FPS_Weapon_Bundle/Weapons/Meshes/Ammunition/SM_Shell_762x51.SM_Shell_762x51'"));
	ProjectileMesh->SetStaticMesh(StaticMesh);
	RootComponent = ProjectileMesh;
	ProjectileMesh->SetNotifyRigidBodyCollision(true);
	ProjectileMesh->SetVisibility(true);

	
	LaunchParticle = CreateDefaultSubobject<UParticleSystemComponent>(FName("LaunchParticle"));
	UParticleSystem* ParticleSystem =  LoadObject<UParticleSystem>(nullptr,
		TEXT("ParticleSystem'/Game/ParagonTwinblast/FX/Particles/Abilities/Dive/FX/P_DiveBooster_Arms.P_DiveBooster_Arms'"));
	LaunchParticle->SetTemplate(ParticleSystem);
	LaunchParticle->SetupAttachment(ProjectileMesh);    //将粒子效果绑定在根结点上（即ProjectileMesh）
	LaunchParticle->SetAutoActivate(true);                //创建好就启动

	ProjectileMesh->OnComponentHit.AddDynamic(this, &ABullet::OnHit);

	InitialLifeSpan = 5.0f;
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
void ABullet::LaunchProjectile(FVector Speed)
{
	ProjectileMovementComponent->SetVelocityInLocalSpace(Speed);
	ProjectileMovementComponent->Activate();    //可以飞行了
}
//碰撞后发生的事件
void ABullet::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("AProjectile::OnHit--OtherActor.Name=%s"),*OtherActor->GetName());    //撞击后给个提示

	ProjectileMesh->SetNotifyRigidBodyCollision(false);    //碰撞之后再也不发生碰撞事件
	//CollisionMesh->DestroyComponent();    //不是DestroyActor，Component是单一一个

	//受伤害源OtherActor的TakeDamage()会被调用
	UGameplayStatics::ApplyPointDamage(OtherActor, 10.0f, GetActorLocation(), Hit,NULL,NULL, UDamageType::StaticClass());

	Destroy();
}