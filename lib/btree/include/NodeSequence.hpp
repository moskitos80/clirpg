#ifndef __NODESEQUENCE__H__
#define __NODESEQUENCE__H__

#include <vector>
#include <memory>
#include <cstddef>

#include "Node.hpp"

namespace btree
{
    class NodeSequence : public Node
    {
    public:
        Status exec();
    private:
        std::size_t mRunningNodeOffset{ 0 };
        std::vector<std::unique_ptr<Node>> mChildren{};
    };
} // namespace btree


#endif  //!__NODESEQUENCE__H__