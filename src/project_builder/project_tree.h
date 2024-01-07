#pragma once

#include "directory.h"
#include <string>

using std::string;

class ProjectTree final
{
public:
  explicit ProjectTree(const string &project_name);

  [[nodiscard]] og::Directory &get_root() noexcept;
  [[nodiscard]] const og::Directory &get_root() const noexcept;

private:
  og::Directory m_origin_dir;
};
