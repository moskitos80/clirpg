#ifndef __STATEHOLDER__H__
#define __STATEHOLDER__H__

namespace game::potion
{
    class Subject
    {
    public:
        virtual void SetAgility(int) = 0;
        virtual void SetLucky(int) = 0;
        virtual void SetHealth(int) = 0;
        virtual void SetDamage(int) = 0;
        virtual ~Subject() = default;
    };
}

#endif  //!__STATEHOLDER__H__