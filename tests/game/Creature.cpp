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
    game::Creature cr{ theFate, "Namer", 'o', Level_1, GhostHeroFactor, 20 };
    EXPECT_TRUE(cr.Name() == "Namer");
}

TEST(Creature, Symbol)
{
    game::Creature cr{ theFate, "Symboler", 'o', Level_1, GhostHeroFactor, 20 };
    EXPECT_TRUE(cr.Symbol() == 'o');
}

TEST(Creature, Level)
{
    game::Creature cr{ theFate, "Leveler", 'o', Level_1, GhostHeroFactor, 20 };
    EXPECT_TRUE(cr.Level() == Level_1);
}

TEST(Creature, Gold)
{
    game::Creature cr{ theFate, "Goldberg", 'o', Level_1, GhostHeroFactor, 20 };
    EXPECT_TRUE(cr.Gold() == 20);
    cr.SetGold(30);
    EXPECT_TRUE(cr.Gold() == 30);
    cr.AddGold(5);
    EXPECT_TRUE(cr.Gold() == 35);
}

TEST(Creature, HitPoints_MaxHitPoints)
{
    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_1, GhostHeroFactor, 20 };
        EXPECT_EQ(cr.HitPoints(), 7);
        EXPECT_EQ(cr.MaxHitPoints(), 7);
    }

    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_1, WarriorHeroFactor, 20 };
        EXPECT_EQ(cr.HitPoints(), 9);
        EXPECT_EQ(cr.MaxHitPoints(), 9);
    }

    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_1, TankHeroFactor, 20 };
        EXPECT_EQ(cr.HitPoints(), 14);
        EXPECT_EQ(cr.MaxHitPoints(), 14);
    }
}

TEST(Creature, Experience_ExperienceNeed)
{
    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_1, GhostHeroFactor, 20 };
        EXPECT_EQ(cr.Experience(), 0);
        EXPECT_EQ(cr.ExperienceNeed(), 16);
    }

    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_4, WarriorHeroFactor, 20 };
        EXPECT_EQ(cr.Experience(), 0);
        EXPECT_EQ(cr.ExperienceNeed(), 42);
    }

    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_6, TankHeroFactor, 20 };
        EXPECT_EQ(cr.Experience(), 0);
        EXPECT_EQ(cr.ExperienceNeed(), 56);
    }
}

TEST(Creature, Damage)
{
    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_6, GhostHeroFactor, 20 };
        EXPECT_EQ(cr.Damage(), 2);
    }

    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_6, WarriorHeroFactor, 20 };
        EXPECT_EQ(cr.Damage(), 3);
    }

    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_6, TankHeroFactor, 20 };
        EXPECT_EQ(cr.Damage(), 4);
    }
}

TEST(Creature, SetDamage)
{
    {
        game::Creature cr{ theFate, "HitPointer", 'o', Level_1, GhostHeroFactor, 20 };
        cr.SetDamage(5);
        EXPECT_EQ(cr.HitPoints(), 2);

        cr.SetDamage(10);
        EXPECT_EQ(cr.HitPoints(), 0);
    }
}

TEST(Creature, IsDead)
{
    game::Creature cr{ theFate, "HitPointer", 'o', Level_1, GhostHeroFactor, 20 };
    cr.SetDamage(5);
    EXPECT_FALSE(cr.IsDead());

    cr.SetDamage(10);
    EXPECT_TRUE(cr.IsDead());
}

TEST(Creature, Experience_LevelUp)
{
    game::Creature cr{ theFate, "HitPointer", 'o', Level_1, GhostHeroFactor, 20 };

    EXPECT_EQ(cr.Experience(), 0);
    EXPECT_EQ(cr.ExperienceNeed(), 16);

    cr.SetExperience(10);
    EXPECT_EQ(cr.Experience(), 10);
    EXPECT_EQ(cr.ExperienceNeed(), 16);

    EXPECT_EQ(cr.Level(), 1);
}

TEST(Creature, Experience_LevelUp_Overflow)
{
    game::Creature cr{ theFate, "HitPointer", 'o', Level_1, GhostHeroFactor, 20 };

    EXPECT_EQ(cr.Experience(), 0);
    EXPECT_EQ(cr.ExperienceNeed(), 16);

    cr.SetExperience(20);
    EXPECT_EQ(cr.Experience(), 4);
    EXPECT_EQ(cr.ExperienceNeed(), 25);

    EXPECT_EQ(cr.Level(), 2);
}