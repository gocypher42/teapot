#include "teapot.h"
#include "project_builder.h"
#include "project_tree.h"
#include "teapot_args.h"
#include "templates.h"
#include <fmt/core.h>

TeaPot::TeaPot(TeaPotArgs args) : m_args(std::move(args)) {}

int TeaPot::Run() const
{
  const ProjectTree project = MakeProject();
  ProjectBuilder::BuildProjectTree(project);
  return 0;
}

ProjectTree TeaPot::MakeProject() const
{
  const string cmake_file_name = "CMakeLists.txt";

  ProjectTree project_tree(m_args.ProjectName());
  ProjectDir &root_dir = project_tree.get_root();

  ProjectFile root_cmake = root_dir.add_file(cmake_file_name);
  root_cmake.set_content(
    Templates::GetProjectCmakeContent(m_args.ProjectName()));

  ProjectDir src_dir = root_dir.add_dir("src");

  ProjectFile src_main = src_dir.add_file("main.cpp");
  src_main.set_content(Templates::GetMainCppContent());

  ProjectFile src_cmake = src_dir.add_file(cmake_file_name);
  src_cmake.set_content(Templates::GetSrcCmakeContent("main.cpp"));

  return project_tree;
}
