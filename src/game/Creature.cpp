#include <cassert>

#include "game/Creature.hpp"

namespace game
{
    Creature::Creature(
        const HeroFate& fate,
        std::string_view name,
        char symbol,
        int level,
        double heroFactor,
        int gold
    )
        : mFate{ fate }
        , mName{ name }
        , mSymbol{ symbol }
        , mLevel{ level }
        , mHeroFactor{ heroFactor }
        , mGold{ gold }
    {
        mMaxHitPoints = mFate.baseMaxHitPoints(mLevel, mHeroFactor);
        mExperienceGoal = mFate.experienceForLevelUp(mLevel);
        mHitPoints = mMaxHitPoints;
    }

    std::string_view Creature::Name() const
    {
        return mName;
    }

    char Creature::Symbol() const
    {
        return mSymbol;
    }

    int Creature::HitPoints() const
    {
        return mHitPoints;
    }

    int Creature::MaxHitPoints() const
    {
        return mMaxHitPoints;
    }

    bool Creature::IsDead() const
    {
        return mHitPoints == 0;
    }

    int Creature::Damage() const
    {
        return mFate.baseMaxDamage(mLevel, mHeroFactor) + mExtraDamage;
    }

    void Creature::Heal(int hp)
    {
        mHitPoints += hp;
        mHitPoints = mHitPoints > mMaxHitPoints
            ? mMaxHitPoints : mHitPoints;
    }

    void Creature::SetDamage(int hp)
    {
        mHitPoints -= hp;
        mHitPoints = mHitPoints < 0 ? 0 : mHitPoints;
    }

    void Creature::AddDamage(int d)
    {
        mExtraDamage += d;
    }

    int Creature::Experience() const
    {
        return mExperience;
    }

    int Creature::ExperienceNeed() const
    {
        return mExperienceGoal;
    }

    void Creature::SetExperience(int e)
    {
        assert(mExperienceGoal > 0);

        mExperience += e;
        while (mExperience >= mExperienceGoal) {
            mExperience %= mExperienceGoal;
            mExperienceGoal = LevelUp();
        }
    }

    int Creature::Level() const
    {
        return mLevel;
    }

    int Creature::LevelUp()
    {
        mLevel++;
        return mFate.experienceForLevelUp(mLevel);
    }

    int Creature::Gold() const
    {
        return mGold;
    }

    void Creature::SetGold(int g)
    {
        mGold = g;
    }

    void Creature::AddGold(int g)
    {
        mGold += g;
    }
}

