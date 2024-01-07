#include "directory.h"
#include "file.h"
#include <algorithm>
#include <fmt/core.h>
#include <stdexcept>
#include <string>
#include <vector>

namespace og {

using std::vector;
using std::string;
using og::File;

Directory::Directory(std::string name) : Node(std::move(name)) {}

File &Directory::add_file(const std::string &file_name)
{
  const auto existing_file = std::find_if(m_files.cbegin(),
    m_files.cend(),
    [&file_name](const File &file) { return file.get_name() == file_name; });

  if (existing_file != m_files.cend()) {
    throw std::invalid_argument(
      fmt::format("ProjectFile {} already exists inside ProjectDir {}",
        file_name,
        get_name()));
  }

  m_files.emplace_back(file_name);
  return m_files.back();
}

Directory &Directory::add_dir(const std::string &dir_name)
{
  const auto existing_dir = std::find_if(m_directories.cbegin(),
    m_directories.cend(),
    [&dir_name](const Directory &dir) { return dir.get_name() == dir_name; });

  if (existing_dir != m_directories.cend()) {
    throw std::invalid_argument(
      fmt::format("ProjectDir {} already exists inside ProjectDir {}",
        dir_name,
        get_name()));
  }

  m_directories.emplace_back(dir_name);
  return m_directories.back();
}

const vector<Directory> &Directory::get_directories() const noexcept
{
  return m_directories;
}

const vector<File> &Directory::get_files() const noexcept { return m_files; }

}// namespace og
