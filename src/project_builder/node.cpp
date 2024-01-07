#include "node.h"

namespace og {

using std::string;

void Node::set_name(const string &name) noexcept { m_name = name; }

const string &Node::get_name() const noexcept { return m_name; }

}// namespace og
