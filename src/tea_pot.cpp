#include <filesystem>
#include <memory>
#include <string>

#include <argparse/argparse.hpp>
#include <fmt/core.h>
#include <fmt/os.h>
#include <utility>

#include "tea_pot.h"
#include "templates.h"

namespace fs = std::filesystem;

using std::string;

class ProjectNode
{
public:
  explicit ProjectNode() = default;
  ProjectNode(const ProjectNode &) = default;
  ProjectNode(ProjectNode &&) = delete;
  ProjectNode &operator=(const ProjectNode &) = default;
  ProjectNode &operator=(ProjectNode &&) = delete;

  virtual ~ProjectNode() = default;
  virtual void build_node() const = 0;

  void set_path(fs::path path) { m_path = std::move(path); }

  [[nodiscard]] const std::filesystem::path &get_path() const { return m_path; }

private:
  std::filesystem::path m_path;
};

class ProjectFile final : public ProjectNode
{
public:
  ProjectFile() = default;

  void build_node() const override{};

private:
  std::string m_content;
};

class ProjectDirectory final : public ProjectNode
{
public:
  explicit ProjectDirectory(const fs::path &path)
  {
    if (fs::is_directory(path)) { throw std::invalid_argument(""); }
    set_path(path);
  }

  void build_node() const override
  {
    const fs::path &path = get_path();
    if (!fs::create_directories(path)) {
      fmt::print("Unable to create src dir: {}\n", path.string());
      return;
    }

    for (const auto &child : m_childs) {
      if (!child) { continue; }
      child->build_node();
    }
  }

private:
};


class Project
{
public:
  explicit Project(std::shared_ptr<ProjectDirectory> root)
    : m_root(std::move(root))
  {}

  void build_project() const
  {
    if (!m_root) { return; }
    m_root->build_node();
  };

private:
  std::shared_ptr<ProjectDirectory> m_root;
};


int TeaPot::Run()
{
  const fs::path project_dir_path("teepot_test");

  const auto root = std::make_shared<ProjectDirectory>("teepot_test");
  root->add_child(std::make_shared<ProjectDirectory>("src"));
  const Project project(root);

  const fs::path src_dir_path(project_dir_path / "src");
  const fs::path cmake_project_file_path(project_dir_path / "CMakeLists.txt");
  const fs::path main_cpp_file_path(src_dir_path / "main.cpp");
  const fs::path cmake_src_file_path(src_dir_path / "CMakeLists.txt");

  project.build_project();

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
