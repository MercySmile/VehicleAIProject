// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="ThirdPersonTarget")
	static void TargetMove(FVector targetPoint,ACharacter* character,bool& bMoveComplete);
	UFUNCTION(BlueprintPure,Category="Direction")
	static void ReverseMove(float angle,float& dir);
};
