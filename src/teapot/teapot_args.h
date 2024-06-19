#pragma once

#include <string>

class TeaPotArgs final
{
public:
  TeaPotArgs &SetVerbose(bool verbose);
  TeaPotArgs &SetProjectName(const std::string &m_project_name);

  [[nodiscard]] const std::string &ProjectName() const noexcept;

private:
  bool m_verbose = false;
  std::string m_project_name;
};
