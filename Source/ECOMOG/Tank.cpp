// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
    PrimaryActorTick.bCanEverTick = true;
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

void ATank::BeginPlay()
{
    Super::BeginPlay();
}

void ATank::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATank::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::MoveForward(float moveParam)
{
    float DeltaTime = GetWorld()->GetDeltaSeconds();
    FVector movement = FVector(DeltaTime * moveParam * MoveSpeed, 0.f, 0.f);
    AddActorLocalOffset(movement, true);
}

void ATank::Turn(float turnParam)
{
    float DeltaTime = GetWorld()->GetDeltaSeconds();

    float turnAmount = DeltaTime * RotateSpeed * turnParam;
    FRotator tankRotation = FRotator(0.f, turnAmount, 0.f);
    AddActorLocalRotation(tankRotation, true);
}