#ifndef EntityData_H
#define EntityData_H

#pragma once

#include <string>
#include <vector>
#include <charconv>
#include <unordered_map>

#include "toml++/toml.h"

#include "../../files/data/Data.h"
#include "../../files/csv/CSVRow.h"

using namespace file::_csv;
using namespace file::data;

namespace arena::data
{
    class EntityData : public Data
    {
	public:
        EntityData(CSVRow row);
        EntityData(std::string name, toml::table* table, EntityData *entity_data);
        ~EntityData();
        
		const std::string& getName() const {
			return this->Name;
		}
		const std::string& getRarity() const {
			return this->Rarity;
		}
		const std::string& getFlags() const {
			return this->Flags;
		}
		const std::string& getTribe() const {
			return this->Tribe;
		}
		const int& getSightRange() const {
			return this->SightRange;
		}
		const int& getDeployTime() const {
			return this->DeployTime;
		}
		const int& getChargeRange() const {
			return this->ChargeRange;
		}
		const int& getSpeed() const {
			return this->Speed;
		}
		const int& getHitpoints() const {
			return this->Hitpoints;
		}
		const int& getHitSpeed() const {
			return this->HitSpeed;
		}
		const int& getLoadTime() const {
			return this->LoadTime;
		}
		const int& getDamage() const {
			return this->Damage;
		}
		const int& getDamageSpecial() const {
			return this->DamageSpecial;
		}
		const int& getCrownTowerDamagePercent() const {
			return this->CrownTowerDamagePercent;
		}
		const bool& getLoadFirstHit() const {
			return this->LoadFirstHit;
		}
		const bool& getLoadAfterRetarget() const {
			return this->LoadAfterRetarget;
		}
		const int& getStopTimeAfterAttack() const {
			return this->StopTimeAfterAttack;
		}
		const int& getStopTimeAfterSpecialAttack() const {
			return this->StopTimeAfterSpecialAttack;
		}
		const std::string& getProjectile() const {
			return this->Projectile;
		}
		const std::string& getCustomFirstProjectile() const {
			return this->CustomFirstProjectile;
		}
		const int& getMultipleProjectiles() const {
			return this->MultipleProjectiles;
		}
		const int& getMultipleTargets() const {
			return this->MultipleTargets;
		}
		const bool& getAllTargetsHit() const {
			return this->AllTargetsHit;
		}
		const int& getRange() const {
			return this->Range;
		}
		const int& getMinimumRange() const {
			return this->MinimumRange;
		}
		const int& getSpecialMinRange() const {
			return this->SpecialMinRange;
		}
		const int& getSpecialRange() const {
			return this->SpecialRange;
		}
		const int& getSpecialLoadTime() const {
			return this->SpecialLoadTime;
		}
		const int& getSpecialChargeTime() const {
			return this->SpecialChargeTime;
		}
		const std::string& getSpecialReadyEffect() const {
			return this->SpecialReadyEffect;
		}
		const std::string& getSpecialChargingEffect() const {
			return this->SpecialChargingEffect;
		}
		const bool& getSpecialIgnoreBuildings() const {
			return this->SpecialIgnoreBuildings;
		}
		const bool& getSpecialAttacksToIgnoreList() const {
			return this->SpecialAttacksToIgnoreList;
		}
		const bool& getAttacksGround() const {
			return this->AttacksGround;
		}
		const bool& getAttacksAir() const {
			return this->AttacksAir;
		}
		const int& getDeathDamageRadius() const {
			return this->DeathDamageRadius;
		}
		const int& getDeathDamage() const {
			return this->DeathDamage;
		}
		const int& getDeathPushBack() const {
			return this->DeathPushBack;
		}
		const int& getAttackPushBack() const {
			return this->AttackPushBack;
		}
		const std::string& getAttackPushBackEndAction() const {
			return this->AttackPushBackEndAction;
		}
		const int& getMeleePushback() const {
			return this->MeleePushback;
		}
		const bool& getIsMeleePushbackAll() const {
			return this->IsMeleePushbackAll;
		}
		const int& getLifeTime() const {
			return this->LifeTime;
		}
		const std::string& getProjectileSpecial() const {
			return this->ProjectileSpecial;
		}
		const std::string& getProjectileEffect() const {
			return this->ProjectileEffect;
		}
		const std::string& getProjectileEffectSpecial() const {
			return this->ProjectileEffectSpecial;
		}
		const int& getAreaDamageRadius() const {
			return this->AreaDamageRadius;
		}
		const bool& getTargetOnlyBuildings() const {
			return this->TargetOnlyBuildings;
		}
		const bool& getTargetOnlyTroops() const {
			return this->TargetOnlyTroops;
		}
		const bool& getTargetOnlyTowers() const {
			return this->TargetOnlyTowers;
		}
		const bool& getTargetOnlyKingTower() const {
			return this->TargetOnlyKingTower;
		}
		const int& getSpecialAttackInterval() const {
			return this->SpecialAttackInterval;
		}
		const std::string& getBuffOnDamage() const {
			return this->BuffOnDamage;
		}
		const int& getBuffOnDamageTime() const {
			return this->BuffOnDamageTime;
		}
		const std::string& getStartingBuff() const {
			return this->StartingBuff;
		}
		const int& getStartingBuffTime() const {
			return this->StartingBuffTime;
		}
		const std::string& getMesh() const {
			return this->Mesh;
		}
		const std::string& getFileName() const {
			return this->FileName;
		}
		const std::string& getBlueExportName() const {
			return this->BlueExportName;
		}
		const std::string& getBlueTopExportName() const {
			return this->BlueTopExportName;
		}
		const std::string& getRedExportName() const {
			return this->RedExportName;
		}
		const std::string& getRedTopExportName() const {
			return this->RedTopExportName;
		}
		const std::string& getPrestigeSWF() const {
			return this->PrestigeSWF;
		}
		const std::string& getPrestigeExportName() const {
			return this->PrestigeExportName;
		}
		const std::string& getPrestigeExportName2() const {
			return this->PrestigeExportName2;
		}
		const std::string& getPrestigeExportName3() const {
			return this->PrestigeExportName3;
		}
		const std::string& getPrestigeRedExportName() const {
			return this->PrestigeRedExportName;
		}
		const std::string& getPrestigeRedExportName2() const {
			return this->PrestigeRedExportName2;
		}
		const std::string& getPrestigeRedExportName3() const {
			return this->PrestigeRedExportName3;
		}
		const bool& getUseAnimator() const {
			return this->UseAnimator;
		}
		const std::string& getAttachedCharacter() const {
			return this->AttachedCharacter;
		}
		const int& getAttachedCharacterHeight() const {
			return this->AttachedCharacterHeight;
		}
		const std::string& getDamageEffect() const {
			return this->DamageEffect;
		}
		const std::string& getDamageEffectSpecial() const {
			return this->DamageEffectSpecial;
		}
		const std::string& getDeathEffect() const {
			return this->DeathEffect;
		}
		const std::string& getMoveEffect() const {
			return this->MoveEffect;
		}
		const bool& getLoopMoveEffect() const {
			return this->LoopMoveEffect;
		}
		const std::string& getSpawnEffect() const {
			return this->SpawnEffect;
		}
		const bool& getSpawnEffectOnce() const {
			return this->SpawnEffectOnce;
		}
		const bool& getCrowdEffects() const {
			return this->CrowdEffects;
		}
		const int& getShadowScaleX() const {
			return this->ShadowScaleX;
		}
		const int& getShadowScaleY() const {
			return this->ShadowScaleY;
		}
		const int& getShadowX() const {
			return this->ShadowX;
		}
		const int& getShadowY() const {
			return this->ShadowY;
		}
		const int& getShadowSkew() const {
			return this->ShadowSkew;
		}
		const std::string& getShadowCustom() const {
			return this->ShadowCustom;
		}
		const std::string& getShadowCustomLow() const {
			return this->ShadowCustomLow;
		}
		const int& getPushback() const {
			return this->Pushback;
		}
		const bool& getIgnorePushback() const {
			return this->IgnorePushback;
		}
		const int& getScale() const {
			return this->Scale;
		}
		const int& getCollisionRadius() const {
			return this->CollisionRadius;
		}
		const int& getMass() const {
			return this->Mass;
		}
		const int& getTileSizeOverride() const {
			return this->TileSizeOverride;
		}
		const std::string& getHealthBar() const {
			return this->HealthBar;
		}
		const int& getHealthBarOffsetY() const {
			return this->HealthBarOffsetY;
		}
		const bool& getShowHealthNumber() const {
			return this->ShowHealthNumber;
		}
		const int& getFlyingHeight() const {
			return this->FlyingHeight;
		}
		const bool& getFlyDirectPaths() const {
			return this->FlyDirectPaths;
		}
		const bool& getFlyFromGround() const {
			return this->FlyFromGround;
		}
		const bool& getHovering() const {
			return this->Hovering;
		}
		const std::string& getDamageExportName() const {
			return this->DamageExportName;
		}
		const int& getGrowTime() const {
			return this->GrowTime;
		}
		const int& getGrowSize() const {
			return this->GrowSize;
		}
		const std::string& getMorphCharacter() const {
			return this->MorphCharacter;
		}
		const std::string& getMorphEffect() const {
			return this->MorphEffect;
		}
		const bool& getHealOnMorph() const {
			return this->HealOnMorph;
		}
		const std::string& getAreaEffectOnMorph() const {
			return this->AreaEffectOnMorph;
		}
		const int& getMorphTime() const {
			return this->MorphTime;
		}
		const bool& getMorphKeepTarget() const {
			return this->MorphKeepTarget;
		}
		const std::string& getAttackStartEffect() const {
			return this->AttackStartEffect;
		}
		const std::string& getAttackStartEffectSpecial() const {
			return this->AttackStartEffectSpecial;
		}
		const int& getDashImmuneToDamageTime() const {
			return this->DashImmuneToDamageTime;
		}
		const std::string& getDashStartEffect() const {
			return this->DashStartEffect;
		}
		const std::string& getDashEffect() const {
			return this->DashEffect;
		}
		const int& getDashCooldown() const {
			return this->DashCooldown;
		}
		const int& getJumpHeight() const {
			return this->JumpHeight;
		}
		const int& getDashPushBack() const {
			return this->DashPushBack;
		}
		const int& getDashRadius() const {
			return this->DashRadius;
		}
		const int& getDashDamage() const {
			return this->DashDamage;
		}
		const std::string& getDashFilter() const {
			return this->DashFilter;
		}
		const int& getDashConstantTime() const {
			return this->DashConstantTime;
		}
		const int& getDashLandingTime() const {
			return this->DashLandingTime;
		}
		const std::string& getLandingEffect() const {
			return this->LandingEffect;
		}
		const std::string& getDashHitEffect() const {
			return this->DashHitEffect;
		}
		const int& getDashMinRange() const {
			return this->DashMinRange;
		}
		const int& getDashMaxRange() const {
			return this->DashMaxRange;
		}
		const int& getDashDistance() const {
			return this->DashDistance;
		}
		const int& getDashCount() const {
			return this->DashCount;
		}
		const int& getDashSecondaryRange() const {
			return this->DashSecondaryRange;
		}
		const int& getDashingDamage() const {
			return this->DashingDamage;
		}
		const int& getDashingPushback() const {
			return this->DashingPushback;
		}
		const bool& getDashToTargetRadius() const {
			return this->DashToTargetRadius;
		}
		const int& getJumpSpeed() const {
			return this->JumpSpeed;
		}
		const std::string& getContinuousEffect() const {
			return this->ContinuousEffect;
		}
		const int& getSpawnStartTime() const {
			return this->SpawnStartTime;
		}
		const int& getSpawnInterval() const {
			return this->SpawnInterval;
		}
		const int& getSpawnNumber() const {
			return this->SpawnNumber;
		}
		const int& getSpawnLimit() const {
			return this->SpawnLimit;
		}
		const bool& getDestroyAtLimit() const {
			return this->DestroyAtLimit;
		}
		const std::string& getDestroyAtLimitEffect() const {
			return this->DestroyAtLimitEffect;
		}
		const int& getSpawnPauseTime() const {
			return this->SpawnPauseTime;
		}
		const std::string& getSpawnCharacter() const {
			return this->SpawnCharacter;
		}
		const bool& getSpawnCharacterWithDeploy() const {
			return this->SpawnCharacterWithDeploy;
		}
		const int& getSpawnCharacterLevelIndex2() const {
			return this->SpawnCharacterLevelIndex2;
		}
		const std::string& getSpawnCharacter2() const {
			return this->SpawnCharacter2;
		}
		const int& getSpawnCharacterLevelIndex3() const {
			return this->SpawnCharacterLevelIndex3;
		}
		const std::string& getSpawnCharacter3() const {
			return this->SpawnCharacter3;
		}
		const std::string& getSpawnProjectile() const {
			return this->SpawnProjectile;
		}
		const std::string& getSpawnCharacterEffect() const {
			return this->SpawnCharacterEffect;
		}
		const std::string& getSpawnDeployBaseAnim() const {
			return this->SpawnDeployBaseAnim;
		}
		const int& getSpawnRadius() const {
			return this->SpawnRadius;
		}
		const bool& getSpawnAttach() const {
			return this->SpawnAttach;
		}
		const int& getSpawnAttachMaxRotation() const {
			return this->SpawnAttachMaxRotation;
		}
		const std::string& getDeathSpawnDeployBaseAnim() const {
			return this->DeathSpawnDeployBaseAnim;
		}
		const int& getDeathSpawnCount() const {
			return this->DeathSpawnCount;
		}
		const std::string& getDeathSpawnCharacter() const {
			return this->DeathSpawnCharacter;
		}
		const int& getDeathSpawnCount2() const {
			return this->DeathSpawnCount2;
		}
		const std::string& getDeathSpawnCharacter2() const {
			return this->DeathSpawnCharacter2;
		}
		const std::string& getDeathSpawnCharacter3() const {
			return this->DeathSpawnCharacter3;
		}
		const bool& getDeathSpawnIsSameUnit() const {
			return this->DeathSpawnIsSameUnit;
		}
		const bool& getRandomizeDeathSpawn() const {
			return this->RandomizeDeathSpawn;
		}
		const std::string& getDeathSpawnProjectile() const {
			return this->DeathSpawnProjectile;
		}
		const int& getDeathSpawnRadius() const {
			return this->DeathSpawnRadius;
		}
		const int& getDeathSpawnMinRadius() const {
			return this->DeathSpawnMinRadius;
		}
		const bool& getDeathSpawnAllowOverRiver() const {
			return this->DeathSpawnAllowOverRiver;
		}
		const int& getSpawnAngleShift() const {
			return this->SpawnAngleShift;
		}
		const int& getSpawnMaxAngle() const {
			return this->SpawnMaxAngle;
		}
		const int& getDeathSpawnDeployTime() const {
			return this->DeathSpawnDeployTime;
		}
		const bool& getDeathSpawnPushback() const {
			return this->DeathSpawnPushback;
		}
		const std::string& getDeathAreaEffect() const {
			return this->DeathAreaEffect;
		}
		const bool& getDeathInheritIgnoreList() const {
			return this->DeathInheritIgnoreList;
		}
		const bool& getKamikaze() const {
			return this->Kamikaze;
		}
		const int& getKamikazeTime() const {
			return this->KamikazeTime;
		}
		const std::string& getKamikazeEffect() const {
			return this->KamikazeEffect;
		}
		const int& getSpawnPathfindSpeed() const {
			return this->SpawnPathfindSpeed;
		}
		const std::string& getSpawnPathfindEffect() const {
			return this->SpawnPathfindEffect;
		}
		const std::string& getSpawnPathfindMorph() const {
			return this->SpawnPathfindMorph;
		}
		const int& getSpawnPushback() const {
			return this->SpawnPushback;
		}
		const int& getSpawnPushbackRadius() const {
			return this->SpawnPushbackRadius;
		}
		const std::string& getSpawnAreaObject() const {
			return this->SpawnAreaObject;
		}
		const int& getSpawnAreaObjectLevelIndex() const {
			return this->SpawnAreaObjectLevelIndex;
		}
		const int& getIngamePathfindSpeed() const {
			return this->IngamePathfindSpeed;
		}
		const std::string& getIngamePathfindEffect() const {
			return this->IngamePathfindEffect;
		}
		const std::string& getIngamePathfindStartEffect() const {
			return this->IngamePathfindStartEffect;
		}
		const std::string& getIngamePathfindStopEffect() const {
			return this->IngamePathfindStopEffect;
		}
		const std::string& getIngamePathfindStopDeployBaseAnim() const {
			return this->IngamePathfindStopDeployBaseAnim;
		}
		const std::string& getChargeEffect() const {
			return this->ChargeEffect;
		}
		const std::string& getTakeDamageEffect() const {
			return this->TakeDamageEffect;
		}
		const int& getProjectileStartRadius() const {
			return this->ProjectileStartRadius;
		}
		const int& getProjectileStartZ() const {
			return this->ProjectileStartZ;
		}
		const int& getStopMovementAfterMS() const {
			return this->StopMovementAfterMS;
		}
		const int& getWaitMS() const {
			return this->WaitMS;
		}
		const bool& getDontStopMoveAnim() const {
			return this->DontStopMoveAnim;
		}
		const bool& getIsSummonerTower() const {
			return this->IsSummonerTower;
		}
		const int& getNoDeploySizeW() const {
			return this->NoDeploySizeW;
		}
		const int& getNoDeploySizeH() const {
			return this->NoDeploySizeH;
		}
		const std::string& getTID() const {
			return this->TID;
		}
		const int& getAttackSequence() const {
			return this->AttackSequence;
		}
		const std::string& getAttackSeqStateEffect1() const {
			return this->AttackSeqStateEffect1;
		}
		const std::string& getAttackSeqStateEffect2() const {
			return this->AttackSeqStateEffect2;
		}
		const std::string& getAttackSeqStateEffect3() const {
			return this->AttackSeqStateEffect3;
		}
		const int& getVariableDamageTime1() const {
			return this->VariableDamageTime1;
		}
		const int& getVariableDamage2() const {
			return this->VariableDamage2;
		}
		const int& getMeleePushback2() const {
			return this->MeleePushback2;
		}
		const bool& getIsMeleePushbackAll2() const {
			return this->IsMeleePushbackAll2;
		}
		const int& getVariableDamageTime2() const {
			return this->VariableDamageTime2;
		}
		const int& getVariableDamage3() const {
			return this->VariableDamage3;
		}
		const int& getMeleePushback3() const {
			return this->MeleePushback3;
		}
		const bool& getIsMeleePushbackAll3() const {
			return this->IsMeleePushbackAll3;
		}
		const std::string& getTargettedDamageEffect1() const {
			return this->TargettedDamageEffect1;
		}
		const std::string& getTargettedDamageEffect2() const {
			return this->TargettedDamageEffect2;
		}
		const std::string& getTargettedDamageEffect3() const {
			return this->TargettedDamageEffect3;
		}
		const std::string& getDamageLevelTransitionEffect12() const {
			return this->DamageLevelTransitionEffect12;
		}
		const std::string& getDamageLevelTransitionEffect23() const {
			return this->DamageLevelTransitionEffect23;
		}
		const std::string& getFlameEffect1() const {
			return this->FlameEffect1;
		}
		const std::string& getFlameEffect2() const {
			return this->FlameEffect2;
		}
		const std::string& getFlameEffect3() const {
			return this->FlameEffect3;
		}
		const int& getTargetEffectY() const {
			return this->TargetEffectY;
		}
		const bool& getSelfAsAoeCenter() const {
			return this->SelfAsAoeCenter;
		}
		const bool& getHidesWhenNotAttacking() const {
			return this->HidesWhenNotAttacking;
		}
		const int& getHideTimeMs() const {
			return this->HideTimeMs;
		}
		const bool& getHideBeforeFirstHit() const {
			return this->HideBeforeFirstHit;
		}
		const bool& getSpecialAttackWhenHidden() const {
			return this->SpecialAttackWhenHidden;
		}
		const std::string& getTargetedHitEffect() const {
			return this->TargetedHitEffect;
		}
		const std::string& getTargetedHitEffectSpecial() const {
			return this->TargetedHitEffectSpecial;
		}
		const int& getTargetedEffectVisualPushback() const {
			return this->TargetedEffectVisualPushback;
		}
		const int& getUpTimeMs() const {
			return this->UpTimeMs;
		}
		const std::string& getHideEffect() const {
			return this->HideEffect;
		}
		const std::string& getAppearEffect() const {
			return this->AppearEffect;
		}
		const int& getAppearPushbackRadius() const {
			return this->AppearPushbackRadius;
		}
		const int& getAppearPushback() const {
			return this->AppearPushback;
		}
		const std::string& getAppearAreaObject() const {
			return this->AppearAreaObject;
		}
		const int& getManaCollectAmount() const {
			return this->ManaCollectAmount;
		}
		const int& getManaGenerateTimeMs() const {
			return this->ManaGenerateTimeMs;
		}
		const int& getManaGenerateLimit() const {
			return this->ManaGenerateLimit;
		}
		const int& getManaOnDeath() const {
			return this->ManaOnDeath;
		}
		const int& getManaOnDeathForOpponent() const {
			return this->ManaOnDeathForOpponent;
		}
		const bool& getHasRotationOnTimeline() const {
			return this->HasRotationOnTimeline;
		}
		const int& getTurretMovement() const {
			return this->TurretMovement;
		}
		const int& getProjectileYOffset() const {
			return this->ProjectileYOffset;
		}
		const int& getChargeSpeedMultiplier() const {
			return this->ChargeSpeedMultiplier;
		}
		const int& getDeployDelay() const {
			return this->DeployDelay;
		}
		const std::string& getDeployBaseAnimExportName() const {
			return this->DeployBaseAnimExportName;
		}
		const std::string& getDeployAnimationOverride() const {
			return this->DeployAnimationOverride;
		}
		const bool& getJumpEnabled() const {
			return this->JumpEnabled;
		}
		const int& getSightClip() const {
			return this->SightClip;
		}
		const std::string& getAreaEffectOnDash() const {
			return this->AreaEffectOnDash;
		}
		const int& getSightClipSide() const {
			return this->SightClipSide;
		}
		const int& getWalkingSpeedTweakPercentage() const {
			return this->WalkingSpeedTweakPercentage;
		}
		const int& getShieldHitpoints() const {
			return this->ShieldHitpoints;
		}
		const int& getShieldDiePushback() const {
			return this->ShieldDiePushback;
		}
		const std::string& getShieldLostEffect() const {
			return this->ShieldLostEffect;
		}
		const std::string& getShieldLostAction() const {
			return this->ShieldLostAction;
		}
		const std::string& getBlueShieldExportName() const {
			return this->BlueShieldExportName;
		}
		const std::string& getRedShieldExportName() const {
			return this->RedShieldExportName;
		}
		const std::string& getLoadAttackEffect1() const {
			return this->LoadAttackEffect1;
		}
		const std::string& getLoadAttackEffect2() const {
			return this->LoadAttackEffect2;
		}
		const std::string& getLoadAttackEffect3() const {
			return this->LoadAttackEffect3;
		}
		const std::string& getLoadAttackEffectReady() const {
			return this->LoadAttackEffectReady;
		}
		const int& getRotateAngleSpeed() const {
			return this->RotateAngleSpeed;
		}
		const int& getDeployTimerDelay() const {
			return this->DeployTimerDelay;
		}
		const bool& getRetargetEachTick() const {
			return this->RetargetEachTick;
		}
		const bool& getRetargetAfterAttack() const {
			return this->RetargetAfterAttack;
		}
		const int& getAttackShakeTime() const {
			return this->AttackShakeTime;
		}
		const int& getVisualHitSpeed() const {
			return this->VisualHitSpeed;
		}
		const int& getVisualHitSpeed2() const {
			return this->VisualHitSpeed2;
		}
		const int& getVisualHitSpeed3() const {
			return this->VisualHitSpeed3;
		}
		const int& getBurst() const {
			return this->Burst;
		}
		const int& getBurstDelay() const {
			return this->BurstDelay;
		}
		const bool& getBurstKeepTarget() const {
			return this->BurstKeepTarget;
		}
		const bool& getBurstAffectAnimation() const {
			return this->BurstAffectAnimation;
		}
		const int& getActivationTime() const {
			return this->ActivationTime;
		}
		const int& getAttackDashTime() const {
			return this->AttackDashTime;
		}
		const std::string& getLoopingFilter() const {
			return this->LoopingFilter;
		}
		const bool& getBuildingTarget() const {
			return this->BuildingTarget;
		}
		const bool& getSpawnConstPriority() const {
			return this->SpawnConstPriority;
		}
		const std::string& getBuffWhenNotAttacking() const {
			return this->BuffWhenNotAttacking;
		}
		const int& getBuffWhenNotAttackingTime() const {
			return this->BuffWhenNotAttackingTime;
		}
		const std::string& getBuffWhenNotAttackingEffect() const {
			return this->BuffWhenNotAttackingEffect;
		}
		const std::string& getBuffWhenNotAttackingRemoveEffect() const {
			return this->BuffWhenNotAttackingRemoveEffect;
		}
		const std::string& getAreaEffectOnHit() const {
			return this->AreaEffectOnHit;
		}
		const int& getAttackStateDamage() const {
			return this->AttackStateDamage;
		}
		const std::string& getAttackStateEffect() const {
			return this->AttackStateEffect;
		}
		const int& getSpeedBeforeAttack() const {
			return this->SpeedBeforeAttack;
		}
		const std::string& getMoveEffect2() const {
			return this->MoveEffect2;
		}
		const std::string& getReflectedAttackBuff() const {
			return this->ReflectedAttackBuff;
		}
		const int& getReflectedAttackBuffDuration() const {
			return this->ReflectedAttackBuffDuration;
		}
		const int& getReflectedAttackRadius() const {
			return this->ReflectedAttackRadius;
		}
		const int& getReflectedAttackDamage() const {
			return this->ReflectedAttackDamage;
		}
		const int& getReflectAttackCrownTowerDamage() const {
			return this->ReflectAttackCrownTowerDamage;
		}
		const std::string& getReflectedAttackEffect() const {
			return this->ReflectedAttackEffect;
		}
		const std::string& getReflectedAttackTargetedEffect() const {
			return this->ReflectedAttackTargetedEffect;
		}
		const int& getReflectedAttackTargetedEffectSources() const {
			return this->ReflectedAttackTargetedEffectSources;
		}
		const std::string& getIgnoreTargetsWithBuff() const {
			return this->IgnoreTargetsWithBuff;
		}
		const bool& getDeprioritizeTargetsWithBuff() const {
			return this->DeprioritizeTargetsWithBuff;
		}
		const bool& getOverrideAttackFinishTime() const {
			return this->OverrideAttackFinishTime;
		}
		const int& getAttackFinishTime() const {
			return this->AttackFinishTime;
		}
		const std::string& getBuffOnKill() const {
			return this->BuffOnKill;
		}
		const int& getBuffOnKillTime() const {
			return this->BuffOnKillTime;
		}
		const std::string& getBuffOn50HP() const {
			return this->BuffOn50HP;
		}
		const int& getBuffOn50HPTime() const {
			return this->BuffOn50HPTime;
		}
		const std::string& getBuffOnXHP() const {
			return this->BuffOnXHP;
		}
		const int& getBuffOnXHPPercent() const {
			return this->BuffOnXHPPercent;
		}
		const int& getBuffOnXHPTime() const {
			return this->BuffOnXHPTime;
		}
		const int& getSuckElixirSpeed() const {
			return this->SuckElixirSpeed;
		}
		const bool& getCapturableBuilding() const {
			return this->CapturableBuilding;
		}
		const int& getSightRangeForCharacters() const {
			return this->SightRangeForCharacters;
		}
		const int& getAttackStateCount() const {
			return this->AttackStateCount;
		}
		const bool& getNeutralObject() const {
			return this->NeutralObject;
		}
		const int& getBuffAfterHitsCount() const {
			return this->BuffAfterHitsCount;
		}
		const int& getBuffAfterHitsTime() const {
			return this->BuffAfterHitsTime;
		}
		const std::string& getBuffAfterHits() const {
			return this->BuffAfterHits;
		}
		const int& getMorphAfterHitsCount() const {
			return this->MorphAfterHitsCount;
		}
		const std::string& getConvertOnKill() const {
			return this->ConvertOnKill;
		}
		const int& getMoveSpeedByFriendlyMass() const {
			return this->MoveSpeedByFriendlyMass;
		}
		const int& getMoveRadiusByFriendlyMass() const {
			return this->MoveRadiusByFriendlyMass;
		}
		const std::string& getIgnoreBuff() const {
			return this->IgnoreBuff;
		}
		const bool& getTargetLowestHP() const {
			return this->TargetLowestHP;
		}
		const std::string& getAbility() const {
			return this->Ability;
		}
		const std::string& getAbilityPendingEffect() const {
			return this->AbilityPendingEffect;
		}
		const bool& getIgnoreClone() const {
			return this->IgnoreClone;
		}
		const std::string& getCustomSpawnFilter() const {
			return this->CustomSpawnFilter;
		}
		const std::string& getCustomCloneFilter() const {
			return this->CustomCloneFilter;
		}
		const bool& getIgnoreResurrect() const {
			return this->IgnoreResurrect;
		}
		const bool& getAllowAreaDmgWhenInvisible() const {
			return this->AllowAreaDmgWhenInvisible;
		}
		const bool& getAvoidCountingForBuffAmountStats() const {
			return this->AvoidCountingForBuffAmountStats;
		}
		const bool& getUntargetableWhenSpawned() const {
			return this->UntargetableWhenSpawned;
		}
		const std::string& getBoostItems() const {
			return this->BoostItems;
		}
		const std::string& getShaderFXBase() const {
			return this->ShaderFXBase;
		}
		const std::string& getShaderFXTop() const {
			return this->ShaderFXTop;
		}
		const int& getGroupDamageDistributionPerc() const {
			return this->GroupDamageDistributionPerc;
		}
		const int& getGroupMaxSize() const {
			return this->GroupMaxSize;
		}
		const std::string& getOnHitAction() const {
			return this->OnHitAction;
		}
		const std::string& getOnAttackAction() const {
			return this->OnAttackAction;
		}
		const std::string& getClonedVersion() const {
			return this->ClonedVersion;
		}

