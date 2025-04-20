// Fill out your copyright notice in the Description page of Project Settings.
// ReSharper disable CppMemberFunctionMayBeStatic
// ReSharper disable CppParameterMayBeConstPtrOrRef
// ReSharper disable CppMemberFunctionMayBeConst

#include "BaseCamera.h"
#include "BaseMacros.h"
#include "BaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SplineComponent.h"

ABaseCamera::ABaseCamera()
{
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 10.0f;
	GetCameraComponent()->SetupAttachment(SpringArmComponent);

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline Component"));
	SplineComponent->SetupAttachment(RootComponent);

	GetCameraComponent()->OnComponentActivated.AddDynamic(this, &ABaseCamera::OnActivated);
	
}

void ABaseCamera::BeginPlay()
{
	Super::BeginPlay();
	
	PrimaryActorTick.bCanEverTick = true;
	
	PlayerCharacter = Cast<ABaseCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ABaseCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ABaseCamera::OnActivated(UActorComponent* Component, bool bReset)
{
	PRINT(0, "Camera Activated: %s", Green, *GetName());
}




