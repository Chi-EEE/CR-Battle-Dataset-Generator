#include "EntityData.h"

namespace arena::data {
	EntityData::EntityData(CSVRow row) : Name(row[0]), Rarity(row[1]), Flags(row[2]), Tribe(row[3]), SightRange(to_int(row[4])), DeployTime(to_int(row[5])), ChargeRange(to_int(row[6])), Speed(to_int(row[7])), Hitpoints(to_int(row[8])), HitSpeed(to_int(row[9])), LoadTime(to_int(row[10])), Damage(to_int(row[11])), DamageSpecial(to_int(row[12])), CrownTowerDamagePercent(to_int(row[13])), LoadFirstHit(to_bool(row[14])), LoadAfterRetarget(to_bool(row[15])), StopTimeAfterAttack(to_int(row[16])), StopTimeAfterSpecialAttack(to_int(row[17])), Projectile(row[18]), CustomFirstProjectile(row[19]), MultipleProjectiles(to_int(row[20])), MultipleTargets(to_int(row[21])), AllTargetsHit(to_bool(row[22])), Range(to_int(row[23])), MinimumRange(to_int(row[24])), SpecialMinRange(to_int(row[25])), SpecialRange(to_int(row[26])), SpecialLoadTime(to_int(row[27])), SpecialChargeTime(to_int(row[28])), SpecialReadyEffect(row[29]), SpecialChargingEffect(row[30]), SpecialIgnoreBuildings(to_bool(row[31])), SpecialAttacksToIgnoreList(to_bool(row[32])), AttacksGround(to_bool(row[33])), AttacksAir(to_bool(row[34])), DeathDamageRadius(to_int(row[35])), DeathDamage(to_int(row[36])), DeathPushBack(to_int(row[37])), AttackPushBack(to_int(row[38])), AttackPushBackEndAction(row[39]), MeleePushback(to_int(row[40])), IsMeleePushbackAll(to_bool(row[41])), LifeTime(to_int(row[42])), ProjectileSpecial(row[43]), ProjectileEffect(row[44]), ProjectileEffectSpecial(row[45]), AreaDamageRadius(to_int(row[46])), TargetOnlyBuildings(to_bool(row[47])), TargetOnlyTroops(to_bool(row[48])), TargetOnlyTowers(to_bool(row[49])), TargetOnlyKingTower(to_bool(row[50])), SpecialAttackInterval(to_int(row[51])), BuffOnDamage(row[52]), BuffOnDamageTime(to_int(row[53])), StartingBuff(row[54]), StartingBuffTime(to_int(row[55])), Mesh(row[56]), FileName(row[57]), BlueExportName(row[58]), BlueTopExportName(row[59]), RedExportName(row[60]), RedTopExportName(row[61]), PrestigeSWF(row[62]), PrestigeExportName(row[63]), PrestigeExportName2(row[64]), PrestigeExportName3(row[65]), PrestigeRedExportName(row[66]), PrestigeRedExportName2(row[67]), PrestigeRedExportName3(row[68]), UseAnimator(to_bool(row[69])), AttachedCharacter(row[70]), AttachedCharacterHeight(to_int(row[71])), DamageEffect(row[72]), DamageEffectSpecial(row[73]), DeathEffect(row[74]), MoveEffect(row[75]), LoopMoveEffect(to_bool(row[76])), SpawnEffect(row[77]), SpawnEffectOnce(to_bool(row[78])), CrowdEffects(to_bool(row[79])), ShadowScaleX(to_int(row[80])), ShadowScaleY(to_int(row[81])), ShadowX(to_int(row[82])), ShadowY(to_int(row[83])), ShadowSkew(to_int(row[84])), ShadowCustom(row[85]), ShadowCustomLow(row[86]), Pushback(to_int(row[87])), IgnorePushback(to_bool(row[88])), Scale(to_int(row[89])), CollisionRadius(to_int(row[90])), Mass(to_int(row[91])), TileSizeOverride(to_int(row[92])), HealthBar(row[93]), HealthBarOffsetY(to_int(row[94])), ShowHealthNumber(to_bool(row[95])), FlyingHeight(to_int(row[96])), FlyDirectPaths(to_bool(row[97])), FlyFromGround(to_bool(row[98])), Hovering(to_bool(row[99])), DamageExportName(row[100]), GrowTime(to_int(row[101])), GrowSize(to_int(row[102])), MorphCharacter(row[103]), MorphEffect(row[104]), HealOnMorph(to_bool(row[105])), AreaEffectOnMorph(row[106]), MorphTime(to_int(row[107])), MorphKeepTarget(to_bool(row[108])), AttackStartEffect(row[109]), AttackStartEffectSpecial(row[110]), DashImmuneToDamageTime(to_int(row[111])), DashStartEffect(row[112]), DashEffect(row[113]), DashCooldown(to_int(row[114])), JumpHeight(to_int(row[115])), DashPushBack(to_int(row[116])), DashRadius(to_int(row[117])), DashDamage(to_int(row[118])), DashFilter(row[119]), DashConstantTime(to_int(row[120])), DashLandingTime(to_int(row[121])), LandingEffect(row[122]), DashHitEffect(row[123]), DashMinRange(to_int(row[124])), DashMaxRange(to_int(row[125])), DashDistance(to_int(row[126])), DashCount(to_int(row[127])), DashSecondaryRange(to_int(row[128])), DashingDamage(to_int(row[129])), DashingPushback(to_int(row[130])), DashToTargetRadius(to_bool(row[131])), JumpSpeed(to_int(row[132])), ContinuousEffect(row[133]), SpawnStartTime(to_int(row[134])), SpawnInterval(to_int(row[135])), SpawnNumber(to_int(row[136])), SpawnLimit(to_int(row[137])), DestroyAtLimit(to_bool(row[138])), DestroyAtLimitEffect(row[139]), SpawnPauseTime(to_int(row[140])), SpawnCharacter(row[141]), SpawnCharacterWithDeploy(to_bool(row[142])), SpawnCharacterLevelIndex2(to_int(row[143])), SpawnCharacter2(row[144]), SpawnCharacterLevelIndex3(to_int(row[145])), SpawnCharacter3(row[146]), SpawnProjectile(row[147]), SpawnCharacterEffect(row[148]), SpawnDeployBaseAnim(row[149]), SpawnRadius(to_int(row[150])), SpawnAttach(to_bool(row[151])), SpawnAttachMaxRotation(to_int(row[152])), DeathSpawnDeployBaseAnim(row[153]), DeathSpawnCount(to_int(row[154])), DeathSpawnCharacter(row[155]), DeathSpawnCount2(to_int(row[156])), DeathSpawnCharacter2(row[157]), DeathSpawnCharacter3(row[158]), DeathSpawnIsSameUnit(to_bool(row[159])), RandomizeDeathSpawn(to_bool(row[160])), DeathSpawnProjectile(row[161]), DeathSpawnRadius(to_int(row[162])), DeathSpawnMinRadius(to_int(row[163])), DeathSpawnAllowOverRiver(to_bool(row[164])), SpawnAngleShift(to_int(row[165])), SpawnMaxAngle(to_int(row[166])), DeathSpawnDeployTime(to_int(row[167])), DeathSpawnPushback(to_bool(row[168])), DeathAreaEffect(row[169]), DeathInheritIgnoreList(to_bool(row[170])), Kamikaze(to_bool(row[171])), KamikazeTime(to_int(row[172])), KamikazeEffect(row[173]), SpawnPathfindSpeed(to_int(row[174])), SpawnPathfindEffect(row[175]), SpawnPathfindMorph(row[176]), SpawnPushback(to_int(row[177])), SpawnPushbackRadius(to_int(row[178])), SpawnAreaObject(row[179]), SpawnAreaObjectLevelIndex(to_int(row[180])), IngamePathfindSpeed(to_int(row[181])), IngamePathfindEffect(row[182]), IngamePathfindStartEffect(row[183]), IngamePathfindStopEffect(row[184]), IngamePathfindStopDeployBaseAnim(row[185]), ChargeEffect(row[186]), TakeDamageEffect(row[187]), ProjectileStartRadius(to_int(row[188])), ProjectileStartZ(to_int(row[189])), StopMovementAfterMS(to_int(row[190])), WaitMS(to_int(row[191])), DontStopMoveAnim(to_bool(row[192])), IsSummonerTower(to_bool(row[193])), NoDeploySizeW(to_int(row[194])), NoDeploySizeH(to_int(row[195])), TID(row[196]), AttackSequence(to_int(row[197])), AttackSeqStateEffect1(row[198]), AttackSeqStateEffect2(row[199]), AttackSeqStateEffect3(row[200]), VariableDamageTime1(to_int(row[201])), VariableDamage2(to_int(row[202])), MeleePushback2(to_int(row[203])), IsMeleePushbackAll2(to_bool(row[204])), VariableDamageTime2(to_int(row[205])), VariableDamage3(to_int(row[206])), MeleePushback3(to_int(row[207])), IsMeleePushbackAll3(to_bool(row[208])), TargettedDamageEffect1(row[209]), TargettedDamageEffect2(row[210]), TargettedDamageEffect3(row[211]), DamageLevelTransitionEffect12(row[212]), DamageLevelTransitionEffect23(row[213]), FlameEffect1(row[214]), FlameEffect2(row[215]), FlameEffect3(row[216]), TargetEffectY(to_int(row[217])), SelfAsAoeCenter(to_bool(row[218])), HidesWhenNotAttacking(to_bool(row[219])), HideTimeMs(to_int(row[220])), HideBeforeFirstHit(to_bool(row[221])), SpecialAttackWhenHidden(to_bool(row[222])), TargetedHitEffect(row[223]), TargetedHitEffectSpecial(row[224]), TargetedEffectVisualPushback(to_int(row[225])), UpTimeMs(to_int(row[226])), HideEffect(row[227]), AppearEffect(row[228]), AppearPushbackRadius(to_int(row[229])), AppearPushback(to_int(row[230])), AppearAreaObject(row[231]), ManaCollectAmount(to_int(row[232])), ManaGenerateTimeMs(to_int(row[233])), ManaGenerateLimit(to_int(row[234])), ManaOnDeath(to_int(row[235])), ManaOnDeathForOpponent(to_int(row[236])), HasRotationOnTimeline(to_bool(row[237])), TurretMovement(to_int(row[238])), ProjectileYOffset(to_int(row[239])), ChargeSpeedMultiplier(to_int(row[240])), DeployDelay(to_int(row[241])), DeployBaseAnimExportName(row[242]), DeployAnimationOverride(row[243]), JumpEnabled(to_bool(row[244])), SightClip(to_int(row[245])), AreaEffectOnDash(row[246]), SightClipSide(to_int(row[247])), WalkingSpeedTweakPercentage(to_int(row[248])), ShieldHitpoints(to_int(row[249])), ShieldDiePushback(to_int(row[250])), ShieldLostEffect(row[251]), ShieldLostAction(row[252]), BlueShieldExportName(row[253]), RedShieldExportName(row[254]), LoadAttackEffect1(row[255]), LoadAttackEffect2(row[256]), LoadAttackEffect3(row[257]), LoadAttackEffectReady(row[258]), RotateAngleSpeed(to_int(row[259])), DeployTimerDelay(to_int(row[260])), RetargetEachTick(to_bool(row[261])), RetargetAfterAttack(to_bool(row[262])), AttackShakeTime(to_int(row[263])), VisualHitSpeed(to_int(row[264])), VisualHitSpeed2(to_int(row[265])), VisualHitSpeed3(to_int(row[266])), Burst(to_int(row[267])), BurstDelay(to_int(row[268])), BurstKeepTarget(to_bool(row[269])), BurstAffectAnimation(to_bool(row[270])), ActivationTime(to_int(row[271])), AttackDashTime(to_int(row[272])), LoopingFilter(row[273]), BuildingTarget(to_bool(row[274])), SpawnConstPriority(to_bool(row[275])), BuffWhenNotAttacking(row[276]), BuffWhenNotAttackingTime(to_int(row[277])), BuffWhenNotAttackingEffect(row[278]), BuffWhenNotAttackingRemoveEffect(row[279]), AreaEffectOnHit(row[280]), AttackStateDamage(to_int(row[281])), AttackStateEffect(row[282]), SpeedBeforeAttack(to_int(row[283])), MoveEffect2(row[284]), ReflectedAttackBuff(row[285]), ReflectedAttackBuffDuration(to_int(row[286])), ReflectedAttackRadius(to_int(row[287])), ReflectedAttackDamage(to_int(row[288])), ReflectAttackCrownTowerDamage(to_int(row[289])), ReflectedAttackEffect(row[290]), ReflectedAttackTargetedEffect(row[291]), ReflectedAttackTargetedEffectSources(to_int(row[292])), IgnoreTargetsWithBuff(row[293]), DeprioritizeTargetsWithBuff(to_bool(row[294])), OverrideAttackFinishTime(to_bool(row[295])), AttackFinishTime(to_int(row[296])), BuffOnKill(row[297]), BuffOnKillTime(to_int(row[298])), BuffOn50HP(row[299]), BuffOn50HPTime(to_int(row[300])), BuffOnXHP(row[301]), BuffOnXHPPercent(to_int(row[302])), BuffOnXHPTime(to_int(row[303])), SuckElixirSpeed(to_int(row[304])), CapturableBuilding(to_bool(row[305])), SightRangeForCharacters(to_int(row[306])), AttackStateCount(to_int(row[307])), NeutralObject(to_bool(row[308])), BuffAfterHitsCount(to_int(row[309])), BuffAfterHitsTime(to_int(row[310])), BuffAfterHits(row[311]), MorphAfterHitsCount(to_int(row[312])), ConvertOnKill(row[313]), MoveSpeedByFriendlyMass(to_int(row[314])), MoveRadiusByFriendlyMass(to_int(row[315])), IgnoreBuff(row[316]), TargetLowestHP(to_bool(row[317])), Ability(row[318]), AbilityPendingEffect(row[319]), IgnoreClone(to_bool(row[320])), CustomSpawnFilter(row[321]), CustomCloneFilter(row[322]), IgnoreResurrect(to_bool(row[323])), AllowAreaDmgWhenInvisible(to_bool(row[324])), AvoidCountingForBuffAmountStats(to_bool(row[325])), UntargetableWhenSpawned(to_bool(row[326])), BoostItems(row[327]), ShaderFXBase(row[328]), ShaderFXTop(row[329]), GroupDamageDistributionPerc(to_int(row[330])), GroupMaxSize(to_int(row[331])), OnHitAction(row[332]), OnAttackAction(row[333]), ClonedVersion(row[334])
	{

	}

