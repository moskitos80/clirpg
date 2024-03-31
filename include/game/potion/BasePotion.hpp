#ifndef __BASEPOTION__H__
#define __BASEPOTION__H__

#include <string_view>
#include <string>

#include "game/potion/Subject.hpp"

namespace game::potion
{
    class BasePotion
    {
        std::string mName{};
        int mValue{};
        int mTurnCount{};

    public:
        explicit BasePotion(std::string_view name, int value, int turnCount)
            : mName{ name }
            , mValue{ value }
            , mTurnCount{ turnCount }
        {}

        int Turn()
        {
            --mTurnCount;
            return mTurnCount;
        }

        virtual void Apply(Subject& cr) const = 0;
        virtual void Cancel(Subject& cr) const = 0;

        virtual int Value() const { return mValue; }
        virtual std::string_view Name() const { return mName; }

        virtual ~BasePotion() = default;
    };
} // namespace game::potion


#endif  //!__BASEPOTION__H__