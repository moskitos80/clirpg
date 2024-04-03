#ifndef __BTNODE__H__
#define __BTNODE__H__

#include <stdexcept>

namespace btree
{
    class Node
    {
    public:
        class Exception :
            public std::runtime_error
        {
        public:
            using std::runtime_error::runtime_error;
        };

        enum Status {
            Success,
            Running,
            Failure,
            Error
        };
        virtual Status exec() = 0;
        virtual ~Node() = default;
    };
}

#endif  //!__BTNODE__H__