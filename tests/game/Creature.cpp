#include <gtest/gtest.h>
#include <string>
#include <cmath>

#include "game/HeroFate.hpp"
#include "game/Creature.hpp"

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

TEST(Creature, Name)
{
    game::Creature cr{ theFate, "Banshi", 'o', 1, GhostHeroFactor, 20 };
    EXPECT_TRUE(cr.Name() == "Banshi");
}

TEST(Creature, Symbol)
{
    game::Creature cr{ theFate, "Banshi", 'o', 1, GhostHeroFactor, 20 };
    EXPECT_TRUE(cr.Symbol() == 'o');
}

TEST(Creature, Level)
{
    game::Creature cr{ theFate, "Banshi", 'o', 1, GhostHeroFactor, 20 };
    EXPECT_TRUE(cr.Level() == 1);
}

TEST(Creature, Gold)
{
    game::Creature cr{ theFate, "Banshi", 'o', 1, GhostHeroFactor, 20 };
    EXPECT_TRUE(cr.Gold() == 20);
    cr.SetGold(30);
    EXPECT_TRUE(cr.Gold() == 30);
    cr.AddGold(5);
    EXPECT_TRUE(cr.Gold() == 35);
}

TEST(Creature, HitPoints)
{
    game::Creature cr{ theFate, "Gooo", 'o', 1, GhostHeroFactor, 20 };
    EXPECT_TRUE(cr.HitPoints() == 7);

    cr.SetDamage(5);
    EXPECT_TRUE(cr.HitPoints() == 2);
    EXPECT_FALSE(cr.IsDead());

    cr.SetDamage(5);
    EXPECT_TRUE(cr.HitPoints() == 0);
    EXPECT_TRUE(cr.IsDead());
}

