#include "project_tree.h"
#include "project_dir.h"
#include <string>

using std::string;

ProjectTree::ProjectTree(const string &project_name)
  : m_origin_dir(ProjectDir(project_name))
{}

ProjectDir &ProjectTree::get_root() noexcept { return m_origin_dir; }

const ProjectDir &ProjectTree::get_root() const noexcept
{
  return m_origin_dir;
}
