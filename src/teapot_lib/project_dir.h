#pragma once

#include "project_file.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

class ProjectDir final
{
public:
  explicit ProjectDir(std::string name);

  [[nodiscard]] const string &get_name() const noexcept;
  [[nodiscard]] ProjectFile &add_file(const std::string &file_name);
  [[nodiscard]] ProjectDir &add_dir(const std::string &dir_name);
  [[nodiscard]] const vector<ProjectDir> &get_directories() const noexcept;
  [[nodiscard]] const vector<ProjectFile> &get_files() const noexcept;

private:
  string m_name;
  vector<ProjectDir> m_directories;
  vector<ProjectFile> m_files;
};
