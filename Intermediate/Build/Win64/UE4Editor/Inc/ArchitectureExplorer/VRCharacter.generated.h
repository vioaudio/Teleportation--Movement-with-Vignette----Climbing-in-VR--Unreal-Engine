// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARCHITECTUREEXPLORER_VRCharacter_generated_h
#error "VRCharacter.generated.h already included, missing '#pragma once' in VRCharacter.h"
#endif
#define ARCHITECTUREEXPLORER_VRCharacter_generated_h

#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_SPARSE_DATA
#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_RPC_WRAPPERS
#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVRCharacter(); \
	friend struct Z_Construct_UClass_AVRCharacter_Statics; \
public: \
	DECLARE_CLASS(AVRCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArchitectureExplorer"), NO_API) \
	DECLARE_SERIALIZER(AVRCharacter)


#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAVRCharacter(); \
	friend struct Z_Construct_UClass_AVRCharacter_Statics; \
public: \
	DECLARE_CLASS(AVRCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArchitectureExplorer"), NO_API) \
	DECLARE_SERIALIZER(AVRCharacter)


#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVRCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVRCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVRCharacter(AVRCharacter&&); \
	NO_API AVRCharacter(const AVRCharacter&); \
public:


#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVRCharacter(AVRCharacter&&); \
	NO_API AVRCharacter(const AVRCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVRCharacter)


#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AVRCharacter, Camera); } \
	FORCEINLINE static uint32 __PPO__TeleportPathMeshPool() { return STRUCT_OFFSET(AVRCharacter, TeleportPathMeshPool); } \
	FORCEINLINE static uint32 __PPO__BlinkerMaterialInstance() { return STRUCT_OFFSET(AVRCharacter, BlinkerMaterialInstance); } \
	FORCEINLINE static uint32 __PPO__LeftController() { return STRUCT_OFFSET(AVRCharacter, LeftController); } \
	FORCEINLINE static uint32 __PPO__RightController() { return STRUCT_OFFSET(AVRCharacter, RightController); } \
	FORCEINLINE static uint32 __PPO__PostProcessComponent() { return STRUCT_OFFSET(AVRCharacter, PostProcessComponent); } \
	FORCEINLINE static uint32 __PPO__VRRoot() { return STRUCT_OFFSET(AVRCharacter, VRRoot); } \
	FORCEINLINE static uint32 __PPO__TeleportPath() { return STRUCT_OFFSET(AVRCharacter, TeleportPath); } \
	FORCEINLINE static uint32 __PPO__DestinationMarker() { return STRUCT_OFFSET(AVRCharacter, DestinationMarker); } \
	FORCEINLINE static uint32 __PPO__MaxTeleportDistance() { return STRUCT_OFFSET(AVRCharacter, MaxTeleportDistance); } \
	FORCEINLINE static uint32 __PPO__TeleportFadeTime() { return STRUCT_OFFSET(AVRCharacter, TeleportFadeTime); } \
	FORCEINLINE static uint32 __PPO__TeleportProjectileRadius() { return STRUCT_OFFSET(AVRCharacter, TeleportProjectileRadius); } \
	FORCEINLINE static uint32 __PPO__TeleportProjectileSpeed() { return STRUCT_OFFSET(AVRCharacter, TeleportProjectileSpeed); } \
	FORCEINLINE static uint32 __PPO__TeleportSimulationTime() { return STRUCT_OFFSET(AVRCharacter, TeleportSimulationTime); } \
	FORCEINLINE static uint32 __PPO__TeleportProjectionExtent() { return STRUCT_OFFSET(AVRCharacter, TeleportProjectionExtent); } \
	FORCEINLINE static uint32 __PPO__HandControllerClass() { return STRUCT_OFFSET(AVRCharacter, HandControllerClass); } \
	FORCEINLINE static uint32 __PPO__RadiusVsVelocity() { return STRUCT_OFFSET(AVRCharacter, RadiusVsVelocity); } \
	FORCEINLINE static uint32 __PPO__BlinkerMaterialBase() { return STRUCT_OFFSET(AVRCharacter, BlinkerMaterialBase); } \
	FORCEINLINE static uint32 __PPO__TeleportArchMaterial() { return STRUCT_OFFSET(AVRCharacter, TeleportArchMaterial); } \
	FORCEINLINE static uint32 __PPO__TeleportArchMesh() { return STRUCT_OFFSET(AVRCharacter, TeleportArchMesh); }


#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_10_PROLOG
#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_SPARSE_DATA \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_RPC_WRAPPERS \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_INCLASS \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_SPARSE_DATA \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_INCLASS_NO_PURE_DECLS \
	ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARCHITECTUREEXPLORER_API UClass* StaticClass<class AVRCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ArchitectureExplorer_Source_ArchitectureExplorer_VRCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
