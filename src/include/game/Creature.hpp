#ifndef __CREATURE__H__
#define __CREATURE__H__

#include <string_view>
#include <string>

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
        Creature();
        virtual ~Creature() = default;

        virtual std::string_view Name() const;
        virtual void SetName(std::string_view);

        virtual char Symbol() const;
        virtual void SetSymbol(char);

        virtual void Heal(int) const;
        virtual int HitPoints() const;
        virtual bool IsDead() const;
        virtual int Damage() const;

        virtual void SetDamage(int);

        virtual int Experience() const;
        virtual void SetExperience(int) const;

        virtual int Level() const;
        virtual void UpLevel(int);

        virtual int Gold() const;
        virtual void SetGold(int);

    private:
        std::string mName{};
        char mSymbol{ '@' };

        int mHitPoints{};
        int mMaxHitPoints{};

        int mLevel{};
        int mExperience{};
        int mExperienceGoal{};

        int mGold{};
    };
}

#endif  //!__CREATURE__H__