#include "project_builder.h"
#include "directory.h"
#include "project_tree.h"
#include <filesystem>
#include <fmt/core.h>
#include <fstream>

namespace og {

namespace fs = std::filesystem;

void ProjectBuilder::BuildProjectTree(const ProjectTree &project_tree)
{
  BuildDirectory("", project_tree.get_root());
}

void ProjectBuilder::BuildDirectory(const fs::path &location,
  const Directory &dir)
{
  const fs::path dir_location = location / dir.get_name();
  if (!fs::create_directories(dir_location)) {
    throw std::ios_base::failure(
      fmt::format("Unable to create directory {}\n", dir_location.string()));
  }

  if (dir.get_directories().empty() && dir.get_files().empty()) { return; }

  for (const auto &directory : dir.get_directories()) {
    BuildDirectory(dir_location, directory);
  }

  for (const auto &file : dir.get_files()) { BuildFile(dir_location, file); }
}

void ProjectBuilder::BuildFile(const fs::path &location, const File &file)
{
  fmt::print("{}", file.get_content());
  const fs::path file_location = location / file.get_name();

  std::ofstream outfile;
  outfile.open(file_location);
  if (!outfile.is_open()) {
    throw std::ios_base::failure(
      fmt::format("Unable to open file {}\n", file_location.string()));
  }
  outfile << file.get_content();
  outfile.close();
}

}// namespace og
