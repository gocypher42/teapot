#pragma once

#include "tea_pot_args.h"

class TeaPot
{
public:
  explicit TeaPot(const TeaPotArgs &args) : m_args(args) {}
  [[nodiscard]] int Run();

private:
  TeaPotArgs m_args;
};
