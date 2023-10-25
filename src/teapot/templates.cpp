#include "templates.h"
// #include "directory.h"
#include <fmt/core.h>
#include <numeric>
#include <string>
#include <vector>

using std::vector;
using std::accumulate;
using std::string;

namespace {

string Join(const vector<string> &strings, const string &separator)
{
  return accumulate(strings.begin(),
    strings.end(),
    string(""),
    [&separator](const string &accumulation, const string &item) {
      return accumulation + item + separator;
    });
}

string JoinWithNewLines(const vector<string> &strings)
{
  return Join(strings, "\n");
}

}// namespace

string Templates::GetProjectCmakeContent(const string &project_name)
{
  const vector<string> content = {
    "cmake_minimum_required(VERSION 3.15)",
    "",
    "project({}",
    "        LANGUAGES CXX",
    "        VERSION 1.0)",
    "",
    "set(CMAKE_CXX_STANDARD 17)",
    "set(CMAKE_EXPORT_COMPILE_COMMANDS ON)",
    "set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${{CMAKE_BINARY_DIR}}/lib)",
    "set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${{CMAKE_BINARY_DIR}}/lib)",
    "set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${{CMAKE_BINARY_DIR}}/bin)",
    "",
    "if (CMAKE_COMPILER_IS_GNUCC)",
    "    set(CMAKE_CXX_FLAGS  \"${{CMAKE_CXX_FLAGS}} -Wall -Wextra\")",
    "endif()",
    "if (MSVC)",
    "    set(CMAKE_CXX_FLAGS  \"${{CMAKE_CXX_FLAGS}} /W4\")",
    "endif()",
    "",
    "include(FetchContent)",
    "",
    "FetchContent_Declare(fmt",
    "                     GIT_REPOSITORY https://github.com/fmtlib/fmt.git",
    "                     # GIT_TAG [PLACE YOUR GIT TAG]",
    ")",
    "FetchContent_MakeAvailable(fmt)",
    "",
    "add_subdirectory(src)",
  };

  return fmt::format(JoinWithNewLines(content), project_name);
}

string Templates::GetMainCppContent()
{
  const vector<string> content = {
    "#include <fmt/core.h>",
    "",
    "int main()",
    "{",
    R"(  fmt::print("Hello {}!\n", "World");)",
    "  return 0;",
    "}",
  };
  return Join(content, "\n");
}

string Templates::GetSrcCmakeContent(const string &main_cpp_file)
{
  vector<string> content = {
    "add_executable(${{PROJECT_NAME}} {})",
    "target_link_libraries(${{PROJECT_NAME}} fmt)",
  };
  return fmt::format(Join(content, "\n"), main_cpp_file);
}
