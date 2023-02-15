// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SocketServerConnection/Public/ConnectionActorUber.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConnectionActorUber() {}
// Cross Module References
	SOCKETSERVERCONNECTION_API UClass* Z_Construct_UClass_AConnectionActorUberStorage_NoRegister();
	SOCKETSERVERCONNECTION_API UClass* Z_Construct_UClass_AConnectionActorUberStorage();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SocketServerConnection();
	SOCKETSERVERCONNECTION_API UClass* Z_Construct_UClass_AConnectionActorUber_NoRegister();
	SOCKETSERVERCONNECTION_API UClass* Z_Construct_UClass_AConnectionActorUber();
// End Cross Module References
	void AConnectionActorUberStorage::StaticRegisterNativesAConnectionActorUberStorage()
	{
	}
	UClass* Z_Construct_UClass_AConnectionActorUberStorage_NoRegister()
	{
		return AConnectionActorUberStorage::StaticClass();
	}
	struct Z_Construct_UClass_AConnectionActorUberStorage_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_timeOfLastInUpdate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_timeOfLastInUpdate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_deltaOfLastInUpdate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_deltaOfLastInUpdate;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_variableInArray_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_variableInArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_variableInArray;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_variableOutArray_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_variableOutArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_variableOutArray;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_infoPrintDisplayPeriod_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_infoPrintDisplayPeriod;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_portNumber_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_portNumber;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_printMessages_MetaData[];
#endif
		static void NewProp_printMessages_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_printMessages;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_doAfterWriting_MetaData[];
#endif
		static void NewProp_doAfterWriting_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_doAfterWriting;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_doBeforeReading_MetaData[];
