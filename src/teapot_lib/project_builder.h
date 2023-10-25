#pragma once

#include "project_dir.h"
#include "project_file.h"
#include "project_tree.h"
#include <filesystem>

namespace fs = std::filesystem;

class ProjectBuilder final
{
public:
  ProjectBuilder() = delete;

  static void BuildProjectTree(const ProjectTree &project_tree);
  static void BuildDirectory(const fs::path &location, const ProjectDir &dir);
  static void BuildFile(const fs::path &location, const ProjectFile &file);
};
