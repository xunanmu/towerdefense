// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/*初始化人物的位置和朝向*/
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	/*初始化人物摄像机手臂组件*/
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPringArmComponent"));
	/*设置摄像机手臂与人物之间的距离*/
	SpringArmComponent->TargetArmLength = 500.0f;
	/*设置根组件*/
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent);

	/*初始摄像机*/
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	/*设置摄像机视野*/
	CameraComponent->FieldOfView = 85.0f;
	/*绑定到摄像机手臂组件*/
	CameraComponent->SetupAttachment(SpringArmComponent);
	/*初始化碰撞体*/
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetCapsuleSize(34.0f,94.0f);
	CapsuleComponent->SetupAttachment(RootComponent);
	//初始速度
	GetCharacterMovement()->MaxWalkSpeed = 700;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

