// Copyright (C) 2018 Arno Ansems
// 
// This program is free software: you can redistribute it and/or modify 
// it under the terms of the GNU General Public License as published by 
// the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version. 
// 
// This program is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details. 
// 
// You should have received a copy of the GNU General Public License 
// along with this program.  If not, see http://www.gnu.org/licenses/ 
//
// Decorate
//
// Data structures for defining actor behavior. Currently all hard-coded, but could
// potentially be extended to support external DECORATE files.
//
#pragma once

#include <stdint.h>
#include "EgaColor.h"
#include <vector>
#include <map>

const float pixelRadius = 1.0f / 128.0f;

typedef enum {ActionNone, ActionChase, ActionChaseLikeMage, ActionChaseLikeWetMan, ActionChaseLikeRunningEye, ActionChaseLikeInvisDude, ActionRunAway, ActionBounce, ActionHide, ActionHideUnderWater, ActionStatue, ActionHangingSkeleton, ActionAttack,
              ActionRemove, ActionPlayerProjectile, ActionMonsterProjectile, ActionDropItem, ActionSpawnSkeleton, ActionForceField, ActionExplodeSound, ActionSmallMonsterSound, ActionLargeMonsterSound, ActionPortalSound, ActionBurningTree, ActionFlash, ActionHarmlessBunny,
              ActionWaitForPickup, ActionWaitForPickupDestructable, ActionFreezeTime, ActionGiveChest, ActionGiveBolt, ActionGiveNuke, ActionGivePotion,
              ActionGiveKey, ActionGiveGem, ActionGiveScroll, ActionGivePoints, ActionGivePointsForChest,
              ActionItemDestroyed, ActionExplosionDelay,
              ActionExplodeWall1,  ActionExplodeWall2,  ActionExplodeWall3, ActionExplodeWall4, ActionWarpToOtherLevel, ActionWarpInsideLevel, ActionFakeWall, ActionVictory} actorAction;
typedef enum {Always, Never, Flickering, WithBlueGem, WithRedGem, WithYellowGem, WithGreenGem, WithPurpleGem, WithAllGems} actorRadarVisibility;

typedef enum
{
    StateIdWalk,
    StateIdAttack,
    StateIdPain,
    StateIdDying,
    StateIdDead,
    StateIdHidden,
    StateIdRise,
    StateIdSink,
    StateIdPeek,
    StateIdProjectileFly,
    StateIdWaitForPickup,
    StateIdPickup,
    StateIdDecoration,
    StateIdArch,
    StateIdPeekAlternative
} DecorateStateId;

typedef struct DecorateAnimationFrame
{
    uint16_t pictureIndex;
    uint16_t durationInTics;
    actorAction action;
} DecorateAnimationFrame;

typedef std::vector<DecorateAnimationFrame> DecorateAnimation;

struct DecorateState
{
    std::vector<DecorateAnimationFrame> animation;
    DecorateStateId nextState;
};

struct DecorateActor
{
    uint16_t id;
    uint16_t spawnOnAllDifficulties;
    uint16_t spawnOnNormalAndHard;
    uint16_t spawnOnHard;
    uint16_t initialHealth;
    float size;
    actorRadarVisibility radarVisibility;
    egaColor radarColor;
    std::map<DecorateStateId, DecorateState> states;
    DecorateStateId initialState;
    uint8_t damage;
    uint16_t hitSound;
    uint16_t speed;
    uint32_t actionParameter;
    uint16_t projectileId;
};
