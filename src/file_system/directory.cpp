#include "directory.h"

#include <algorithm>
#include <fmt/core.h>

File &Directory::add_file(const fs::path &file_path)
{
  m_files.emplace_back(file_path);
  return m_files.back();
}

Directory &Directory::add_dir(const fs::path &file_path)
{
  m_directories.emplace_back(file_path);
  return m_directories.back();
}

bool Directory::build(const fs::path &parent_path) const
{
  const fs::path current_path = parent_path / get_path();

  if (!fs::create_directories(current_path)) {
    fmt::print("unable to create directory {}\n", current_path.string());
    return false;
  }

  const auto build_node = [&current_path](const FileSystemNode &node) {
    return node.build(current_path);
  };

  return std::all_of(m_directories.cbegin(), m_directories.cend(), build_node)
         && std::all_of(m_files.cbegin(), m_files.cend(), build_node);
}
