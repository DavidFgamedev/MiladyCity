// Copyright Epic Games, Inc. All Rights Reserved.

#include "MiladyCityGameMode.h"
#include "WebService.h"
#include "Engine/GameInstance.h"

AMiladyCityGameMode::AMiladyCityGameMode()
{
}

void AMiladyCityGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Test HTTP service
    UGameInstance* GI = GetGameInstance();
    if (GI)
    {
        UWebService* Web = GI->GetSubsystem<UWebService>();
        if (Web)
        {
            Web->GetJson(
                TEXT("https://httpbin.org/json"),
                FOnWebRequestComplete::CreateLambda([](bool bSuccess, TSharedPtr<FJsonObject> Data)
                {
                    if (bSuccess)
                    {
                        UE_LOG(LogTemp, Warning, TEXT("[MiladyCity] HTTP TEST SUCCESS!"));
                    }
                    else
                    {
                        UE_LOG(LogTemp, Error, TEXT("[MiladyCity] HTTP TEST FAILED"));
                    }
                })
            );
        }
    }
}
