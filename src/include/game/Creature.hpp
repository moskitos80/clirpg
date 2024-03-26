#ifndef __CREATURE__H__
#define __CREATURE__H__

#include <string_view>
#include <string>

#include "game/HeroFate.hpp"

namespace game
{
    /*
        https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/

        Имеет уровень Level

        Имеет наносимый урон Damage
        Имеет жизненные силы HitPoints
        Имеет Накопленный опыт Experience
        Имеет накопленное количество золота Gold

        Уровень диктует верхнее значение жизненных сил MaxHitPoints
        Уровень диктует верхнее значение наносимого урона Damage
        Уровень диктует следующие целевое значение накопления опыта ExperienceGoal

        Можно узнать количество здоровья
        Можно узнать, наносим урон
        Можно узнать жив или мёртв
        Можно узнать количество опыта
        Можно узнать количество золота
        Можно узнать количество оставшгося опыта до повышения уровня

        Можно повысить уровень
        Можно лечить добавив, количество здоровья
        Можно наносить урон, снимая количество здоровья
        Можно добавить количество золота

        * Количество опыта требуемого для повышения до
            следующего уровня вычисляется согласно базовой прогрессии
    */
    class Creature
    {
    public:
        Creature(
            const HeroFate& fate,
            std::string_view name,
            char symbol,
            int level = 1,
            double heroFactor = 1,
            int gold = 0
        );
        virtual ~Creature() = default;

        virtual std::string_view Name() const;
        virtual char Symbol() const;

        virtual int HitPoints() const;
        virtual int MaxHitPoints() const;
        virtual bool IsDead() const;
        virtual int Damage() const;

        virtual void Heal(int);
        virtual void SetDamage(int);

        virtual int Experience() const;
        virtual void SetExperience(int);

        virtual int Level() const;
        virtual int LevelUp();

        virtual int Gold() const;
        virtual void SetGold(int);
        virtual void AddGold(int);

    private:
        const HeroFate& mFate;

        std::string mName{};
        char mSymbol{ '@' };

        int mHitPoints{};
        int mMaxHitPoints{};

        int mLevel{};
        int mExperience{};
        int mExperienceGoal{};

        double mHeroFactor{};
        int mGold{};
    };
}

#endif  //!__CREATURE__H__