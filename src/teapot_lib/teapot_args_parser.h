#pragma once

#include "teapot_args.h"
#include <argparse/argparse.hpp>

class TeaPotArgsParser
{
public:
  TeaPotArgsParser();
  [[nodiscard]] bool ParseArgs(int argc, char **argv) noexcept;
  [[nodiscard]] TeaPotArgs GetArgs() const;

private:
  argparse::ArgumentParser m_program;
};
