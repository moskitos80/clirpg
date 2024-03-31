#ifndef __DAMAGEPOTION__H__
#define __DAMAGEPOTION__H__

#include "game/potion/BasePotion.hpp"
#include "game/potion/Subject.hpp"

namespace game::potion
{
    class DamagePotion :
        public BasePotion
    {
    public:
        using BasePotion::BasePotion;
        void Apply(Subject& cr) const override { cr.SetDamage(Value()); }
        void Cancel(Subject& cr) const override { cr.SetDamage(-Value()); }
    };
}

#endif  //!__DAMAGEPOTION__H__