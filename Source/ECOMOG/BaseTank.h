// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "BaseTank.generated.h"

UCLASS()
class ECOMOG_API ABaseTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void RotateTurret(FVector LookAt);

	void FireMisile();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "TankComponents", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent *CapsuleComp;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "TankComponents", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *BaseMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "TankComponents", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *TurretMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "TankComponents", meta = (AllowPrivateAccess = "true"))
	class USceneComponent *ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "TankComponents")
	TSubclassOf<class AProjectile> Projectile;
};
