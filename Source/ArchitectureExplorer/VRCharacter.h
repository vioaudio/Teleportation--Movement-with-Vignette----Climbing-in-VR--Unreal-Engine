// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

UCLASS()
class ARCHITECTUREEXPLORER_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frameKK
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 
	void BeginTeleport();
	void DrawTeleportPath(const TArray<FVector> &Path);
	FVector2D GetBlinkersCenter();
	bool FindTeleportDestination(TArray<FVector> &OutPath, FVector &OutLocation);
	void FinishTeleport();
	void MoveForward(float throttle);
	void MoveRight(float throttle);
	void StartCameraFade(float FromAlpha, float ToAlpha);
	void UpdateBlinkers();
	void UpdateSpline(const TArray<FVector> &Path);
	void UpdateDestinationMarker();


private:
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY()
	TArray<class USplineMeshComponent*> TeleportPathMeshPool;
	UPROPERTY()
	class UMaterialInstanceDynamic* BlinkerMaterialInstance;
	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent* LeftController;
	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent* RightController;
	UPROPERTY()
	class UPostProcessComponent* PostProcessComponent;
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* VRRoot;
	UPROPERTY(VisibleAnywhere)
	class USplineComponent* TeleportPath;
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* DestinationMarker;

private:
	UPROPERTY(EditAnywhere)
	float MaxTeleportDistance = 1000.f;
	UPROPERTY(EditAnywhere)
	float TeleportFadeTime = 1.f;
	UPROPERTY(EditAnywhere)
	float TeleportProjectileRadius = 10.f;
	UPROPERTY(EditAnywhere)
	float TeleportProjectileSpeed = 800;
	UPROPERTY(EditAnywhere)
	float TeleportSimulationTime = 1; //Distance of Parabola
	UPROPERTY(EditAnywhere)
	FVector TeleportProjectionExtent = FVector(100, 100, 100);
	UPROPERTY(EditAnywhere)
	class UCurveFloat* RadiusVsVelocity;
	UPROPERTY(EditAnywhere)
	class UMaterialInterface* BlinkerMaterialBase;
	UPROPERTY(EditDefaultsOnly) //Ensures level doesn't accidentally change it after default is set
	class UMaterialInterface* TeleportArchMaterial;
	UPROPERTY(EditDefaultsOnly)
	class UStaticMesh* TeleportArchMesh;

};
