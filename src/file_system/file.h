#pragma once

#include "file_system_node.h"
#include <filesystem>

namespace fs = std::filesystem;

class File final : public FileSystemNode
{
public:
  explicit File(fs::path path) : FileSystemNode(std::move(path)) {}

  void set_content(const std::string &content) { m_content = content; }

  [[nodiscard]] bool build(const fs::path &parent_path) const override;

private:
  std::string m_content;
};
