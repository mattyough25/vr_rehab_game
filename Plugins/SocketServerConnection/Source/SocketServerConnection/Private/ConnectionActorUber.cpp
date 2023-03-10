// Fill out your copyright notice in the Description page of Project Settings.
/*
    Written by Anton Sobinov

    Copyright (C) 2018 Anton Sobinov

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
#include "ConnectionActorUber.h"


SaSocketApi* AConnectionActorUber::sasocketapi = new SaSocketApi();
FRunnableThread* AConnectionActorUber::Thread = NULL;
bool AConnectionActorUber::serverRunning = false;
double AConnectionActorUber::preciseTimeOfLastInUpdate = -1.;
double AConnectionActorUber::preciseDeltaOfLastInUpdate = -1.;


//--------------------------------------------- STORAGE
// Sets default values
AConnectionActorUberStorage::AConnectionActorUberStorage()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    timeOfLastInUpdate = -1.f;
    deltaOfLastInUpdate = -1.f;

    variableInArray.Init(-1.f, 1);
    variableInArray.Empty();
    variableOutArray.Init(-1.f, 1);
    variableOutArray.Empty();

    infoPrintDisplayPeriod = 10.f;
    printMessages = false;
    portNumber = 44500;

    doAfterWriting = false;
    doBeforeReading = false;
}


AConnectionActorUberStorage::~AConnectionActorUberStorage()
{
    // shutDownServer();
}

// Called when the game starts or when spawned
void AConnectionActorUberStorage::BeginPlay()
{
    Super::BeginPlay();

    // DBGMSG("Program initiated.\n", 10);
}

// Called every frame
void AConnectionActorUberStorage::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AConnectionActorUberStorage::Destroyed()
{
    // shutDownServer();
}



//--------------------------------------- SERVER
// Sets default values
AConnectionActorUber::AConnectionActorUber()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}


AConnectionActorUber::~AConnectionActorUber()
{
	// shutDownServer();
}

// Called when the game starts or when spawned
void AConnectionActorUber::BeginPlay()
{
	Super::BeginPlay();

	// DBGMSG("Program initiated.\n", 10);
}

// Called every frame
void AConnectionActorUber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConnectionActorUber::Destroyed()
{
    // shutDownServer();
}


void AConnectionActorUber::startServer(AConnectionActorUberStorage* var)
{
    TDBGMSG(var->printMessages, "Starting server.", var->infoPrintDisplayPeriod);
    if (!serverRunning)
    {
        TDBGMSG(var->printMessages, "Starting a new server.", var->infoPrintDisplayPeriod);

        char port[40];
        sprintf_s(port, "%d", var->portNumber);
        sasocketapi->changePort(port);

        Thread = FRunnableThread::Create(
            sasocketapi, TEXT("FSaSocketApi"),
            128*1024, TPri_Normal);

        serverRunning = true;
    }
    else {
        TDBGMSG(var->printMessages, "Server is already running.", var->infoPrintDisplayPeriod);
    }

}


void AConnectionActorUber::shutDownServer(AConnectionActorUberStorage* var)
{
    TDBGMSG(var->printMessages, "Proceeding to server shutdown.", var->infoPrintDisplayPeriod);
    if (serverRunning)
    {
        TDBGMSG(var->printMessages, "Server was running.", var->infoPrintDisplayPeriod);

        // FString msg_buf = FString::Printf(TEXT("sasocketapi currently references %p address."), (void *) sasocketapi);
        // TDBGMSG_NT(var->printMessages, msg_buf, var->infoPrintDisplayPeriod);
        // FString::Printf(msg_buf);
        // UE_LOG(LogTemp, Warning, TEXT(msg_buf));
        // UE_LOG(LogTemp, Warning, TEXT("sasocketapi currently references %p address."), (void *) sasocketapi);


        // stuff
        sasocketapi->Stop();
        // FPlatformProcess::Sleep(0.03);
        // delete sasocketapi;
        // FPlatformProcess::Sleep(0.03);
        // delete Thread;
        // Thread = NULL;

        // sasocketapi = new SaSocketApi();

        serverRunning = false;
    }
    else {
        TDBGMSG(var->printMessages, "Server was NOT running.", var->infoPrintDisplayPeriod);
    }
}

void AConnectionActorUber::updateInDataBeforeReading(AConnectionActorUberStorage* var)
{
    if (serverRunning)
    {
        var->variableInArray.Empty();
        for (int i = 0; i < sasocketapi->NIn[0]; ++i)
        {
            var->variableInArray.Add(sasocketapi->dataIn[i]);
        }

        double currentTime = FPlatformTime::Seconds();
        if (preciseTimeOfLastInUpdate >= 0)
            preciseDeltaOfLastInUpdate = currentTime - preciseTimeOfLastInUpdate;
        preciseTimeOfLastInUpdate = currentTime;

        var->timeOfLastInUpdate = (float) preciseTimeOfLastInUpdate;
        var->deltaOfLastInUpdate = (float) preciseDeltaOfLastInUpdate;

        TDBGMSG(var->printMessages, "Extracted values from Matlab Server.", var->infoPrintDisplayPeriod);
    }
    else {
        TDBGMSG(var->printMessages, "Server is NOT running. Cannot update in data", var->infoPrintDisplayPeriod);
    }
}

void AConnectionActorUber::updateOutDataAfterWriting(AConnectionActorUberStorage* var)
{
    if (serverRunning)
    {
        sasocketapi->NOut[0] = (int) var->variableOutArray.Num();
        for (int i = 0; i < sasocketapi->NOut[0]; ++i)
        {
            (sasocketapi->dataOut)[i] = (float) var->variableOutArray[i];
        }

        TDBGMSG(var->printMessages, "Deposited tems in Matlab Server.", var->infoPrintDisplayPeriod);

        // FString msg = FString::Printf(TEXT("dat1=%f dat2=%f"), var->variableOutArray[0], var->variableOutArray[1]);
        // GEngine->AddOnScreenDebugMessage(-1, var->infoPrintDisplayPeriod, FColor::Red, msg);
        // msg = FString::Printf(TEXT("dat1=%f dat2=%f"), (sasocketapi->dataOut)[0], (sasocketapi->dataOut)[1]);
        // GEngine->AddOnScreenDebugMessage(-1, var->infoPrintDisplayPeriod, FColor::Red, msg);
    }
    else {
        TDBGMSG(var->printMessages, "Server is NOT running. Cannot update out data", var->infoPrintDisplayPeriod);
    }
}

TArray<float> AConnectionActorUber::generateDataVectorForOutput(
	float timeStamp,
	TArray<float> TrackerData,
    TArray<float> LeapData,
    TArray<float> PhaseSpaceData,
    TArray<float> TaskData)
{
	TArray<float> out;
	out.Add(timeStamp);

    // Add the number for each set of arrays
    out.Add(TrackerData.Num());
    out.Add(LeapData.Num());
    out.Add(PhaseSpaceData.Num());
    out.Add(TaskData.Num());

    // TrackerData
    for (int i = 0; i < TrackerData.Num(); ++i)
    {
        out.Add(TrackerData[i]);
    }

    // LeapData
    for (int i = 0; i < LeapData.Num(); ++i)
    {
        out.Add(LeapData[i]);
    }

    // PhaseSpaceData
    for (int i = 0; i < PhaseSpaceData.Num(); ++i)
    {
        out.Add(PhaseSpaceData[i]);
    }

    // TaskData
    for (int i = 0; i < TaskData.Num(); ++i)
    {
        out.Add(TaskData[i]);
    }

	return out;
}

TArray<float> AConnectionActorUber::pullOutPhaseSpaceData(
	TArray<float> VectorIn,
	int StartIndex)
{
	TArray<float> out;

	// TrackerData
	for (int i = 0; i < 48; ++i)
	{
		out.Add(VectorIn[i+ StartIndex]);
	}

	return out;
}
