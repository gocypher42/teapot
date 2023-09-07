#include "tea_pot_args.h"
#include <string>

using std::string;

TeaPotArgs &TeaPotArgs::SetVerbose(bool verbose)
{
  m_verbose = verbose;
  return *this;
}

TeaPotArgs &TeaPotArgs::SetProjectName(const string &project_name)
{
  m_project_name = project_name;
  return *this;
}
