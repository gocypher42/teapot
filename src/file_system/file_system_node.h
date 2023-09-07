#pragma once

#include <filesystem>

namespace fs = std::filesystem;

class FileSystemNode
{
public:
  explicit FileSystemNode(fs::path path);
  virtual ~FileSystemNode() = default;
  FileSystemNode(const FileSystemNode &) = default;
  FileSystemNode(FileSystemNode &&) = delete;
  FileSystemNode &operator=(const FileSystemNode &) = default;
  FileSystemNode &operator=(FileSystemNode &&) = delete;

  [[nodiscard]] const fs::path &get_path() const { return m_path; }

  [[nodiscard]] virtual bool build(const fs::path &parent_path) const = 0;

private:
  fs::path m_path;
};
