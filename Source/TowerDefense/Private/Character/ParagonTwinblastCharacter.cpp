// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ParagonTwinblastCharacter.h"


#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"

AParagonTwinblastCharacter::AParagonTwinblastCharacter()
{
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
}


void AParagonTwinblastCharacter::Attack()
{
	UE_LOG(LogTemp,Error,TEXT("测试AParagonTwinblastCharacter"));
	/*攻击蒙太奇动画*/
	UAnimMontage* AnimMontage = LoadObject<UAnimMontage>(nullptr,
		TEXT("AnimMontage'/Game/Resources/Characters/ParagonTwinblast/Characters/Heroes/TwinBlast/Animations/DoubleShot_Fire_Lft_Montage.DoubleShot_Fire_Lft_Montage'"));
	PlayAnimMontage(AnimMontage);
	/*攻击声音*/
	USoundWave* SoundWave = LoadObject<USoundWave>(nullptr,
		TEXT("SoundWave'/Game/Resources/Weapons/MilitaryWeapDark/Sound/GrenadeLauncher/Wavs/GrenadeLauncher_Explosion02.GrenadeLauncher_Explosion02'"));
	UGameplayStatics::PlaySoundAtLocation(this,SoundWave,GetActorLocation());
}

void AParagonTwinblastCharacter::SwitchCharacters()
{
	ParagonTwinblastSkeletalMesh = LoadObject<USkeletalMesh>(nullptr,
		TEXT("SkeletalMesh'/Game/Resources/Characters/ParagonTwinblast/Characters/Heroes/TwinBlast/Skins/Tier2/ShadowOps/Meshes/TwinBlast_ShadowOps.TwinBlast_ShadowOps'"));
	GetMesh()->SetSkeletalMesh(ParagonTwinblastSkeletalMesh);
}
