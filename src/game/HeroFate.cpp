#include <cmath>
#include <cassert>

#include "game/HeroFate.hpp"

namespace game
{
    HeroFate::HeroFate(double r, const Progression& p)
        : mPrg{ p }
        , mHpDmgRatio{ r }
    {
        assert(mHpDmgRatio > 0);
    }

    int HeroFate::baseMaxDamage(int level, double heroFactor) const
    {
        assert(level > 0);
        assert(heroFactor > 0);
        return int(baseMaxHitPoints(level, heroFactor) / mHpDmgRatio);
    }

    int HeroFate::baseMaxHitPoints(int level, double heroFactor) const
    {
        assert(level > 0);
        assert(heroFactor > 0);
        return int(std::sqrt(mPrg(level) * mHpDmgRatio) * heroFactor);
    }

    int HeroFate::experienceForLevelUp(int level) const
    {
        assert(level > 0);
        return mPrg(level);
    }
}