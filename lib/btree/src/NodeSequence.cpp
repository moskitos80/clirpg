#include "Node.hpp"
#include "NodeSequence.hpp"

namespace btree
{
    Node::Status NodeSequence::exec()
    {
        for (std::size_t i = mRunningNodeOffset; i < std::size(mChildren); i++) {
            mRunningNodeOffset = 0;
            switch (mChildren[i]->exec()) {
            case Node::Success:
                continue;
            case Node::Running:
                mRunningNodeOffset = i;
                return Node::Running;
            case Node::Failure:
                return Node::Failure;
            case Node::Error:
                return Node::Error;
            default:
                throw Node::Exception{ "Unknown returned status from child" };
            }
        }
        return Node::Error;
    }
} // namespace btree
