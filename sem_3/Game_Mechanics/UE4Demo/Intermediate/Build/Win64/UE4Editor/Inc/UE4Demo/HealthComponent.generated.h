// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UE4DEMO_HealthComponent_generated_h
#error "HealthComponent.generated.h already included, missing '#pragma once' in HealthComponent.h"
#endif
#define UE4DEMO_HealthComponent_generated_h

#define UE4Demo_Source_UE4Demo_HealthComponent_h_48_DELEGATE \
struct HealthComponent_eventOnDamageSignature_Parms \
{ \
	float DamageAmount; \
}; \
static inline void FOnDamageSignature_DelegateWrapper(const FMulticastScriptDelegate& OnDamageSignature, float DamageAmount) \
{ \
	HealthComponent_eventOnDamageSignature_Parms Parms; \
	Parms.DamageAmount=DamageAmount; \
	OnDamageSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UE4Demo_Source_UE4Demo_HealthComponent_h_44_DELEGATE \
static inline void FOnDeathSignature_DelegateWrapper(const FMulticastScriptDelegate& OnDeathSignature) \
{ \
	OnDeathSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_SPARSE_DATA
#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_RPC_WRAPPERS \
	virtual void DoDamage_Implementation(float amount, bool& isDead); \
 \
	DECLARE_FUNCTION(execDoDamage); \
	DECLARE_FUNCTION(execIsDead); \
	DECLARE_FUNCTION(execGetHealthPercentage); \
	DECLARE_FUNCTION(execResetHealth);


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void DoDamage_Implementation(float amount, bool& isDead); \
 \
	DECLARE_FUNCTION(execDoDamage); \
	DECLARE_FUNCTION(execIsDead); \
	DECLARE_FUNCTION(execGetHealthPercentage); \
	DECLARE_FUNCTION(execResetHealth);


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_EVENT_PARMS \
	struct HealthComponent_eventDoDamage_Parms \
	{ \
		float amount; \
		bool isDead; \
	};


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_CALLBACK_WRAPPERS
#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHealthComponent(); \
	friend struct Z_Construct_UClass_UHealthComponent_Statics; \
public: \
	DECLARE_CLASS(UHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UE4Demo"), NO_API) \
	DECLARE_SERIALIZER(UHealthComponent)


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUHealthComponent(); \
	friend struct Z_Construct_UClass_UHealthComponent_Statics; \
public: \
	DECLARE_CLASS(UHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UE4Demo"), NO_API) \
	DECLARE_SERIALIZER(UHealthComponent)


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHealthComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHealthComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHealthComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHealthComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHealthComponent(UHealthComponent&&); \
	NO_API UHealthComponent(const UHealthComponent&); \
public:


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHealthComponent(UHealthComponent&&); \
	NO_API UHealthComponent(const UHealthComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHealthComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHealthComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHealthComponent)


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_PRIVATE_PROPERTY_OFFSET
#define UE4Demo_Source_UE4Demo_HealthComponent_h_10_PROLOG \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_EVENT_PARMS


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_SPARSE_DATA \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_RPC_WRAPPERS \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_CALLBACK_WRAPPERS \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_INCLASS \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UE4Demo_Source_UE4Demo_HealthComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_SPARSE_DATA \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_CALLBACK_WRAPPERS \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_INCLASS_NO_PURE_DECLS \
	UE4Demo_Source_UE4Demo_HealthComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UE4DEMO_API UClass* StaticClass<class UHealthComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UE4Demo_Source_UE4Demo_HealthComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
