#pragma once

#include <filesystem>
#include <vector>

#include "file.h"
#include "file_system_node.h"

namespace fs = std::filesystem;

using std::vector;


class Directory final : public FileSystemNode
{
public:
  explicit Directory(fs::path path) : FileSystemNode(std::move(path)) {}

  [[nodiscard]] const vector<File> &get_files() const { return m_files; }
  [[nodiscard]] const vector<Directory> &get_dir() const
  {
    return m_directories;
  }

  File &add_file(const fs::path &file_path);
  Directory &add_dir(const fs::path &file_path);

  [[nodiscard]] bool build(const fs::path &parent_path = "") const override;
  void print_tree() const;

private:
  vector<File> m_files;
  vector<Directory> m_directories;
};
