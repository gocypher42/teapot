#pragma once

#include "tea_pot_args.h"

class Directory;

class TeaPot
{
public:
  explicit TeaPot(TeaPotArgs args);

  [[nodiscard]] int Run();
  [[nodiscard]] Directory GetProject() const;

private:
  TeaPotArgs m_args;
};
