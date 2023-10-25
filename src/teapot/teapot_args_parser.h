#pragma once

#include "teapot_args.h"
#include <argparse/argparse.hpp>
#include <string>

using std::string;

class TeaPotArgsParser final
{
public:
  TeaPotArgsParser();
  [[nodiscard]] bool ParseArgs(int argc, char **argv) noexcept;
  [[nodiscard]] TeaPotArgs GetArgs() const;

private:
  static const string VERBOSE;
  static const string PROJECT_NAME;

  argparse::ArgumentParser m_program;
};
