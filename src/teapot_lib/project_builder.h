#pragma once

#include "project_tree.h"

class ProjectBuilder final
{
public:
  ProjectBuilder() = delete;
  static void BuildProjectTree(const ProjectTree &project_tree) {}
};
