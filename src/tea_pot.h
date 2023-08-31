#pragma once

#include "tea_pot_args.h"

class TeaPot
{
public:
  explicit TeaPot(TeaPotArgs args) : m_args(std::move(args)) {}
  [[nodiscard]] int Run();

private:
  TeaPotArgs m_args;
};
