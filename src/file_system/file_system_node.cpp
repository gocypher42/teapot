#include "file_system_node.h"

FileSystemNode::FileSystemNode(fs::path path) : m_path(std::move(path)) {}
