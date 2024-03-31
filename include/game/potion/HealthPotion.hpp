#ifndef __DAMAGEPOTION__H__
#define __DAMAGEPOTION__H__

#include "game/potion/BasePotion.hpp"
#include "game/potion/Subject.hpp"

namespace game::potion
{
    class HealthPotion :
        public BasePotion
    {
    public:
        using BasePotion::BasePotion;
        void Apply(Subject& cr) const override { cr.SetHealth(Value()); }
        void Cancel(Subject& cr) const override { /* EMPTY */ }
    };
}

#endif  //!__DAMAGEPOTION__H__