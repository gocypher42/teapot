#include <fmt/core.h>
#include <string>

#include "templates.h"

using std::string;

string Templates::GetProjectCmakeContent(const string &project_name)
{
  return fmt::format(
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
}

string Templates::GetMainCppContent()
{
  return "#include <fmt/core.h>\n"
         "\n"
         "int main()\n"
         "{"
         "  fmt::print(\"Hello {}!\\n\", \"World\");\n"
         "  return 0;\n"
         "}\n";
}

string Templates::GetSrcCmakeContent(const string &main_cpp_file)
{
  return fmt::format(
    "add_executable(${{PROJECT_NAME}} {})\n"
    "target_link_libraries(${{PROJECT_NAME}} fmt)\n",
    main_cpp_file);
}
