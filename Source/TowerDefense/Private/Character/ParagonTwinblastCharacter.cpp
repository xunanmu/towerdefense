// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ParagonTwinblastCharacter.h"

AParagonTwinblastCharacter::AParagonTwinblastCharacter()
{
	UE_LOG(LogTemp,Error,TEXT("%s"),*FString());
	//加载骨骼网格体
	USkeletalMesh* ParagonTwinblastSkeletalMesh = LoadObject<USkeletalMesh>(nullptr,
		TEXT("Skeleton'/Game/Resources/Characters/ParagonTwinblast/Characters/Heroes/TwinBlast/Meshes/TwinBlast_Skeleton.TwinBlast_Skeleton'"));
	GetMesh()->SetSkeletalMesh(ParagonTwinblastSkeletalMesh);
	// 指定动画
	static ConstructorHelpers::FClassFinder<UAnimInstance> ParagonTwinblastAnimInstance(
		TEXT("AnimBlueprint'/Game/Resources/Characters/ParagonTwinblast/Characters/Heroes/TwinBlast/Twinblast_AnimBlueprint.Twinblast_AnimBlueprint_C'"));
	if(ParagonTwinblastAnimInstance.Class)
	{
		GetMesh()->SetAnimInstanceClass(ParagonTwinblastAnimInstance.Class);
	}
}
