// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ParagonTwinblastCharacter.h"

AParagonTwinblastCharacter::AParagonTwinblastCharacter()
{
	ParagonTwinblastSkeletalMesh = CreateDefaultSubobject<USkeletalMesh>(TEXT("ParagonTwinblastSkeletalMesh"));
	// //加载骨骼网格体
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
