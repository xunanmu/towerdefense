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

protected:
	class USpringArmComponent* SpringArmComponent;
	class UCameraComponent* CameraComponent;
	class UCapsuleComponent* CapsuleComponent;
private:
	void MoveForWard(float Value);
	void MoveBack(float Value);
	void MoveRight(float Value);
	void MoveLeft(float Value);
public:
	virtual void Attack(){}
	virtual void SwitchCharacters(){}

};
