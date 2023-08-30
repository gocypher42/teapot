#include <filesystem>
#include <string>

#include <argparse/argparse.hpp>
#include <fmt/core.h>
#include <fmt/os.h>

#include "tea_pot.h"
#include "templates.h"

namespace fs = std::filesystem;

using std::string;

int TeaPot::Run()
{
  const string project_name = "teepot_test";
  const fs::path project_dir_path("teepot_test");
  const fs::path src_dir_path(project_dir_path / "src");
  const fs::path cmake_project_file_path(project_dir_path / "CMakeLists.txt");
  const fs::path main_cpp_file_path(src_dir_path / "main.cpp");
  const fs::path cmake_src_file_path(src_dir_path / "CMakeLists.txt");

  if (!fs::create_directories(project_dir_path)) {
    fmt::print("Unable to create project dir: {}\n", project_dir_path.string());
    return -1;
  }

  if (!fs::create_directories(src_dir_path)) {
    fmt::print("Unable to create src dir: {}\n", src_dir_path.string());
    return -1;
  }

  fmt::ostream out_cmake_project =
    fmt::output_file(cmake_project_file_path.string());
  out_cmake_project.print(
    "{}", Templates::GetProjectCmakeContent(m_args.ProjectName()));

  fmt::ostream out_cmake_src = fmt::output_file(cmake_src_file_path.string());
  out_cmake_src.print("{}",
    Templates::GetSrcCmakeContent(main_cpp_file_path.filename().string()));

  fmt::ostream out_main_cpp = fmt::output_file(main_cpp_file_path.string());
  out_main_cpp.print("{}", Templates::GetMainCppContent());


  return 0;
}
