#include "tea_pot_args_parser.h"

const string VERBOSE = "verbose";
const string PROJECT_NAME = "project-name";

TeaPotArgsParser::TeaPotArgsParser() : m_program("teapot")
{
  m_program.add_argument("-p", "--" + PROJECT_NAME)
    .required()
    .metavar("PROJECT_NAME")
    .help("Project Name");

  m_program.add_argument("--" + VERBOSE)
    .help("increase output verbosity")
    .default_value(false)
    .implicit_value(true);
}

bool TeaPotArgsParser::ParseArgs(int argc, char **argv) noexcept
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
  args.SetVerbose(m_program.get<bool>(VERBOSE))
    .SetProjectName(m_program.get<string>(PROJECT_NAME));
  return args;
}
