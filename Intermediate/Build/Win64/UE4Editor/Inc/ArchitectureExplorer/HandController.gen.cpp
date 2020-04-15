// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArchitectureExplorer/HandController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHandController() {}
// Cross Module References
	ARCHITECTUREEXPLORER_API UClass* Z_Construct_UClass_AHandController_NoRegister();
	ARCHITECTUREEXPLORER_API UClass* Z_Construct_UClass_AHandController();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ArchitectureExplorer();
	ARCHITECTUREEXPLORER_API UFunction* Z_Construct_UFunction_AHandController_ActorBeginOverlap();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ARCHITECTUREEXPLORER_API UFunction* Z_Construct_UFunction_AHandController_ActorEndOverlap();
	ARCHITECTUREEXPLORER_API UFunction* Z_Construct_UFunction_AHandController_HapticFeedback();
	ENGINE_API UClass* Z_Construct_UClass_UHapticFeedbackEffect_Base_NoRegister();
	HEADMOUNTEDDISPLAY_API UClass* Z_Construct_UClass_UMotionControllerComponent_NoRegister();
// End Cross Module References
	void AHandController::StaticRegisterNativesAHandController()
	{
		UClass* Class = AHandController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ActorBeginOverlap", &AHandController::execActorBeginOverlap },
			{ "ActorEndOverlap", &AHandController::execActorEndOverlap },
			{ "HapticFeedback", &AHandController::execHapticFeedback },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics
	{
		struct HandController_eventActorBeginOverlap_Parms
		{
			AActor* OverlappedActor;
			AActor* OtherActor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HandController_eventActorBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::NewProp_OverlappedActor = { "OverlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HandController_eventActorBeginOverlap_Parms, OverlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::NewProp_OverlappedActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Callbacks\n" },
		{ "ModuleRelativePath", "HandController.h" },
		{ "ToolTip", "Callbacks" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHandController, nullptr, "ActorBeginOverlap", nullptr, nullptr, sizeof(HandController_eventActorBeginOverlap_Parms), Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHandController_ActorBeginOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHandController_ActorBeginOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics
	{
		struct HandController_eventActorEndOverlap_Parms
		{
			AActor* OverlappedActor;
			AActor* OtherActor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HandController_eventActorEndOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::NewProp_OverlappedActor = { "OverlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HandController_eventActorEndOverlap_Parms, OverlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::NewProp_OverlappedActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "HandController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHandController, nullptr, "ActorEndOverlap", nullptr, nullptr, sizeof(HandController_eventActorEndOverlap_Parms), Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHandController_ActorEndOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHandController_ActorEndOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHandController_HapticFeedback_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHandController_HapticFeedback_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "HandController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHandController_HapticFeedback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHandController, nullptr, "HapticFeedback", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHandController_HapticFeedback_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHandController_HapticFeedback_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHandController_HapticFeedback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHandController_HapticFeedback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AHandController_NoRegister()
	{
		return AHandController::StaticClass();
	}
	struct Z_Construct_UClass_AHandController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HapticCurve_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HapticCurve;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MotionController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MotionController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHandController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ArchitectureExplorer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AHandController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AHandController_ActorBeginOverlap, "ActorBeginOverlap" }, // 3442524710
		{ &Z_Construct_UFunction_AHandController_ActorEndOverlap, "ActorEndOverlap" }, // 3990618304
		{ &Z_Construct_UFunction_AHandController_HapticFeedback, "HapticFeedback" }, // 1507707293
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHandController_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "HandController.h" },
		{ "ModuleRelativePath", "HandController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHandController_Statics::NewProp_HapticCurve_MetaData[] = {
		{ "Category", "HandController" },
		{ "Comment", "//Parameters\n" },
		{ "ModuleRelativePath", "HandController.h" },
		{ "ToolTip", "Parameters" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHandController_Statics::NewProp_HapticCurve = { "HapticCurve", nullptr, (EPropertyFlags)0x0040000000010001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHandController, HapticCurve), Z_Construct_UClass_UHapticFeedbackEffect_Base_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHandController_Statics::NewProp_HapticCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHandController_Statics::NewProp_HapticCurve_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHandController_Statics::NewProp_MotionController_MetaData[] = {
		{ "Category", "HandController" },
		{ "Comment", "//Default Sub Object\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HandController.h" },
		{ "ToolTip", "Default Sub Object" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHandController_Statics::NewProp_MotionController = { "MotionController", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHandController, MotionController), Z_Construct_UClass_UMotionControllerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHandController_Statics::NewProp_MotionController_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHandController_Statics::NewProp_MotionController_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHandController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHandController_Statics::NewProp_HapticCurve,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHandController_Statics::NewProp_MotionController,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHandController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHandController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHandController_Statics::ClassParams = {
		&AHandController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AHandController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AHandController_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AHandController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHandController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHandController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHandController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHandController, 74849974);
	template<> ARCHITECTUREEXPLORER_API UClass* StaticClass<AHandController>()
	{
		return AHandController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHandController(Z_Construct_UClass_AHandController, &AHandController::StaticClass, TEXT("/Script/ArchitectureExplorer"), TEXT("AHandController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHandController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
