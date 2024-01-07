#pragma once

#include "file.h"
#include "node.h"
#include <string>
#include <vector>

namespace og {

using std::vector;
using std::string;

class Directory final : public Node
{
public:
  explicit Directory(std::string name);

  [[nodiscard]] og::File &add_file(const std::string &file_name);
  [[nodiscard]] Directory &add_dir(const std::string &dir_name);
  [[nodiscard]] const vector<Directory> &get_directories() const noexcept;
  [[nodiscard]] const vector<og::File> &get_files() const noexcept;

private:
  vector<Directory> m_directories;
  vector<og::File> m_files;
};

}// namespace og
