#include "tea_pot_args_parser.h"

TeaPotArgsParser::TeaPotArgsParser() : m_program("teapot")
{
  m_program.add_argument("--verbose")
    .help("increase output verbosity")
    .default_value(false)
    .implicit_value(true);
}

bool TeaPotArgsParser::ParseArgs(int argc, char **argv)
{
  try {
    m_program.parse_args(argc, argv);
  } catch (const std::runtime_error &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << m_program;
    return false;
  }
  return true;
}

TeaPotArgs TeaPotArgsParser::GetArgs() const
{
  TeaPotArgs args;
  args.SetVerbose(m_program.get<bool>("verbose"))
    .SetProjectName("teapot__test");
  return args;
}
