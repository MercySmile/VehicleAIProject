// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
 void UMyBlueprintFunctionLibrary::TargetMove(FVector targetPoint,ACharacter* character,bool& bMoveComplete )
{
	bool bMove=false;
	FVector worldDir=FVector::ZeroVector;
	float scaleValue=1.f;
 	worldDir=UKismetMathLibrary::Normal(UKismetMathLibrary::Subtract_VectorVector(targetPoint,character->GetActorLocation()),0.0001f );
 	if (UKismetMathLibrary::Vector_Distance(targetPoint,character->GetActorLocation())<=1)
 	{
 		bMove=true;
 	}
 	else
 	{
 		character->AddMovementInput(worldDir,scaleValue);
 	}
 	bMoveComplete=bMove;
}

void UMyBlueprintFunctionLibrary::ReverseMove(float angle,float& dir)
{
	if ((angle>90&&angle<=180)||(angle>=-180&&angle<-90))
	{
		dir=-1;
	}
	else if((angle>=0&&angle<=90)||(angle>=-90&&angle<0))
	{
		dir=1;
	}
}
