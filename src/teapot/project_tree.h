#pragma once

#include "project_dir.h"
#include "project_file.h"
#include <string>

using std::string;

class ProjectTree final
{
public:
  explicit ProjectTree(const string &project_name);

  [[nodiscard]] ProjectDir &get_root() noexcept;
  [[nodiscard]] const ProjectDir &get_root() const noexcept;
private:
  ProjectDir m_origin_dir;
};
