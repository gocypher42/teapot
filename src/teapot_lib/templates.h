#pragma once

#include <string>

using std::string;

class Templates final
{
public:
  Templates() = delete;

  static string GetProjectCmakeContent(const string &project_name);
  static string GetMainCppContent();
  static string GetSrcCmakeContent(const string &main_cpp_file);
};
