#include <gtest/gtest.h>
#include <cmath>

#include "game/HeroFate.hpp"

const game::HeroFate theFate{ 6, [](int level) {
        return int(std::pow(level, 0.7) * 16);
    }
};

const auto GhostHeroFactor{ 0.8 };
const auto WarriorHeroFactor{ 1 };
const auto TankHeroFactor{ 1.5 };

const auto Level_1{ 1 };
const auto Level_4{ 4 };
const auto Level_6{ 6 };

TEST(HeroFate, baseMaxHitPoints)
{
    EXPECT_EQ(theFate.baseMaxHitPoints(Level_1, GhostHeroFactor), 7);
    EXPECT_EQ(theFate.baseMaxHitPoints(Level_1, WarriorHeroFactor), 9);
    EXPECT_EQ(theFate.baseMaxHitPoints(Level_1, TankHeroFactor), 14);

    EXPECT_EQ(theFate.baseMaxHitPoints(Level_6, GhostHeroFactor), 14);
    EXPECT_EQ(theFate.baseMaxHitPoints(Level_6, WarriorHeroFactor), 18);
    EXPECT_EQ(theFate.baseMaxHitPoints(Level_6, TankHeroFactor), 27);
}

TEST(HeroFate, baseMaxDamage)
{
    EXPECT_EQ(theFate.baseMaxDamage(Level_1, GhostHeroFactor), 1);
    EXPECT_EQ(theFate.baseMaxDamage(Level_1, WarriorHeroFactor), 1);
    EXPECT_EQ(theFate.baseMaxDamage(Level_1, TankHeroFactor), 2);

    EXPECT_EQ(theFate.baseMaxDamage(Level_6, GhostHeroFactor), 2);
    EXPECT_EQ(theFate.baseMaxDamage(Level_6, WarriorHeroFactor), 3);
    EXPECT_EQ(theFate.baseMaxDamage(Level_6, TankHeroFactor), 4);
}

TEST(HeroFate, maxExperience)
{
    EXPECT_EQ(theFate.experienceForLevelUp(Level_1), 16);
    EXPECT_EQ(theFate.experienceForLevelUp(Level_4), 42);
    EXPECT_EQ(theFate.experienceForLevelUp(Level_6), 56);
}