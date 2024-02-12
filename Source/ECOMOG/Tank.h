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
	

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime);

	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:
	void MoveForward(float moveParam);

};
