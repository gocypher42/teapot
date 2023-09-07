#include "file.h"
#include <fmt/os.h>

bool File::build(const fs::path &parent_path) const
{
  const fs::path current_path = parent_path / get_path();
  fmt::ostream out_cmake_project = fmt::output_file(current_path.string());
  out_cmake_project.print("{}", m_content);
  return true;
}
