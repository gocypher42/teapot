#include "project_dir.h"
#include "project_file.h"
#include <algorithm>
#include <fmt/core.h>
#include <string>
#include <vector>
#include <stdexcept>

using std::vector;
using std::string;

ProjectDir::ProjectDir(std::string name) : m_name(std::move(name)) {}

const string &ProjectDir::get_name() const noexcept { return m_name; }

ProjectFile &ProjectDir::add_file(const std::string &file_name)
{
  const auto existing_file = std::find_if(
    m_files.cbegin(), m_files.cend(), [&file_name](const ProjectFile &file) {
      return file.get_name() == file_name;
    });

  if (existing_file != m_files.cend()) {
    throw std::invalid_argument(fmt::format(
      "ProjectFile {} already exists inside ProjectDir {}", file_name, m_name));
  }

  m_files.emplace_back(file_name);
  return m_files.back();
}

ProjectDir &ProjectDir::add_dir(const std::string &dir_name)
{
  const auto existing_dir = std::find_if(m_directories.cbegin(),
    m_directories.cend(),
    [&dir_name](const ProjectDir &dir) { return dir.get_name() == dir_name; });

  if (existing_dir != m_directories.cend()) {
    throw std::invalid_argument(fmt::format(
      "ProjectDir {} already exists inside ProjectDir {}", dir_name, m_name));
  }

  m_directories.emplace_back(dir_name);
  return m_directories.back();
}

const vector<ProjectDir> &ProjectDir::get_directories() const noexcept
{
  return m_directories;
}

const vector<ProjectFile> &ProjectDir::get_files() const noexcept
{
  return m_files;
}
