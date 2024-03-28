#include <gtest/gtest.h>
#include <string>
#include <cmath>

#include "game/Player.hpp"
#include "game/Creature.hpp"

const game::HeroFate theFate{ 6, [](int level) {
        return int(std::pow(level, 0.7) * 16);
    }
};

TEST(Player, Construct)
{
    game::Player pl{ theFate, "Moskitos", '@', 1, 1.5, 0 };

    EXPECT_EQ(pl.Name(), "Moskitos");
    EXPECT_EQ(pl.Symbol(), '@');
}