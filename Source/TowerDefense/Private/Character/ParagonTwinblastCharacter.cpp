// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ParagonTwinblastCharacter.h"


#include "Blueprint/UserWidget.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"
#include "Weapon/WeaponParticle/Bullet.h"

AParagonTwinblastCharacter::AParagonTwinblastCharacter()
{
	/*开启远程复制*/
	// bReplicates = true;
	//初始化投射物类
	ProjectileClass = ABullet::StaticClass();
	//初始化射速
	FireRate = 0.25f;
	bIsFiringWeapon = false;
	
	//加载骨骼网格体
	ParagonTwinblastSkeletalMesh = LoadObject<USkeletalMesh>(nullptr,
		TEXT("SkeletalMesh'/Game/Resources/Characters/ParagonTwinblast/Characters/Heroes/TwinBlast/Meshes/TwinBlast.TwinBlast'"));
	GetMesh()->SetSkeletalMesh(ParagonTwinblastSkeletalMesh);
	// 指定动画
	static ConstructorHelpers::FClassFinder<UAnimInstance> ParagonTwinblastAnimInstance(
		TEXT("AnimBlueprint'/Game/Resources/Characters/ParagonTwinblast/Characters/Heroes/TwinBlast/Twinblast_AnimBlueprint.Twinblast_AnimBlueprint_C'"));
	if(ParagonTwinblastAnimInstance.Class)
	{
		GetMesh()->SetAnimInstanceClass(ParagonTwinblastAnimInstance.Class);
	}


	// if (StartingWidgetClass != nullptr) 
	// {
	// 	CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), StartingWidgetClass);
	// 	if (CurrentWidget != nullptr)
	// 	{
	// 		CurrentWidget->AddToViewport();
	// 	}
	// }
}


void AParagonTwinblastCharacter::Attack()
{
	/*射击*/
	StartFire();
}

void AParagonTwinblastCharacter::SwitchCharacters()
{
	ParagonTwinblastSkeletalMesh = LoadObject<USkeletalMesh>(nullptr,
		TEXT("SkeletalMesh'/Game/Resources/Characters/ParagonTwinblast/Characters/Heroes/TwinBlast/Skins/Tier2/ShadowOps/Meshes/TwinBlast_ShadowOps.TwinBlast_ShadowOps'"));
	GetMesh()->SetSkeletalMesh(ParagonTwinblastSkeletalMesh);
}

void AParagonTwinblastCharacter::SwitchWeapon()
{
	K2_AttachRootComponentToActor(this,FName("weapon_l"));
}

void AParagonTwinblastCharacter::StartFire()
{
	if (!bIsFiringWeapon)
	{
		bIsFiringWeapon = true;
		UWorld* World = GetWorld();
		World->GetTimerManager().SetTimer(FiringTimer,this,&AParagonTwinblastCharacter::StopFire,FireRate,false);
		HandleFire();
	}
}


void AParagonTwinblastCharacter::PlayAttack_Implementation()
{
	/*攻击蒙太奇动画*/ 
	UAnimMontage* AnimMontage = LoadObject<UAnimMontage>(nullptr,
		TEXT("AnimMontage'/Game/Resources/Characters/ParagonTwinblast/Characters/Heroes/TwinBlast/Animations/DoubleShot_Fire_Lft_Montage.DoubleShot_Fire_Lft_Montage'"));
	PlayAnimMontage(AnimMontage);
	/*攻击声音*/
	USoundWave* SoundWave = LoadObject<USoundWave>(nullptr,
		TEXT("SoundWave'/Game/Resources/Weapons/MilitaryWeapDark/Sound/GrenadeLauncher/Wavs/GrenadeLauncher_Explosion02.GrenadeLauncher_Explosion02'"));
	UGameplayStatics::PlaySoundAtLocation(this,SoundWave,GetActorLocation());
}

void AParagonTwinblastCharacter::StopFire()
{
	bIsFiringWeapon = false;
}

void AParagonTwinblastCharacter::HandleFire_Implementation()
{
	FVector spawnLocation = GetActorLocation() + ( GetControlRotation().Vector()  * 100.0f ) + (GetActorUpVector() * 50.0f);
	FRotator spawnRotation = GetControlRotation();

	FActorSpawnParameters spawnParameters;
	spawnParameters.Instigator = GetInstigator();
	spawnParameters.Owner = this;

	PlayAttack();
	ABullet* spawnedProjectile = GetWorld()->SpawnActor<ABullet>(spawnLocation, spawnRotation, spawnParameters);
	
}