	EntityData::EntityData(std::string name, toml::table* tomlTable, EntityData* entity_data)
	{
		this->Name = name;
#pragma region Set Variable
		this->Rarity = entity_data->Rarity;
		this->Flags = entity_data->Flags;
		this->Tribe = entity_data->Tribe;
		this->SightRange = entity_data->SightRange;
		this->DeployTime = entity_data->DeployTime;
		this->ChargeRange = entity_data->ChargeRange;
		this->Speed = entity_data->Speed;
		this->Hitpoints = entity_data->Hitpoints;
		this->HitSpeed = entity_data->HitSpeed;
		this->LoadTime = entity_data->LoadTime;
		this->Damage = entity_data->Damage;
		this->DamageSpecial = entity_data->DamageSpecial;
		this->CrownTowerDamagePercent = entity_data->CrownTowerDamagePercent;
		this->LoadFirstHit = entity_data->LoadFirstHit;
		this->LoadAfterRetarget = entity_data->LoadAfterRetarget;
		this->StopTimeAfterAttack = entity_data->StopTimeAfterAttack;
		this->StopTimeAfterSpecialAttack = entity_data->StopTimeAfterSpecialAttack;
		this->Projectile = entity_data->Projectile;
		this->CustomFirstProjectile = entity_data->CustomFirstProjectile;
		this->MultipleProjectiles = entity_data->MultipleProjectiles;
		this->MultipleTargets = entity_data->MultipleTargets;
		this->AllTargetsHit = entity_data->AllTargetsHit;
		this->Range = entity_data->Range;
		this->MinimumRange = entity_data->MinimumRange;
		this->SpecialMinRange = entity_data->SpecialMinRange;
		this->SpecialRange = entity_data->SpecialRange;
		this->SpecialLoadTime = entity_data->SpecialLoadTime;
		this->SpecialChargeTime = entity_data->SpecialChargeTime;
		this->SpecialReadyEffect = entity_data->SpecialReadyEffect;
		this->SpecialChargingEffect = entity_data->SpecialChargingEffect;
		this->SpecialIgnoreBuildings = entity_data->SpecialIgnoreBuildings;
		this->SpecialAttacksToIgnoreList = entity_data->SpecialAttacksToIgnoreList;
		this->AttacksGround = entity_data->AttacksGround;
		this->AttacksAir = entity_data->AttacksAir;
		this->DeathDamageRadius = entity_data->DeathDamageRadius;
		this->DeathDamage = entity_data->DeathDamage;
		this->DeathPushBack = entity_data->DeathPushBack;
		this->AttackPushBack = entity_data->AttackPushBack;
		this->AttackPushBackEndAction = entity_data->AttackPushBackEndAction;
		this->MeleePushback = entity_data->MeleePushback;
		this->IsMeleePushbackAll = entity_data->IsMeleePushbackAll;
		this->LifeTime = entity_data->LifeTime;
		this->ProjectileSpecial = entity_data->ProjectileSpecial;
		this->ProjectileEffect = entity_data->ProjectileEffect;
		this->ProjectileEffectSpecial = entity_data->ProjectileEffectSpecial;
		this->AreaDamageRadius = entity_data->AreaDamageRadius;
		this->TargetOnlyBuildings = entity_data->TargetOnlyBuildings;
		this->TargetOnlyTroops = entity_data->TargetOnlyTroops;
		this->TargetOnlyTowers = entity_data->TargetOnlyTowers;
		this->TargetOnlyKingTower = entity_data->TargetOnlyKingTower;
		this->SpecialAttackInterval = entity_data->SpecialAttackInterval;
		this->BuffOnDamage = entity_data->BuffOnDamage;
		this->BuffOnDamageTime = entity_data->BuffOnDamageTime;
		this->StartingBuff = entity_data->StartingBuff;
		this->StartingBuffTime = entity_data->StartingBuffTime;
		this->Mesh = entity_data->Mesh;
		this->FileName = entity_data->FileName;
		this->BlueExportName = entity_data->BlueExportName;
		this->BlueTopExportName = entity_data->BlueTopExportName;
		this->RedExportName = entity_data->RedExportName;
		this->RedTopExportName = entity_data->RedTopExportName;
		this->PrestigeSWF = entity_data->PrestigeSWF;
		this->PrestigeExportName = entity_data->PrestigeExportName;
		this->PrestigeExportName2 = entity_data->PrestigeExportName2;
		this->PrestigeExportName3 = entity_data->PrestigeExportName3;
		this->PrestigeRedExportName = entity_data->PrestigeRedExportName;
		this->PrestigeRedExportName2 = entity_data->PrestigeRedExportName2;
		this->PrestigeRedExportName3 = entity_data->PrestigeRedExportName3;
		this->UseAnimator = entity_data->UseAnimator;
		this->AttachedCharacter = entity_data->AttachedCharacter;
		this->AttachedCharacterHeight = entity_data->AttachedCharacterHeight;
		this->DamageEffect = entity_data->DamageEffect;
		this->DamageEffectSpecial = entity_data->DamageEffectSpecial;
		this->DeathEffect = entity_data->DeathEffect;
		this->MoveEffect = entity_data->MoveEffect;
		this->LoopMoveEffect = entity_data->LoopMoveEffect;
		this->SpawnEffect = entity_data->SpawnEffect;
		this->SpawnEffectOnce = entity_data->SpawnEffectOnce;
		this->CrowdEffects = entity_data->CrowdEffects;
		this->ShadowScaleX = entity_data->ShadowScaleX;
		this->ShadowScaleY = entity_data->ShadowScaleY;
		this->ShadowX = entity_data->ShadowX;
		this->ShadowY = entity_data->ShadowY;
		this->ShadowSkew = entity_data->ShadowSkew;
		this->ShadowCustom = entity_data->ShadowCustom;
		this->ShadowCustomLow = entity_data->ShadowCustomLow;
		this->Pushback = entity_data->Pushback;
		this->IgnorePushback = entity_data->IgnorePushback;
		this->Scale = entity_data->Scale;
		this->CollisionRadius = entity_data->CollisionRadius;
		this->Mass = entity_data->Mass;
		this->TileSizeOverride = entity_data->TileSizeOverride;
		this->HealthBar = entity_data->HealthBar;
		this->HealthBarOffsetY = entity_data->HealthBarOffsetY;
		this->ShowHealthNumber = entity_data->ShowHealthNumber;
		this->FlyingHeight = entity_data->FlyingHeight;
		this->FlyDirectPaths = entity_data->FlyDirectPaths;
		this->FlyFromGround = entity_data->FlyFromGround;
		this->Hovering = entity_data->Hovering;
		this->DamageExportName = entity_data->DamageExportName;
		this->GrowTime = entity_data->GrowTime;
		this->GrowSize = entity_data->GrowSize;
		this->MorphCharacter = entity_data->MorphCharacter;
		this->MorphEffect = entity_data->MorphEffect;
		this->HealOnMorph = entity_data->HealOnMorph;
		this->AreaEffectOnMorph = entity_data->AreaEffectOnMorph;
		this->MorphTime = entity_data->MorphTime;
		this->MorphKeepTarget = entity_data->MorphKeepTarget;
		this->AttackStartEffect = entity_data->AttackStartEffect;
		this->AttackStartEffectSpecial = entity_data->AttackStartEffectSpecial;
		this->DashImmuneToDamageTime = entity_data->DashImmuneToDamageTime;
		this->DashStartEffect = entity_data->DashStartEffect;
		this->DashEffect = entity_data->DashEffect;
		this->DashCooldown = entity_data->DashCooldown;
		this->JumpHeight = entity_data->JumpHeight;
		this->DashPushBack = entity_data->DashPushBack;
		this->DashRadius = entity_data->DashRadius;
		this->DashDamage = entity_data->DashDamage;
		this->DashFilter = entity_data->DashFilter;
		this->DashConstantTime = entity_data->DashConstantTime;
		this->DashLandingTime = entity_data->DashLandingTime;
		this->LandingEffect = entity_data->LandingEffect;
		this->DashHitEffect = entity_data->DashHitEffect;
		this->DashMinRange = entity_data->DashMinRange;
		this->DashMaxRange = entity_data->DashMaxRange;
		this->DashDistance = entity_data->DashDistance;
		this->DashCount = entity_data->DashCount;
		this->DashSecondaryRange = entity_data->DashSecondaryRange;
		this->DashingDamage = entity_data->DashingDamage;
		this->DashingPushback = entity_data->DashingPushback;
		this->DashToTargetRadius = entity_data->DashToTargetRadius;
		this->JumpSpeed = entity_data->JumpSpeed;
		this->ContinuousEffect = entity_data->ContinuousEffect;
		this->SpawnStartTime = entity_data->SpawnStartTime;
		this->SpawnInterval = entity_data->SpawnInterval;
		this->SpawnNumber = entity_data->SpawnNumber;
		this->SpawnLimit = entity_data->SpawnLimit;
		this->DestroyAtLimit = entity_data->DestroyAtLimit;
		this->DestroyAtLimitEffect = entity_data->DestroyAtLimitEffect;
		this->SpawnPauseTime = entity_data->SpawnPauseTime;
		this->SpawnCharacter = entity_data->SpawnCharacter;
		this->SpawnCharacterWithDeploy = entity_data->SpawnCharacterWithDeploy;
		this->SpawnCharacterLevelIndex2 = entity_data->SpawnCharacterLevelIndex2;
		this->SpawnCharacter2 = entity_data->SpawnCharacter2;
		this->SpawnCharacterLevelIndex3 = entity_data->SpawnCharacterLevelIndex3;
		this->SpawnCharacter3 = entity_data->SpawnCharacter3;
		this->SpawnProjectile = entity_data->SpawnProjectile;
		this->SpawnCharacterEffect = entity_data->SpawnCharacterEffect;
		this->SpawnDeployBaseAnim = entity_data->SpawnDeployBaseAnim;
		this->SpawnRadius = entity_data->SpawnRadius;
		this->SpawnAttach = entity_data->SpawnAttach;
		this->SpawnAttachMaxRotation = entity_data->SpawnAttachMaxRotation;
		this->DeathSpawnDeployBaseAnim = entity_data->DeathSpawnDeployBaseAnim;
		this->DeathSpawnCount = entity_data->DeathSpawnCount;
		this->DeathSpawnCharacter = entity_data->DeathSpawnCharacter;
		this->DeathSpawnCount2 = entity_data->DeathSpawnCount2;
		this->DeathSpawnCharacter2 = entity_data->DeathSpawnCharacter2;
		this->DeathSpawnCharacter3 = entity_data->DeathSpawnCharacter3;
		this->DeathSpawnIsSameUnit = entity_data->DeathSpawnIsSameUnit;
		this->RandomizeDeathSpawn = entity_data->RandomizeDeathSpawn;
		this->DeathSpawnProjectile = entity_data->DeathSpawnProjectile;
		this->DeathSpawnRadius = entity_data->DeathSpawnRadius;
		this->DeathSpawnMinRadius = entity_data->DeathSpawnMinRadius;
		this->DeathSpawnAllowOverRiver = entity_data->DeathSpawnAllowOverRiver;
		this->SpawnAngleShift = entity_data->SpawnAngleShift;
		this->SpawnMaxAngle = entity_data->SpawnMaxAngle;
		this->DeathSpawnDeployTime = entity_data->DeathSpawnDeployTime;
		this->DeathSpawnPushback = entity_data->DeathSpawnPushback;
		this->DeathAreaEffect = entity_data->DeathAreaEffect;
		this->DeathInheritIgnoreList = entity_data->DeathInheritIgnoreList;
		this->Kamikaze = entity_data->Kamikaze;
		this->KamikazeTime = entity_data->KamikazeTime;
		this->KamikazeEffect = entity_data->KamikazeEffect;
		this->SpawnPathfindSpeed = entity_data->SpawnPathfindSpeed;
		this->SpawnPathfindEffect = entity_data->SpawnPathfindEffect;
		this->SpawnPathfindMorph = entity_data->SpawnPathfindMorph;
		this->SpawnPushback = entity_data->SpawnPushback;
		this->SpawnPushbackRadius = entity_data->SpawnPushbackRadius;
		this->SpawnAreaObject = entity_data->SpawnAreaObject;
		this->SpawnAreaObjectLevelIndex = entity_data->SpawnAreaObjectLevelIndex;
		this->IngamePathfindSpeed = entity_data->IngamePathfindSpeed;
		this->IngamePathfindEffect = entity_data->IngamePathfindEffect;
		this->IngamePathfindStartEffect = entity_data->IngamePathfindStartEffect;
		this->IngamePathfindStopEffect = entity_data->IngamePathfindStopEffect;
		this->IngamePathfindStopDeployBaseAnim = entity_data->IngamePathfindStopDeployBaseAnim;
		this->ChargeEffect = entity_data->ChargeEffect;
		this->TakeDamageEffect = entity_data->TakeDamageEffect;
		this->ProjectileStartRadius = entity_data->ProjectileStartRadius;
		this->ProjectileStartZ = entity_data->ProjectileStartZ;
		this->StopMovementAfterMS = entity_data->StopMovementAfterMS;
		this->WaitMS = entity_data->WaitMS;
		this->DontStopMoveAnim = entity_data->DontStopMoveAnim;
		this->IsSummonerTower = entity_data->IsSummonerTower;
		this->NoDeploySizeW = entity_data->NoDeploySizeW;
		this->NoDeploySizeH = entity_data->NoDeploySizeH;
		this->TID = entity_data->TID;
		this->AttackSequence = entity_data->AttackSequence;
		this->AttackSeqStateEffect1 = entity_data->AttackSeqStateEffect1;
		this->AttackSeqStateEffect2 = entity_data->AttackSeqStateEffect2;
		this->AttackSeqStateEffect3 = entity_data->AttackSeqStateEffect3;
		this->VariableDamageTime1 = entity_data->VariableDamageTime1;
		this->VariableDamage2 = entity_data->VariableDamage2;
		this->MeleePushback2 = entity_data->MeleePushback2;
		this->IsMeleePushbackAll2 = entity_data->IsMeleePushbackAll2;
		this->VariableDamageTime2 = entity_data->VariableDamageTime2;
		this->VariableDamage3 = entity_data->VariableDamage3;
		this->MeleePushback3 = entity_data->MeleePushback3;
		this->IsMeleePushbackAll3 = entity_data->IsMeleePushbackAll3;
		this->TargettedDamageEffect1 = entity_data->TargettedDamageEffect1;
		this->TargettedDamageEffect2 = entity_data->TargettedDamageEffect2;
		this->TargettedDamageEffect3 = entity_data->TargettedDamageEffect3;
		this->DamageLevelTransitionEffect12 = entity_data->DamageLevelTransitionEffect12;
		this->DamageLevelTransitionEffect23 = entity_data->DamageLevelTransitionEffect23;
		this->FlameEffect1 = entity_data->FlameEffect1;
		this->FlameEffect2 = entity_data->FlameEffect2;
		this->FlameEffect3 = entity_data->FlameEffect3;
		this->TargetEffectY = entity_data->TargetEffectY;
		this->SelfAsAoeCenter = entity_data->SelfAsAoeCenter;
		this->HidesWhenNotAttacking = entity_data->HidesWhenNotAttacking;
		this->HideTimeMs = entity_data->HideTimeMs;
		this->HideBeforeFirstHit = entity_data->HideBeforeFirstHit;
		this->SpecialAttackWhenHidden = entity_data->SpecialAttackWhenHidden;
		this->TargetedHitEffect = entity_data->TargetedHitEffect;
		this->TargetedHitEffectSpecial = entity_data->TargetedHitEffectSpecial;
		this->TargetedEffectVisualPushback = entity_data->TargetedEffectVisualPushback;
		this->UpTimeMs = entity_data->UpTimeMs;
		this->HideEffect = entity_data->HideEffect;
		this->AppearEffect = entity_data->AppearEffect;
		this->AppearPushbackRadius = entity_data->AppearPushbackRadius;
		this->AppearPushback = entity_data->AppearPushback;
		this->AppearAreaObject = entity_data->AppearAreaObject;
		this->ManaCollectAmount = entity_data->ManaCollectAmount;
		this->ManaGenerateTimeMs = entity_data->ManaGenerateTimeMs;
		this->ManaGenerateLimit = entity_data->ManaGenerateLimit;
		this->ManaOnDeath = entity_data->ManaOnDeath;
		this->ManaOnDeathForOpponent = entity_data->ManaOnDeathForOpponent;
		this->HasRotationOnTimeline = entity_data->HasRotationOnTimeline;
		this->TurretMovement = entity_data->TurretMovement;
		this->ProjectileYOffset = entity_data->ProjectileYOffset;
		this->ChargeSpeedMultiplier = entity_data->ChargeSpeedMultiplier;
		this->DeployDelay = entity_data->DeployDelay;
		this->DeployBaseAnimExportName = entity_data->DeployBaseAnimExportName;
		this->DeployAnimationOverride = entity_data->DeployAnimationOverride;
		this->JumpEnabled = entity_data->JumpEnabled;
		this->SightClip = entity_data->SightClip;
		this->AreaEffectOnDash = entity_data->AreaEffectOnDash;
		this->SightClipSide = entity_data->SightClipSide;
		this->WalkingSpeedTweakPercentage = entity_data->WalkingSpeedTweakPercentage;
		this->ShieldHitpoints = entity_data->ShieldHitpoints;
		this->ShieldDiePushback = entity_data->ShieldDiePushback;
		this->ShieldLostEffect = entity_data->ShieldLostEffect;
		this->ShieldLostAction = entity_data->ShieldLostAction;
		this->BlueShieldExportName = entity_data->BlueShieldExportName;
		this->RedShieldExportName = entity_data->RedShieldExportName;
		this->LoadAttackEffect1 = entity_data->LoadAttackEffect1;
		this->LoadAttackEffect2 = entity_data->LoadAttackEffect2;
		this->LoadAttackEffect3 = entity_data->LoadAttackEffect3;
		this->LoadAttackEffectReady = entity_data->LoadAttackEffectReady;
		this->RotateAngleSpeed = entity_data->RotateAngleSpeed;
		this->DeployTimerDelay = entity_data->DeployTimerDelay;
		this->RetargetEachTick = entity_data->RetargetEachTick;
		this->RetargetAfterAttack = entity_data->RetargetAfterAttack;
		this->AttackShakeTime = entity_data->AttackShakeTime;
		this->VisualHitSpeed = entity_data->VisualHitSpeed;
		this->VisualHitSpeed2 = entity_data->VisualHitSpeed2;
		this->VisualHitSpeed3 = entity_data->VisualHitSpeed3;
		this->Burst = entity_data->Burst;
		this->BurstDelay = entity_data->BurstDelay;
		this->BurstKeepTarget = entity_data->BurstKeepTarget;
		this->BurstAffectAnimation = entity_data->BurstAffectAnimation;
		this->ActivationTime = entity_data->ActivationTime;
		this->AttackDashTime = entity_data->AttackDashTime;
		this->LoopingFilter = entity_data->LoopingFilter;
		this->BuildingTarget = entity_data->BuildingTarget;
		this->SpawnConstPriority = entity_data->SpawnConstPriority;
		this->BuffWhenNotAttacking = entity_data->BuffWhenNotAttacking;
		this->BuffWhenNotAttackingTime = entity_data->BuffWhenNotAttackingTime;
		this->BuffWhenNotAttackingEffect = entity_data->BuffWhenNotAttackingEffect;
		this->BuffWhenNotAttackingRemoveEffect = entity_data->BuffWhenNotAttackingRemoveEffect;
		this->AreaEffectOnHit = entity_data->AreaEffectOnHit;
		this->AttackStateDamage = entity_data->AttackStateDamage;
		this->AttackStateEffect = entity_data->AttackStateEffect;
		this->SpeedBeforeAttack = entity_data->SpeedBeforeAttack;
		this->MoveEffect2 = entity_data->MoveEffect2;
		this->ReflectedAttackBuff = entity_data->ReflectedAttackBuff;
		this->ReflectedAttackBuffDuration = entity_data->ReflectedAttackBuffDuration;
		this->ReflectedAttackRadius = entity_data->ReflectedAttackRadius;
		this->ReflectedAttackDamage = entity_data->ReflectedAttackDamage;
		this->ReflectAttackCrownTowerDamage = entity_data->ReflectAttackCrownTowerDamage;
		this->ReflectedAttackEffect = entity_data->ReflectedAttackEffect;
		this->ReflectedAttackTargetedEffect = entity_data->ReflectedAttackTargetedEffect;
		this->ReflectedAttackTargetedEffectSources = entity_data->ReflectedAttackTargetedEffectSources;
		this->IgnoreTargetsWithBuff = entity_data->IgnoreTargetsWithBuff;
		this->DeprioritizeTargetsWithBuff = entity_data->DeprioritizeTargetsWithBuff;
		this->OverrideAttackFinishTime = entity_data->OverrideAttackFinishTime;
		this->AttackFinishTime = entity_data->AttackFinishTime;
		this->BuffOnKill = entity_data->BuffOnKill;
		this->BuffOnKillTime = entity_data->BuffOnKillTime;
		this->BuffOn50HP = entity_data->BuffOn50HP;
		this->BuffOn50HPTime = entity_data->BuffOn50HPTime;
		this->BuffOnXHP = entity_data->BuffOnXHP;
		this->BuffOnXHPPercent = entity_data->BuffOnXHPPercent;
		this->BuffOnXHPTime = entity_data->BuffOnXHPTime;
		this->SuckElixirSpeed = entity_data->SuckElixirSpeed;
		this->CapturableBuilding = entity_data->CapturableBuilding;
		this->SightRangeForCharacters = entity_data->SightRangeForCharacters;
		this->AttackStateCount = entity_data->AttackStateCount;
		this->NeutralObject = entity_data->NeutralObject;
		this->BuffAfterHitsCount = entity_data->BuffAfterHitsCount;
		this->BuffAfterHitsTime = entity_data->BuffAfterHitsTime;
		this->BuffAfterHits = entity_data->BuffAfterHits;
		this->MorphAfterHitsCount = entity_data->MorphAfterHitsCount;
		this->ConvertOnKill = entity_data->ConvertOnKill;
		this->MoveSpeedByFriendlyMass = entity_data->MoveSpeedByFriendlyMass;
		this->MoveRadiusByFriendlyMass = entity_data->MoveRadiusByFriendlyMass;
		this->IgnoreBuff = entity_data->IgnoreBuff;
		this->TargetLowestHP = entity_data->TargetLowestHP;
		this->Ability = entity_data->Ability;
		this->AbilityPendingEffect = entity_data->AbilityPendingEffect;
		this->IgnoreClone = entity_data->IgnoreClone;
		this->CustomSpawnFilter = entity_data->CustomSpawnFilter;
		this->CustomCloneFilter = entity_data->CustomCloneFilter;
		this->IgnoreResurrect = entity_data->IgnoreResurrect;
		this->AllowAreaDmgWhenInvisible = entity_data->AllowAreaDmgWhenInvisible;
		this->AvoidCountingForBuffAmountStats = entity_data->AvoidCountingForBuffAmountStats;
		this->UntargetableWhenSpawned = entity_data->UntargetableWhenSpawned;
		this->BoostItems = entity_data->BoostItems;
		this->ShaderFXBase = entity_data->ShaderFXBase;
		this->ShaderFXTop = entity_data->ShaderFXTop;
		this->GroupDamageDistributionPerc = entity_data->GroupDamageDistributionPerc;
		this->GroupMaxSize = entity_data->GroupMaxSize;
		this->OnHitAction = entity_data->OnHitAction;
		this->OnAttackAction = entity_data->OnAttackAction;
		this->ClonedVersion = entity_data->ClonedVersion;

#pragma endregion
		std::unordered_map<std::string, void*> variableMap = {
			{"Name", &this->Name},
			{"Rarity", &this->Rarity},
			{"Flags", &this->Flags},
			{"Tribe", &this->Tribe},
			{"SightRange", &this->SightRange},
			{"DeployTime", &this->DeployTime},
			{"ChargeRange", &this->ChargeRange},
			{"Speed", &this->Speed},
			{"Hitpoints", &this->Hitpoints},
			{"HitSpeed", &this->HitSpeed},
			{"LoadTime", &this->LoadTime},
			{"Damage", &this->Damage},
			{"DamageSpecial", &this->DamageSpecial},
			{"CrownTowerDamagePercent", &this->CrownTowerDamagePercent},
			{"LoadFirstHit", &this->LoadFirstHit},
			{"LoadAfterRetarget", &this->LoadAfterRetarget},
			{"StopTimeAfterAttack", &this->StopTimeAfterAttack},
			{"StopTimeAfterSpecialAttack", &this->StopTimeAfterSpecialAttack},
			{"Projectile", &this->Projectile},
			{"CustomFirstProjectile", &this->CustomFirstProjectile},
			{"MultipleProjectiles", &this->MultipleProjectiles},
			{"MultipleTargets", &this->MultipleTargets},
			{"AllTargetsHit", &this->AllTargetsHit},
			{"Range", &this->Range},
			{"MinimumRange", &this->MinimumRange},
			{"SpecialMinRange", &this->SpecialMinRange},
			{"SpecialRange", &this->SpecialRange},
			{"SpecialLoadTime", &this->SpecialLoadTime},
			{"SpecialChargeTime", &this->SpecialChargeTime},
			{"SpecialReadyEffect", &this->SpecialReadyEffect},
			{"SpecialChargingEffect", &this->SpecialChargingEffect},
			{"SpecialIgnoreBuildings", &this->SpecialIgnoreBuildings},
			{"SpecialAttacksToIgnoreList", &this->SpecialAttacksToIgnoreList},
			{"AttacksGround", &this->AttacksGround},
			{"AttacksAir", &this->AttacksAir},
			{"DeathDamageRadius", &this->DeathDamageRadius},
			{"DeathDamage", &this->DeathDamage},
			{"DeathPushBack", &this->DeathPushBack},
			{"AttackPushBack", &this->AttackPushBack},
			{"AttackPushBackEndAction", &this->AttackPushBackEndAction},
			{"MeleePushback", &this->MeleePushback},
			{"IsMeleePushbackAll", &this->IsMeleePushbackAll},
			{"LifeTime", &this->LifeTime},
			{"ProjectileSpecial", &this->ProjectileSpecial},
			{"ProjectileEffect", &this->ProjectileEffect},
			{"ProjectileEffectSpecial", &this->ProjectileEffectSpecial},
			{"AreaDamageRadius", &this->AreaDamageRadius},
			{"TargetOnlyBuildings", &this->TargetOnlyBuildings},
			{"TargetOnlyTroops", &this->TargetOnlyTroops},
			{"TargetOnlyTowers", &this->TargetOnlyTowers},
			{"TargetOnlyKingTower", &this->TargetOnlyKingTower},
			{"SpecialAttackInterval", &this->SpecialAttackInterval},
			{"BuffOnDamage", &this->BuffOnDamage},
			{"BuffOnDamageTime", &this->BuffOnDamageTime},
			{"StartingBuff", &this->StartingBuff},
			{"StartingBuffTime", &this->StartingBuffTime},
			{"Mesh", &this->Mesh},
			{"FileName", &this->FileName},
			{"BlueExportName", &this->BlueExportName},
			{"BlueTopExportName", &this->BlueTopExportName},
			{"RedExportName", &this->RedExportName},
			{"RedTopExportName", &this->RedTopExportName},
			{"PrestigeSWF", &this->PrestigeSWF},
			{"PrestigeExportName", &this->PrestigeExportName},
			{"PrestigeExportName2", &this->PrestigeExportName2},
			{"PrestigeExportName3", &this->PrestigeExportName3},
			{"PrestigeRedExportName", &this->PrestigeRedExportName},
			{"PrestigeRedExportName2", &this->PrestigeRedExportName2},
			{"PrestigeRedExportName3", &this->PrestigeRedExportName3},
			{"UseAnimator", &this->UseAnimator},
			{"AttachedCharacter", &this->AttachedCharacter},
			{"AttachedCharacterHeight", &this->AttachedCharacterHeight},
			{"DamageEffect", &this->DamageEffect},
			{"DamageEffectSpecial", &this->DamageEffectSpecial},
			{"DeathEffect", &this->DeathEffect},
			{"MoveEffect", &this->MoveEffect},
			{"LoopMoveEffect", &this->LoopMoveEffect},
			{"SpawnEffect", &this->SpawnEffect},
			{"SpawnEffectOnce", &this->SpawnEffectOnce},
			{"CrowdEffects", &this->CrowdEffects},
			{"ShadowScaleX", &this->ShadowScaleX},
			{"ShadowScaleY", &this->ShadowScaleY},
			{"ShadowX", &this->ShadowX},
			{"ShadowY", &this->ShadowY},
			{"ShadowSkew", &this->ShadowSkew},
			{"ShadowCustom", &this->ShadowCustom},
			{"ShadowCustomLow", &this->ShadowCustomLow},
			{"Pushback", &this->Pushback},
			{"IgnorePushback", &this->IgnorePushback},
			{"Scale", &this->Scale},
			{"CollisionRadius", &this->CollisionRadius},
			{"Mass", &this->Mass},
			{"TileSizeOverride", &this->TileSizeOverride},
			{"HealthBar", &this->HealthBar},
			{"HealthBarOffsetY", &this->HealthBarOffsetY},
			{"ShowHealthNumber", &this->ShowHealthNumber},
			{"FlyingHeight", &this->FlyingHeight},
			{"FlyDirectPaths", &this->FlyDirectPaths},
			{"FlyFromGround", &this->FlyFromGround},
			{"Hovering", &this->Hovering},
			{"DamageExportName", &this->DamageExportName},
			{"GrowTime", &this->GrowTime},
			{"GrowSize", &this->GrowSize},
			{"MorphCharacter", &this->MorphCharacter},
			{"MorphEffect", &this->MorphEffect},
			{"HealOnMorph", &this->HealOnMorph},
			{"AreaEffectOnMorph", &this->AreaEffectOnMorph},
			{"MorphTime", &this->MorphTime},
			{"MorphKeepTarget", &this->MorphKeepTarget},
			{"AttackStartEffect", &this->AttackStartEffect},
			{"AttackStartEffectSpecial", &this->AttackStartEffectSpecial},
			{"DashImmuneToDamageTime", &this->DashImmuneToDamageTime},
			{"DashStartEffect", &this->DashStartEffect},
			{"DashEffect", &this->DashEffect},
			{"DashCooldown", &this->DashCooldown},
			{"JumpHeight", &this->JumpHeight},
			{"DashPushBack", &this->DashPushBack},
			{"DashRadius", &this->DashRadius},
			{"DashDamage", &this->DashDamage},
			{"DashFilter", &this->DashFilter},
			{"DashConstantTime", &this->DashConstantTime},
			{"DashLandingTime", &this->DashLandingTime},
			{"LandingEffect", &this->LandingEffect},
			{"DashHitEffect", &this->DashHitEffect},
			{"DashMinRange", &this->DashMinRange},
			{"DashMaxRange", &this->DashMaxRange},
			{"DashDistance", &this->DashDistance},
			{"DashCount", &this->DashCount},
			{"DashSecondaryRange", &this->DashSecondaryRange},
			{"DashingDamage", &this->DashingDamage},
			{"DashingPushback", &this->DashingPushback},
			{"DashToTargetRadius", &this->DashToTargetRadius},
			{"JumpSpeed", &this->JumpSpeed},
			{"ContinuousEffect", &this->ContinuousEffect},
			{"SpawnStartTime", &this->SpawnStartTime},
			{"SpawnInterval", &this->SpawnInterval},
			{"SpawnNumber", &this->SpawnNumber},
			{"SpawnLimit", &this->SpawnLimit},
			{"DestroyAtLimit", &this->DestroyAtLimit},
			{"DestroyAtLimitEffect", &this->DestroyAtLimitEffect},
			{"SpawnPauseTime", &this->SpawnPauseTime},
			{"SpawnCharacter", &this->SpawnCharacter},
			{"SpawnCharacterWithDeploy", &this->SpawnCharacterWithDeploy},
			{"SpawnCharacterLevelIndex2", &this->SpawnCharacterLevelIndex2},
			{"SpawnCharacter2", &this->SpawnCharacter2},
			{"SpawnCharacterLevelIndex3", &this->SpawnCharacterLevelIndex3},
			{"SpawnCharacter3", &this->SpawnCharacter3},
			{"SpawnProjectile", &this->SpawnProjectile},
			{"SpawnCharacterEffect", &this->SpawnCharacterEffect},
			{"SpawnDeployBaseAnim", &this->SpawnDeployBaseAnim},
			{"SpawnRadius", &this->SpawnRadius},
			{"SpawnAttach", &this->SpawnAttach},
			{"SpawnAttachMaxRotation", &this->SpawnAttachMaxRotation},
			{"DeathSpawnDeployBaseAnim", &this->DeathSpawnDeployBaseAnim},
			{"DeathSpawnCount", &this->DeathSpawnCount},
			{"DeathSpawnCharacter", &this->DeathSpawnCharacter},
			{"DeathSpawnCount2", &this->DeathSpawnCount2},
			{"DeathSpawnCharacter2", &this->DeathSpawnCharacter2},
			{"DeathSpawnCharacter3", &this->DeathSpawnCharacter3},
			{"DeathSpawnIsSameUnit", &this->DeathSpawnIsSameUnit},
			{"RandomizeDeathSpawn", &this->RandomizeDeathSpawn},
			{"DeathSpawnProjectile", &this->DeathSpawnProjectile},
			{"DeathSpawnRadius", &this->DeathSpawnRadius},
			{"DeathSpawnMinRadius", &this->DeathSpawnMinRadius},
			{"DeathSpawnAllowOverRiver", &this->DeathSpawnAllowOverRiver},
			{"SpawnAngleShift", &this->SpawnAngleShift},
			{"SpawnMaxAngle", &this->SpawnMaxAngle},
			{"DeathSpawnDeployTime", &this->DeathSpawnDeployTime},
			{"DeathSpawnPushback", &this->DeathSpawnPushback},
			{"DeathAreaEffect", &this->DeathAreaEffect},
			{"DeathInheritIgnoreList", &this->DeathInheritIgnoreList},
			{"Kamikaze", &this->Kamikaze},
			{"KamikazeTime", &this->KamikazeTime},
			{"KamikazeEffect", &this->KamikazeEffect},
			{"SpawnPathfindSpeed", &this->SpawnPathfindSpeed},
			{"SpawnPathfindEffect", &this->SpawnPathfindEffect},
			{"SpawnPathfindMorph", &this->SpawnPathfindMorph},
			{"SpawnPushback", &this->SpawnPushback},
			{"SpawnPushbackRadius", &this->SpawnPushbackRadius},
			{"SpawnAreaObject", &this->SpawnAreaObject},
			{"SpawnAreaObjectLevelIndex", &this->SpawnAreaObjectLevelIndex},
			{"IngamePathfindSpeed", &this->IngamePathfindSpeed},
			{"IngamePathfindEffect", &this->IngamePathfindEffect},
			{"IngamePathfindStartEffect", &this->IngamePathfindStartEffect},
			{"IngamePathfindStopEffect", &this->IngamePathfindStopEffect},
			{"IngamePathfindStopDeployBaseAnim", &this->IngamePathfindStopDeployBaseAnim},
			{"ChargeEffect", &this->ChargeEffect},
			{"TakeDamageEffect", &this->TakeDamageEffect},
			{"ProjectileStartRadius", &this->ProjectileStartRadius},
			{"ProjectileStartZ", &this->ProjectileStartZ},
			{"StopMovementAfterMS", &this->StopMovementAfterMS},
			{"WaitMS", &this->WaitMS},
			{"DontStopMoveAnim", &this->DontStopMoveAnim},
			{"IsSummonerTower", &this->IsSummonerTower},
			{"NoDeploySizeW", &this->NoDeploySizeW},
			{"NoDeploySizeH", &this->NoDeploySizeH},
			{"TID", &this->TID},
			{"AttackSequence", &this->AttackSequence},
			{"AttackSeqStateEffect1", &this->AttackSeqStateEffect1},
			{"AttackSeqStateEffect2", &this->AttackSeqStateEffect2},
			{"AttackSeqStateEffect3", &this->AttackSeqStateEffect3},
			{"VariableDamageTime1", &this->VariableDamageTime1},
			{"VariableDamage2", &this->VariableDamage2},
			{"MeleePushback2", &this->MeleePushback2},
			{"IsMeleePushbackAll2", &this->IsMeleePushbackAll2},
			{"VariableDamageTime2", &this->VariableDamageTime2},
			{"VariableDamage3", &this->VariableDamage3},
			{"MeleePushback3", &this->MeleePushback3},
			{"IsMeleePushbackAll3", &this->IsMeleePushbackAll3},
			{"TargettedDamageEffect1", &this->TargettedDamageEffect1},
			{"TargettedDamageEffect2", &this->TargettedDamageEffect2},
			{"TargettedDamageEffect3", &this->TargettedDamageEffect3},
			{"DamageLevelTransitionEffect12", &this->DamageLevelTransitionEffect12},
			{"DamageLevelTransitionEffect23", &this->DamageLevelTransitionEffect23},
			{"FlameEffect1", &this->FlameEffect1},
			{"FlameEffect2", &this->FlameEffect2},
			{"FlameEffect3", &this->FlameEffect3},
			{"TargetEffectY", &this->TargetEffectY},
			{"SelfAsAoeCenter", &this->SelfAsAoeCenter},
			{"HidesWhenNotAttacking", &this->HidesWhenNotAttacking},
			{"HideTimeMs", &this->HideTimeMs},
			{"HideBeforeFirstHit", &this->HideBeforeFirstHit},
			{"SpecialAttackWhenHidden", &this->SpecialAttackWhenHidden},
			{"TargetedHitEffect", &this->TargetedHitEffect},
			{"TargetedHitEffectSpecial", &this->TargetedHitEffectSpecial},
			{"TargetedEffectVisualPushback", &this->TargetedEffectVisualPushback},
			{"UpTimeMs", &this->UpTimeMs},
			{"HideEffect", &this->HideEffect},
			{"AppearEffect", &this->AppearEffect},
			{"AppearPushbackRadius", &this->AppearPushbackRadius},
			{"AppearPushback", &this->AppearPushback},
			{"AppearAreaObject", &this->AppearAreaObject},
			{"ManaCollectAmount", &this->ManaCollectAmount},
			{"ManaGenerateTimeMs", &this->ManaGenerateTimeMs},
			{"ManaGenerateLimit", &this->ManaGenerateLimit},
			{"ManaOnDeath", &this->ManaOnDeath},
			{"ManaOnDeathForOpponent", &this->ManaOnDeathForOpponent},
			{"HasRotationOnTimeline", &this->HasRotationOnTimeline},
			{"TurretMovement", &this->TurretMovement},
			{"ProjectileYOffset", &this->ProjectileYOffset},
			{"ChargeSpeedMultiplier", &this->ChargeSpeedMultiplier},
			{"DeployDelay", &this->DeployDelay},
			{"DeployBaseAnimExportName", &this->DeployBaseAnimExportName},
			{"DeployAnimationOverride", &this->DeployAnimationOverride},
			{"JumpEnabled", &this->JumpEnabled},
			{"SightClip", &this->SightClip},
			{"AreaEffectOnDash", &this->AreaEffectOnDash},
			{"SightClipSide", &this->SightClipSide},
			{"WalkingSpeedTweakPercentage", &this->WalkingSpeedTweakPercentage},
			{"ShieldHitpoints", &this->ShieldHitpoints},
			{"ShieldDiePushback", &this->ShieldDiePushback},
			{"ShieldLostEffect", &this->ShieldLostEffect},
			{"ShieldLostAction", &this->ShieldLostAction},
			{"BlueShieldExportName", &this->BlueShieldExportName},
			{"RedShieldExportName", &this->RedShieldExportName},
			{"LoadAttackEffect1", &this->LoadAttackEffect1},
			{"LoadAttackEffect2", &this->LoadAttackEffect2},
			{"LoadAttackEffect3", &this->LoadAttackEffect3},
			{"LoadAttackEffectReady", &this->LoadAttackEffectReady},
			{"RotateAngleSpeed", &this->RotateAngleSpeed},
			{"DeployTimerDelay", &this->DeployTimerDelay},
			{"RetargetEachTick", &this->RetargetEachTick},
			{"RetargetAfterAttack", &this->RetargetAfterAttack},
			{"AttackShakeTime", &this->AttackShakeTime},
			{"VisualHitSpeed", &this->VisualHitSpeed},
			{"VisualHitSpeed2", &this->VisualHitSpeed2},
			{"VisualHitSpeed3", &this->VisualHitSpeed3},
			{"Burst", &this->Burst},
			{"BurstDelay", &this->BurstDelay},
			{"BurstKeepTarget", &this->BurstKeepTarget},
			{"BurstAffectAnimation", &this->BurstAffectAnimation},
			{"ActivationTime", &this->ActivationTime},
			{"AttackDashTime", &this->AttackDashTime},
			{"LoopingFilter", &this->LoopingFilter},
			{"BuildingTarget", &this->BuildingTarget},
			{"SpawnConstPriority", &this->SpawnConstPriority},
			{"BuffWhenNotAttacking", &this->BuffWhenNotAttacking},
			{"BuffWhenNotAttackingTime", &this->BuffWhenNotAttackingTime},
			{"BuffWhenNotAttackingEffect", &this->BuffWhenNotAttackingEffect},
			{"BuffWhenNotAttackingRemoveEffect", &this->BuffWhenNotAttackingRemoveEffect},
			{"AreaEffectOnHit", &this->AreaEffectOnHit},
			{"AttackStateDamage", &this->AttackStateDamage},
			{"AttackStateEffect", &this->AttackStateEffect},
			{"SpeedBeforeAttack", &this->SpeedBeforeAttack},
			{"MoveEffect2", &this->MoveEffect2},
			{"ReflectedAttackBuff", &this->ReflectedAttackBuff},
			{"ReflectedAttackBuffDuration", &this->ReflectedAttackBuffDuration},
			{"ReflectedAttackRadius", &this->ReflectedAttackRadius},
			{"ReflectedAttackDamage", &this->ReflectedAttackDamage},
			{"ReflectAttackCrownTowerDamage", &this->ReflectAttackCrownTowerDamage},
			{"ReflectedAttackEffect", &this->ReflectedAttackEffect},
			{"ReflectedAttackTargetedEffect", &this->ReflectedAttackTargetedEffect},
			{"ReflectedAttackTargetedEffectSources", &this->ReflectedAttackTargetedEffectSources},
			{"IgnoreTargetsWithBuff", &this->IgnoreTargetsWithBuff},
			{"DeprioritizeTargetsWithBuff", &this->DeprioritizeTargetsWithBuff},
			{"OverrideAttackFinishTime", &this->OverrideAttackFinishTime},
			{"AttackFinishTime", &this->AttackFinishTime},
			{"BuffOnKill", &this->BuffOnKill},
			{"BuffOnKillTime", &this->BuffOnKillTime},
			{"BuffOn50HP", &this->BuffOn50HP},
			{"BuffOn50HPTime", &this->BuffOn50HPTime},
			{"BuffOnXHP", &this->BuffOnXHP},
			{"BuffOnXHPPercent", &this->BuffOnXHPPercent},
			{"BuffOnXHPTime", &this->BuffOnXHPTime},
			{"SuckElixirSpeed", &this->SuckElixirSpeed},
			{"CapturableBuilding", &this->CapturableBuilding},
			{"SightRangeForCharacters", &this->SightRangeForCharacters},
			{"AttackStateCount", &this->AttackStateCount},
			{"NeutralObject", &this->NeutralObject},
			{"BuffAfterHitsCount", &this->BuffAfterHitsCount},
			{"BuffAfterHitsTime", &this->BuffAfterHitsTime},
			{"BuffAfterHits", &this->BuffAfterHits},
			{"MorphAfterHitsCount", &this->MorphAfterHitsCount},
			{"ConvertOnKill", &this->ConvertOnKill},
			{"MoveSpeedByFriendlyMass", &this->MoveSpeedByFriendlyMass},
			{"MoveRadiusByFriendlyMass", &this->MoveRadiusByFriendlyMass},
			{"IgnoreBuff", &this->IgnoreBuff},
			{"TargetLowestHP", &this->TargetLowestHP},
			{"Ability", &this->Ability},
			{"AbilityPendingEffect", &this->AbilityPendingEffect},
			{"IgnoreClone", &this->IgnoreClone},
			{"CustomSpawnFilter", &this->CustomSpawnFilter},
			{"CustomCloneFilter", &this->CustomCloneFilter},
			{"IgnoreResurrect", &this->IgnoreResurrect},
			{"AllowAreaDmgWhenInvisible", &this->AllowAreaDmgWhenInvisible},
			{"AvoidCountingForBuffAmountStats", &this->AvoidCountingForBuffAmountStats},
			{"UntargetableWhenSpawned", &this->UntargetableWhenSpawned},
			{"BoostItems", &this->BoostItems},
			{"ShaderFXBase", &this->ShaderFXBase},
			{"ShaderFXTop", &this->ShaderFXTop},
			{"GroupDamageDistributionPerc", &this->GroupDamageDistributionPerc},
			{"GroupMaxSize", &this->GroupMaxSize},
			{"OnHitAction", &this->OnHitAction},
			{"OnAttackAction", &this->OnAttackAction},
			{"ClonedVersion", &this->ClonedVersion},

		};
		for (const auto& pair : *tomlTable) {
			const toml::key& key = pair.first;
			const toml::node& value = pair.second;
			std::string keyValue(key.str());
			if (variableMap[keyValue] == nullptr) {
				continue;
			}
			if (value.is<int64_t>()) {
				*static_cast<int*>(variableMap[keyValue]) = value.value<int64_t>().value();
			}
			else if (value.is<std::string>()) {
				*static_cast<std::string*>(variableMap[keyValue]) = value.value<std::string>().value();
			}
			else if (value.is_array()) {
				const toml::array* arrayValue = value.as_array();

				auto* arrayElement = arrayValue->get(arrayValue->size() - 1);
				if (arrayElement->is<int64_t>()) {
					*static_cast<int*>(variableMap[keyValue]) = arrayElement->value<int64_t>().value();
				}
				else if (arrayElement->is<std::string>()) {
					*static_cast<std::string*>(variableMap[keyValue]) = arrayElement->value<std::string>().value();
				}
			}
			else {
				std::cout << "Key: " << key << ", Value (unknown type)" << std::endl;
			}
		}
	}

	EntityData::~EntityData()
	{

	}
}