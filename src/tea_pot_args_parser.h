#pragma once

#include <argparse/argparse.hpp>

#include "tea_pot_args.h"

class TeaPotArgsParser
{
public:
  TeaPotArgsParser();
  [[nodiscard]] bool ParseArgs(int argc, char **argv);
  [[nodiscard]] TeaPotArgs GetArgs() const;

private:
  argparse::ArgumentParser m_program;
};
