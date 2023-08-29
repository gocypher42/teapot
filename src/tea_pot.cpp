#include <filesystem>
#include <string>

#include <fmt/core.h>
#include <fmt/os.h>

#include "tea_pot.h"

namespace fs = std::filesystem;

using std::string;


int TeaPot::Run(int /*argc*/, char ** /*argv*/)
{

  const string project_name = "teepot_test";
  const fs::path project_dir_path("teepot_test");
  const fs::path src_dir_path(project_dir_path / "src");
  const fs::path cmake_project_file_path(project_dir_path / "CMakeLists.txt");
  const string cmake_project_file_content = fmt::format(
    "cmake_minimum_required(VERSION 3.15)\n"
    "\n"
    "project({}\n"
    "        LANGUAGES CXX\n"
    "        VERSION 1.0)\n"
    "\n"
    "set(CMAKE_CXX_STANDARD 17)\n"
    "set(CMAKE_EXPORT_COMPILE_COMMANDS ON)\n"
    "set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${{CMAKE_BINARY_DIR}}/lib)\n"
    "set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${{CMAKE_BINARY_DIR}}/lib)\n"
    "set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${{CMAKE_BINARY_DIR}}/bin)\n"
    "\n"
    "if ( CMAKE_COMPILER_IS_GNUCC )\n"
    "    set(CMAKE_CXX_FLAGS  \"${{CMAKE_CXX_FLAGS}} -Wall -Wextra\")\n"
    "endif()\n"
    "if ( MSVC )\n"
    "    set(CMAKE_CXX_FLAGS  \"${{CMAKE_CXX_FLAGS}} /W4\")\n"
    "endif()\n"
    "include(FetchContent)\n"
    "\n"
    "FetchContent_Declare(fmt\n"
    "                     GIT_REPOSITORY https://github.com/fmtlib/fmt.git\n"
    "                     GIT_TAG 10.1.1)\n"
    "FetchContent_MakeAvailable(fmt)\n"
    "\n"
    "add_subdirectory(src)\n",
    project_name);
  const fs::path main_cpp_file_path(src_dir_path / "main.cpp");
  const string main_cpp_file_content =
    "#include <fmt/core.h>\n"
    "\n"
    "int main()\n"
    "{"
    "  fmt::print(\"Hello {}!\\n\", \"World\");\n"
    "  return 0;\n"
    "}\n";

  const fs::path cmake_src_file_path(src_dir_path / "CMakeLists.txt");
  const string cmake_src_file_content = fmt::format(
    "add_executable(${{PROJECT_NAME}} {})\n"
    "target_link_libraries(${{PROJECT_NAME}} fmt)\n",
    main_cpp_file_path.filename().string());

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
  out_cmake_project.print("{}", cmake_project_file_content);

  fmt::ostream out_main_cpp = fmt::output_file(main_cpp_file_path.string());
  out_main_cpp.print("{}", main_cpp_file_content);

  fmt::ostream out_cmake_src = fmt::output_file(cmake_src_file_path.string());
  out_cmake_src.print("{}", cmake_src_file_content);

  return 0;
}
