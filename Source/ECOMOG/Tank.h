// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTank.h"
#include "Tank.generated.h"

/**
 *
 */
UCLASS()
class ECOMOG_API ATank : public ABaseTank
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime);

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:
	void MoveForward(float moveParam);
	void Turn(float turnParam);

	class APlayerController *PlayerController;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent *SpringArm;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent *Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tanks Values", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tanks Values", meta = (AllowPrivateAccess = "true"))
	float RotateSpeed = 200.0f;
};
