#pragma once

#include "directory.h"
#include "file.h"
#include "project_tree.h"
#include <filesystem>

namespace og {

namespace fs = std::filesystem;

class ProjectBuilder final
{
public:
  ProjectBuilder() = delete;

  static void BuildProjectTree(const ProjectTree &project_tree);

private:
  static void BuildDirectory(const fs::path &location, const Directory &dir);
  static void BuildFile(const fs::path &location, const File &file);
};

}// namespace og
