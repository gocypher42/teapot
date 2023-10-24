#pragma once

#include "project_dir.h"
#include "project_file.h"
#include <string>

using std::string;

class ProjectTree final
{
public:
  explicit ProjectTree(const string &project_name)
    : m_origin_dir(ProjectDir(project_name))
  {}

  [[nodiscard]] ProjectDir &get_root() noexcept { return m_origin_dir; }

private:
  ProjectDir m_origin_dir;
};

