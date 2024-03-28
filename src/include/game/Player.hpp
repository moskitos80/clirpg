#ifndef __PLAYER__H__
#define __PLAYER__H__

#include "game/Creature.hpp"

namespace game
{
    class Player :
        public Creature
    {
    public:
        using Creature::Creature;
        virtual ~Player() = default;

        // void addPotion();
    };
} // namespace game


#endif  //!__PLAYER__H__