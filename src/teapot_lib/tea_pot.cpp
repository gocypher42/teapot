#include "tea_pot.h"
#include "directory.h"
#include "templates.h"

#include <fmt/core.h>

int TeaPot::Run()
{
  Directory root(m_args.ProjectName());

  root.add_file("CMakeLists.txt")
    .set_content(Templates::GetProjectCmakeContent(m_args.ProjectName()));

  Directory &src = root.add_dir("src");
  src.add_file("main.cpp").set_content(Templates::GetMainCppContent());
  src.add_file("CMakeLists.txt")
    .set_content(Templates::GetSrcCmakeContent("main.cpp"));

  if (!root.build()) { return -1; }

  fmt::print("\tCreated project {}.\n", m_args.ProjectName());
  return 0;
}
