#ifndef __PATIENT__H__
#define __PATIENT__H__

namespace game
{
    class Patient
    {
    public:
        virtual void Heal(int hp) = 0;
    };
} // namespace game


#endif  //!__PATIENT__H__