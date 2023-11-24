// This Project Made By Yuan Xiaodong.


#include "AbilitySystem/AuraAbilitySystemComponent.h"

/**
 * @brief bind delegate to self
 */
void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle FActiveGameplayEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(-1,8,FColor::Red,FString::Printf(TEXT("Effect Applied")));

	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);

}
