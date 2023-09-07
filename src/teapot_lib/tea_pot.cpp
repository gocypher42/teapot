#include "tea_pot.h"
#include "directory.h"
#include "tea_pot_args.h"
#include "templates.h"
#include <fmt/core.h>

TeaPot::TeaPot(TeaPotArgs args) : m_args(std::move(args)) {}

int TeaPot::Run()
{
  const Directory project = GetProject();

  if (!project.build("")) { return -1; }

  fmt::print("\tCreated project {}.\n", m_args.ProjectName());
  return 0;
}

Directory TeaPot::GetProject() const
{
  Directory project(m_args.ProjectName());

  project.add_file("CMakeLists.txt")
    .set_content(Templates::GetProjectCmakeContent(m_args.ProjectName()));

  Directory &src = project.add_dir("src");
  src.add_file("main.cpp").set_content(Templates::GetMainCppContent());
  src.add_file("CMakeLists.txt")
    .set_content(Templates::GetSrcCmakeContent("main.cpp"));
  return project;
}
