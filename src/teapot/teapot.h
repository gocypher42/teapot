#pragma once

#include "project_tree.h"
#include "teapot_args.h"

class Directory;

class TeaPot final
{
public:
  explicit TeaPot(TeaPotArgs args);

  [[nodiscard]] int Run() const;
  [[nodiscard]] ProjectTree MakeProject() const;

private:
  TeaPotArgs m_args;
};
