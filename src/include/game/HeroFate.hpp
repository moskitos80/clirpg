#ifndef __HEROFATE__H__
#define __HEROFATE__H__

#include <functional>

namespace game
{
    class HeroFate
    {
        using Progression = std::function<int(int)>;

    public:
        HeroFate(double hpDmgRatio, const Progression& progression);

        int baseMaxDamage(int level, double heroFactor) const;
        int baseMaxHitPoints(int level, double heroFactor) const;
        int experienceForLevelUp(int level) const;

    private:
        Progression mPrg;
        double mHpDmgRatio;
    };
}

#endif  //!__HEROFATE__H__