#pragma once

#include <string>

using std::string;

class TeaPotArgs final
{
public:
  TeaPotArgs() = default;

  TeaPotArgs &SetVerbose(bool verbose);
  TeaPotArgs &SetProjectName(const string &m_project_name);

  [[nodiscard]] const string &ProjectName() const noexcept;

private:
  bool m_verbose = false;
  string m_project_name;
};
