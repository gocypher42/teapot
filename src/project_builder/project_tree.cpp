#include "project_tree.h"
#include "directory.h"
#include <string>

using std::string;
using og::Directory;

ProjectTree::ProjectTree(const string &project_name)
  : m_origin_dir(Directory(project_name))
{}

Directory &ProjectTree::get_root() noexcept { return m_origin_dir; }

const Directory &ProjectTree::get_root() const noexcept { return m_origin_dir; }