    private:
		std::string Name;
		std::string Rarity;
		std::string Flags;
		std::string Tribe;
		int SightRange;
		int DeployTime;
		int ChargeRange;
		int Speed;
		int Hitpoints;
		int HitSpeed;
		int LoadTime;
		int Damage;
		int DamageSpecial;
		int CrownTowerDamagePercent;
		bool LoadFirstHit;
		bool LoadAfterRetarget;
		int StopTimeAfterAttack;
		int StopTimeAfterSpecialAttack;
		std::string Projectile;
		std::string CustomFirstProjectile;
		int MultipleProjectiles;
		int MultipleTargets;
		bool AllTargetsHit;
		int Range;
		int MinimumRange;
		int SpecialMinRange;
		int SpecialRange;
		int SpecialLoadTime;
		int SpecialChargeTime;
		std::string SpecialReadyEffect;
		std::string SpecialChargingEffect;
		bool SpecialIgnoreBuildings;
		bool SpecialAttacksToIgnoreList;
		bool AttacksGround;
		bool AttacksAir;
		int DeathDamageRadius;
		int DeathDamage;
		int DeathPushBack;
		int AttackPushBack;
		std::string AttackPushBackEndAction;
		int MeleePushback;
		bool IsMeleePushbackAll;
		int LifeTime;
		std::string ProjectileSpecial;
		std::string ProjectileEffect;
		std::string ProjectileEffectSpecial;
		int AreaDamageRadius;
		bool TargetOnlyBuildings;
		bool TargetOnlyTroops;
		bool TargetOnlyTowers;
		bool TargetOnlyKingTower;
		int SpecialAttackInterval;
		std::string BuffOnDamage;
		int BuffOnDamageTime;
		std::string StartingBuff;
		int StartingBuffTime;
		std::string Mesh;
		std::string FileName;
		std::string BlueExportName;
		std::string BlueTopExportName;
		std::string RedExportName;
		std::string RedTopExportName;
		std::string PrestigeSWF;
		std::string PrestigeExportName;
		std::string PrestigeExportName2;
		std::string PrestigeExportName3;
		std::string PrestigeRedExportName;
		std::string PrestigeRedExportName2;
		std::string PrestigeRedExportName3;
		bool UseAnimator;
		std::string AttachedCharacter;
		int AttachedCharacterHeight;
		std::string DamageEffect;
		std::string DamageEffectSpecial;
		std::string DeathEffect;
		std::string MoveEffect;
		bool LoopMoveEffect;
		std::string SpawnEffect;
		bool SpawnEffectOnce;
		bool CrowdEffects;
		int ShadowScaleX;
		int ShadowScaleY;
		int ShadowX;
		int ShadowY;
		int ShadowSkew;
		std::string ShadowCustom;
		std::string ShadowCustomLow;
		int Pushback;
		bool IgnorePushback;
		int Scale;
		int CollisionRadius;
		int Mass;
		int TileSizeOverride;
		std::string HealthBar;
		int HealthBarOffsetY;
		bool ShowHealthNumber;
		int FlyingHeight;
		bool FlyDirectPaths;
		bool FlyFromGround;
		bool Hovering;
		std::string DamageExportName;
		int GrowTime;
		int GrowSize;
		std::string MorphCharacter;
		std::string MorphEffect;
		bool HealOnMorph;
		std::string AreaEffectOnMorph;
		int MorphTime;
		bool MorphKeepTarget;
		std::string AttackStartEffect;
		std::string AttackStartEffectSpecial;
		int DashImmuneToDamageTime;
		std::string DashStartEffect;
		std::string DashEffect;
		int DashCooldown;
		int JumpHeight;
		int DashPushBack;
		int DashRadius;
		int DashDamage;
		std::string DashFilter;
		int DashConstantTime;
		int DashLandingTime;
		std::string LandingEffect;
		std::string DashHitEffect;
		int DashMinRange;
		int DashMaxRange;
		int DashDistance;
		int DashCount;
		int DashSecondaryRange;
		int DashingDamage;
		int DashingPushback;
		bool DashToTargetRadius;
		int JumpSpeed;
		std::string ContinuousEffect;
		int SpawnStartTime;
		int SpawnInterval;
		int SpawnNumber;
		int SpawnLimit;
		bool DestroyAtLimit;
		std::string DestroyAtLimitEffect;
		int SpawnPauseTime;
		std::string SpawnCharacter;
		bool SpawnCharacterWithDeploy;
		int SpawnCharacterLevelIndex2;
		std::string SpawnCharacter2;
		int SpawnCharacterLevelIndex3;
		std::string SpawnCharacter3;
		std::string SpawnProjectile;
		std::string SpawnCharacterEffect;
		std::string SpawnDeployBaseAnim;
		int SpawnRadius;
		bool SpawnAttach;
		int SpawnAttachMaxRotation;
		std::string DeathSpawnDeployBaseAnim;
		int DeathSpawnCount;
		std::string DeathSpawnCharacter;
		int DeathSpawnCount2;
		std::string DeathSpawnCharacter2;
		std::string DeathSpawnCharacter3;
		bool DeathSpawnIsSameUnit;
		bool RandomizeDeathSpawn;
		std::string DeathSpawnProjectile;
		int DeathSpawnRadius;
		int DeathSpawnMinRadius;
		bool DeathSpawnAllowOverRiver;
		int SpawnAngleShift;
		int SpawnMaxAngle;
		int DeathSpawnDeployTime;
		bool DeathSpawnPushback;
		std::string DeathAreaEffect;
		bool DeathInheritIgnoreList;
		bool Kamikaze;
		int KamikazeTime;
		std::string KamikazeEffect;
		int SpawnPathfindSpeed;
		std::string SpawnPathfindEffect;
		std::string SpawnPathfindMorph;
		int SpawnPushback;
		int SpawnPushbackRadius;
		std::string SpawnAreaObject;
		int SpawnAreaObjectLevelIndex;
		int IngamePathfindSpeed;
		std::string IngamePathfindEffect;
		std::string IngamePathfindStartEffect;
		std::string IngamePathfindStopEffect;
		std::string IngamePathfindStopDeployBaseAnim;
		std::string ChargeEffect;
		std::string TakeDamageEffect;
		int ProjectileStartRadius;
		int ProjectileStartZ;
		int StopMovementAfterMS;
		int WaitMS;
		bool DontStopMoveAnim;
		bool IsSummonerTower;
		int NoDeploySizeW;
		int NoDeploySizeH;
		std::string TID;
		int AttackSequence;
		std::string AttackSeqStateEffect1;
		std::string AttackSeqStateEffect2;
		std::string AttackSeqStateEffect3;
		int VariableDamageTime1;
		int VariableDamage2;
		int MeleePushback2;
		bool IsMeleePushbackAll2;
		int VariableDamageTime2;
		int VariableDamage3;
		int MeleePushback3;
		bool IsMeleePushbackAll3;
		std::string TargettedDamageEffect1;
		std::string TargettedDamageEffect2;
		std::string TargettedDamageEffect3;
		std::string DamageLevelTransitionEffect12;
		std::string DamageLevelTransitionEffect23;
		std::string FlameEffect1;
		std::string FlameEffect2;
		std::string FlameEffect3;
		int TargetEffectY;
		bool SelfAsAoeCenter;
		bool HidesWhenNotAttacking;
		int HideTimeMs;
		bool HideBeforeFirstHit;
		bool SpecialAttackWhenHidden;
		std::string TargetedHitEffect;
		std::string TargetedHitEffectSpecial;
		int TargetedEffectVisualPushback;
		int UpTimeMs;
		std::string HideEffect;
		std::string AppearEffect;
		int AppearPushbackRadius;
		int AppearPushback;
		std::string AppearAreaObject;
		int ManaCollectAmount;
		int ManaGenerateTimeMs;
		int ManaGenerateLimit;
		int ManaOnDeath;
		int ManaOnDeathForOpponent;
		bool HasRotationOnTimeline;
		int TurretMovement;
		int ProjectileYOffset;
		int ChargeSpeedMultiplier;
		int DeployDelay;
		std::string DeployBaseAnimExportName;
		std::string DeployAnimationOverride;
		bool JumpEnabled;
		int SightClip;
		std::string AreaEffectOnDash;
		int SightClipSide;
		int WalkingSpeedTweakPercentage;
		int ShieldHitpoints;
		int ShieldDiePushback;
		std::string ShieldLostEffect;
		std::string ShieldLostAction;
		std::string BlueShieldExportName;
		std::string RedShieldExportName;
		std::string LoadAttackEffect1;
		std::string LoadAttackEffect2;
		std::string LoadAttackEffect3;
		std::string LoadAttackEffectReady;
		int RotateAngleSpeed;
		int DeployTimerDelay;
		bool RetargetEachTick;
		bool RetargetAfterAttack;
		int AttackShakeTime;
		int VisualHitSpeed;
		int VisualHitSpeed2;
		int VisualHitSpeed3;
		int Burst;
		int BurstDelay;
		bool BurstKeepTarget;
		bool BurstAffectAnimation;
		int ActivationTime;
		int AttackDashTime;
		std::string LoopingFilter;
		bool BuildingTarget;
		bool SpawnConstPriority;
		std::string BuffWhenNotAttacking;
		int BuffWhenNotAttackingTime;
		std::string BuffWhenNotAttackingEffect;
		std::string BuffWhenNotAttackingRemoveEffect;
		std::string AreaEffectOnHit;
		int AttackStateDamage;
		std::string AttackStateEffect;
		int SpeedBeforeAttack;
		std::string MoveEffect2;
		std::string ReflectedAttackBuff;
		int ReflectedAttackBuffDuration;
		int ReflectedAttackRadius;
		int ReflectedAttackDamage;
		int ReflectAttackCrownTowerDamage;
		std::string ReflectedAttackEffect;
		std::string ReflectedAttackTargetedEffect;
		int ReflectedAttackTargetedEffectSources;
		std::string IgnoreTargetsWithBuff;
		bool DeprioritizeTargetsWithBuff;
		bool OverrideAttackFinishTime;
		int AttackFinishTime;
		std::string BuffOnKill;
		int BuffOnKillTime;
		std::string BuffOn50HP;
		int BuffOn50HPTime;
		std::string BuffOnXHP;
		int BuffOnXHPPercent;
		int BuffOnXHPTime;
		int SuckElixirSpeed;
		bool CapturableBuilding;
		int SightRangeForCharacters;
		int AttackStateCount;
		bool NeutralObject;
		int BuffAfterHitsCount;
		int BuffAfterHitsTime;
		std::string BuffAfterHits;
		int MorphAfterHitsCount;
		std::string ConvertOnKill;
		int MoveSpeedByFriendlyMass;
		int MoveRadiusByFriendlyMass;
		std::string IgnoreBuff;
		bool TargetLowestHP;
		std::string Ability;
		std::string AbilityPendingEffect;
		bool IgnoreClone;
		std::string CustomSpawnFilter;
		std::string CustomCloneFilter;
		bool IgnoreResurrect;
		bool AllowAreaDmgWhenInvisible;
		bool AvoidCountingForBuffAmountStats;
		bool UntargetableWhenSpawned;
		std::string BoostItems;
		std::string ShaderFXBase;
		std::string ShaderFXTop;
		int GroupDamageDistributionPerc;
		int GroupMaxSize;
		std::string OnHitAction;
		std::string OnAttackAction;
		std::string ClonedVersion;

    };
	typedef std::shared_ptr<EntityData> pEntityData;
}

#endif