#endif
		static void NewProp_doBeforeReading_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_doBeforeReading;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AConnectionActorUberStorage_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SocketServerConnection,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ConnectionActorUber.h" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_timeOfLastInUpdate_MetaData[] = {
		{ "Category", "ServerInData" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_timeOfLastInUpdate = { "timeOfLastInUpdate", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AConnectionActorUberStorage, timeOfLastInUpdate), METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_timeOfLastInUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_timeOfLastInUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_deltaOfLastInUpdate_MetaData[] = {
		{ "Category", "ServerInData" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_deltaOfLastInUpdate = { "deltaOfLastInUpdate", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AConnectionActorUberStorage, deltaOfLastInUpdate), METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_deltaOfLastInUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_deltaOfLastInUpdate_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableInArray_Inner = { "variableInArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableInArray_MetaData[] = {
		{ "Category", "ServerInData" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableInArray = { "variableInArray", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AConnectionActorUberStorage, variableInArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableInArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableInArray_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableOutArray_Inner = { "variableOutArray", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableOutArray_MetaData[] = {
		{ "Category", "ServerOutData" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableOutArray = { "variableOutArray", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AConnectionActorUberStorage, variableOutArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableOutArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableOutArray_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_infoPrintDisplayPeriod_MetaData[] = {
		{ "Category", "ServerConfig" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_infoPrintDisplayPeriod = { "infoPrintDisplayPeriod", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AConnectionActorUberStorage, infoPrintDisplayPeriod), METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_infoPrintDisplayPeriod_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_infoPrintDisplayPeriod_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_portNumber_MetaData[] = {
		{ "Category", "ServerConfig" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_portNumber = { "portNumber", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AConnectionActorUberStorage, portNumber), METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_portNumber_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_portNumber_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_printMessages_MetaData[] = {
		{ "Category", "ServerConfig" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	void Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_printMessages_SetBit(void* Obj)
	{
		((AConnectionActorUberStorage*)Obj)->printMessages = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_printMessages = { "printMessages", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AConnectionActorUberStorage), &Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_printMessages_SetBit, METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_printMessages_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_printMessages_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doAfterWriting_MetaData[] = {
		{ "Category", "ServerConfig" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	void Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doAfterWriting_SetBit(void* Obj)
	{
		((AConnectionActorUberStorage*)Obj)->doAfterWriting = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doAfterWriting = { "doAfterWriting", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AConnectionActorUberStorage), &Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doAfterWriting_SetBit, METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doAfterWriting_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doAfterWriting_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doBeforeReading_MetaData[] = {
		{ "Category", "ServerConfig" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	void Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doBeforeReading_SetBit(void* Obj)
	{
		((AConnectionActorUberStorage*)Obj)->doBeforeReading = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doBeforeReading = { "doBeforeReading", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AConnectionActorUberStorage), &Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doBeforeReading_SetBit, METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doBeforeReading_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doBeforeReading_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AConnectionActorUberStorage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_timeOfLastInUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_deltaOfLastInUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableInArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableInArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableOutArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_variableOutArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_infoPrintDisplayPeriod,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_portNumber,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_printMessages,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doAfterWriting,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AConnectionActorUberStorage_Statics::NewProp_doBeforeReading,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AConnectionActorUberStorage_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AConnectionActorUberStorage>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AConnectionActorUberStorage_Statics::ClassParams = {
		&AConnectionActorUberStorage::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AConnectionActorUberStorage_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUberStorage_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUberStorage_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AConnectionActorUberStorage()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AConnectionActorUberStorage_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AConnectionActorUberStorage, 559279547);
	template<> SOCKETSERVERCONNECTION_API UClass* StaticClass<AConnectionActorUberStorage>()
	{
		return AConnectionActorUberStorage::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AConnectionActorUberStorage(Z_Construct_UClass_AConnectionActorUberStorage, &AConnectionActorUberStorage::StaticClass, TEXT("/Script/SocketServerConnection"), TEXT("AConnectionActorUberStorage"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AConnectionActorUberStorage);
	DEFINE_FUNCTION(AConnectionActorUber::execpullOutPhaseSpaceData)
	{
		P_GET_TARRAY(float,Z_Param_VectorIn);
		P_GET_PROPERTY(FIntProperty,Z_Param_StartIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<float>*)Z_Param__Result=AConnectionActorUber::pullOutPhaseSpaceData(Z_Param_VectorIn,Z_Param_StartIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AConnectionActorUber::execgenerateDataVectorForOutput)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_timeStamp);
		P_GET_TARRAY(float,Z_Param_TrackerData);
		P_GET_TARRAY(float,Z_Param_LeapData);
		P_GET_TARRAY(float,Z_Param_PhaseSpaceData);
		P_GET_TARRAY(float,Z_Param_TaskData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<float>*)Z_Param__Result=AConnectionActorUber::generateDataVectorForOutput(Z_Param_timeStamp,Z_Param_TrackerData,Z_Param_LeapData,Z_Param_PhaseSpaceData,Z_Param_TaskData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AConnectionActorUber::execupdateOutDataAfterWriting)
	{
		P_GET_OBJECT(AConnectionActorUberStorage,Z_Param_var);
		P_FINISH;
		P_NATIVE_BEGIN;
		AConnectionActorUber::updateOutDataAfterWriting(Z_Param_var);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AConnectionActorUber::execupdateInDataBeforeReading)
	{
		P_GET_OBJECT(AConnectionActorUberStorage,Z_Param_var);
		P_FINISH;
		P_NATIVE_BEGIN;
		AConnectionActorUber::updateInDataBeforeReading(Z_Param_var);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AConnectionActorUber::execshutDownServer)
	{
		P_GET_OBJECT(AConnectionActorUberStorage,Z_Param_var);
		P_FINISH;
		P_NATIVE_BEGIN;
		AConnectionActorUber::shutDownServer(Z_Param_var);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AConnectionActorUber::execstartServer)
	{
		P_GET_OBJECT(AConnectionActorUberStorage,Z_Param_var);
		P_FINISH;
		P_NATIVE_BEGIN;
		AConnectionActorUber::startServer(Z_Param_var);
		P_NATIVE_END;
	}
	void AConnectionActorUber::StaticRegisterNativesAConnectionActorUber()
	{
		UClass* Class = AConnectionActorUber::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "generateDataVectorForOutput", &AConnectionActorUber::execgenerateDataVectorForOutput },
			{ "pullOutPhaseSpaceData", &AConnectionActorUber::execpullOutPhaseSpaceData },
			{ "shutDownServer", &AConnectionActorUber::execshutDownServer },
			{ "startServer", &AConnectionActorUber::execstartServer },
			{ "updateInDataBeforeReading", &AConnectionActorUber::execupdateInDataBeforeReading },
			{ "updateOutDataAfterWriting", &AConnectionActorUber::execupdateOutDataAfterWriting },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics
	{
		struct ConnectionActorUber_eventgenerateDataVectorForOutput_Parms
		{
			float timeStamp;
			TArray<float> TrackerData;
			TArray<float> LeapData;
			TArray<float> PhaseSpaceData;
			TArray<float> TaskData;
			TArray<float> ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_timeStamp;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TrackerData_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TrackerData;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LeapData_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_LeapData;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PhaseSpaceData_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PhaseSpaceData;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TaskData_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TaskData;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_timeStamp = { "timeStamp", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventgenerateDataVectorForOutput_Parms, timeStamp), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_TrackerData_Inner = { "TrackerData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_TrackerData = { "TrackerData", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventgenerateDataVectorForOutput_Parms, TrackerData), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_LeapData_Inner = { "LeapData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_LeapData = { "LeapData", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventgenerateDataVectorForOutput_Parms, LeapData), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_PhaseSpaceData_Inner = { "PhaseSpaceData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_PhaseSpaceData = { "PhaseSpaceData", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventgenerateDataVectorForOutput_Parms, PhaseSpaceData), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_TaskData_Inner = { "TaskData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_TaskData = { "TaskData", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventgenerateDataVectorForOutput_Parms, TaskData), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventgenerateDataVectorForOutput_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_timeStamp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_TrackerData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_TrackerData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_LeapData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_LeapData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_PhaseSpaceData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_PhaseSpaceData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_TaskData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_TaskData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "TrackerData,LeapData,PhaseSpaceData,TaskData" },
		{ "Category", "MatlabServer" },
		{ "Comment", "// generate data vector\n" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "HidePin", "WorldContextObject" },
		{ "Keywords", "matlab server generate data vector" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
		{ "ToolTip", "generate data vector" },
		{ "UnsafeDuringActorConstruction", "TRUE" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AConnectionActorUber, nullptr, "generateDataVectorForOutput", nullptr, nullptr, sizeof(ConnectionActorUber_eventgenerateDataVectorForOutput_Parms), Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics
	{
		struct ConnectionActorUber_eventpullOutPhaseSpaceData_Parms
		{
			TArray<float> VectorIn;
			int32 StartIndex;
			TArray<float> ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VectorIn_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_VectorIn;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_StartIndex;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_VectorIn_Inner = { "VectorIn", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_VectorIn = { "VectorIn", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventpullOutPhaseSpaceData_Parms, VectorIn), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_StartIndex = { "StartIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventpullOutPhaseSpaceData_Parms, StartIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventpullOutPhaseSpaceData_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_VectorIn_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_VectorIn,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_StartIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "VectorIn" },
		{ "Category", "MatlabServer" },
		{ "Comment", "// generate data vector\n" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "HidePin", "WorldContextObject" },
		{ "Keywords", "matlab server pull out PhaseSpace Data In vector" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
		{ "ToolTip", "generate data vector" },
		{ "UnsafeDuringActorConstruction", "TRUE" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AConnectionActorUber, nullptr, "pullOutPhaseSpaceData", nullptr, nullptr, sizeof(ConnectionActorUber_eventpullOutPhaseSpaceData_Parms), Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics
	{
		struct ConnectionActorUber_eventshutDownServer_Parms
		{
			AConnectionActorUberStorage* var;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_var;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::NewProp_var = { "var", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventshutDownServer_Parms, var), Z_Construct_UClass_AConnectionActorUberStorage_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::NewProp_var,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "MatlabServer" },
		{ "Comment", "// stop dedicated server for connection with matlab\n" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "HidePin", "WorldContextObject" },
		{ "Keywords", "matlab server shutdown" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
		{ "ToolTip", "stop dedicated server for connection with matlab" },
		{ "UnsafeDuringActorConstruction", "TRUE" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AConnectionActorUber, nullptr, "shutDownServer", nullptr, nullptr, sizeof(ConnectionActorUber_eventshutDownServer_Parms), Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AConnectionActorUber_shutDownServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AConnectionActorUber_shutDownServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AConnectionActorUber_startServer_Statics
	{
		struct ConnectionActorUber_eventstartServer_Parms
		{
			AConnectionActorUberStorage* var;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_var;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::NewProp_var = { "var", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventstartServer_Parms, var), Z_Construct_UClass_AConnectionActorUberStorage_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::NewProp_var,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "MatlabServer" },
		{ "Comment", "// start dedicated server for connection with matlab\n" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "HidePin", "WorldContextObject" },
		{ "Keywords", "matlab server start" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
		{ "ToolTip", "start dedicated server for connection with matlab" },
		{ "UnsafeDuringActorConstruction", "TRUE" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AConnectionActorUber, nullptr, "startServer", nullptr, nullptr, sizeof(ConnectionActorUber_eventstartServer_Parms), Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AConnectionActorUber_startServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AConnectionActorUber_startServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics
	{
		struct ConnectionActorUber_eventupdateInDataBeforeReading_Parms
		{
			AConnectionActorUberStorage* var;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_var;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::NewProp_var = { "var", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventupdateInDataBeforeReading_Parms, var), Z_Construct_UClass_AConnectionActorUberStorage_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::NewProp_var,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::Function_MetaDataParams[] = {
		{ "Category", "MatlabServer" },
		{ "Comment", "// read data from matlab\n" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "HidePin", "WorldContextObject" },
		{ "Keywords", "matlab server update in" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
		{ "ToolTip", "read data from matlab" },
		{ "UnsafeDuringActorConstruction", "TRUE" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AConnectionActorUber, nullptr, "updateInDataBeforeReading", nullptr, nullptr, sizeof(ConnectionActorUber_eventupdateInDataBeforeReading_Parms), Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics
	{
		struct ConnectionActorUber_eventupdateOutDataAfterWriting_Parms
		{
			AConnectionActorUberStorage* var;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_var;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::NewProp_var = { "var", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConnectionActorUber_eventupdateOutDataAfterWriting_Parms, var), Z_Construct_UClass_AConnectionActorUberStorage_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::NewProp_var,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::Function_MetaDataParams[] = {
		{ "Category", "MatlabServer" },
		{ "Comment", "// send data to matlab\n" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "HidePin", "WorldContextObject" },
		{ "Keywords", "matlab server update out" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
		{ "ToolTip", "send data to matlab" },
		{ "UnsafeDuringActorConstruction", "TRUE" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AConnectionActorUber, nullptr, "updateOutDataAfterWriting", nullptr, nullptr, sizeof(ConnectionActorUber_eventupdateOutDataAfterWriting_Parms), Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AConnectionActorUber_NoRegister()
	{
		return AConnectionActorUber::StaticClass();
	}
	struct Z_Construct_UClass_AConnectionActorUber_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AConnectionActorUber_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SocketServerConnection,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AConnectionActorUber_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AConnectionActorUber_generateDataVectorForOutput, "generateDataVectorForOutput" }, // 3787423870
		{ &Z_Construct_UFunction_AConnectionActorUber_pullOutPhaseSpaceData, "pullOutPhaseSpaceData" }, // 1633367340
		{ &Z_Construct_UFunction_AConnectionActorUber_shutDownServer, "shutDownServer" }, // 1059619275
		{ &Z_Construct_UFunction_AConnectionActorUber_startServer, "startServer" }, // 3975605032
		{ &Z_Construct_UFunction_AConnectionActorUber_updateInDataBeforeReading, "updateInDataBeforeReading" }, // 3657626216
		{ &Z_Construct_UFunction_AConnectionActorUber_updateOutDataAfterWriting, "updateOutDataAfterWriting" }, // 2269365547
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConnectionActorUber_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ConnectionActorUber.h" },
		{ "ModuleRelativePath", "Public/ConnectionActorUber.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AConnectionActorUber_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AConnectionActorUber>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AConnectionActorUber_Statics::ClassParams = {
		&AConnectionActorUber::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AConnectionActorUber_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AConnectionActorUber_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AConnectionActorUber()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AConnectionActorUber_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AConnectionActorUber, 1710240975);
	template<> SOCKETSERVERCONNECTION_API UClass* StaticClass<AConnectionActorUber>()
	{
		return AConnectionActorUber::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AConnectionActorUber(Z_Construct_UClass_AConnectionActorUber, &AConnectionActorUber::StaticClass, TEXT("/Script/SocketServerConnection"), TEXT("AConnectionActorUber"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AConnectionActorUber);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
