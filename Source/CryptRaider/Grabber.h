// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "Grabber.generated.h"

class UPhysicsHandleComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	UGrabber();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;



private:
	UPROPERTY(EditAnywhere)
	float MaxGrabDistance = 400.0f;

	UPROPERTY(EditAnywhere)
	float GrabRadius = 100.0f;

	UPROPERTY(EditAnywhere)
	float HoldDistance = 200.0f;

	bool GetGrabbableInReach(FHitResult& OutHitResult) const;

public:
	UFUNCTION(BlueprintCallable)
	void Grab();
	
	UFUNCTION(BlueprintCallable)
	void Release();

	UPhysicsHandleComponent* GetPhysicsHandle() const;
};