#include "project_file.h"
#include <string>

using std::string;

ProjectFile::ProjectFile(string file_name) : m_name(std::move(file_name)){};

void ProjectFile::set_content(const std::string &content) noexcept
{
  m_content = content;
}

const string &ProjectFile::get_name() const noexcept { return m_name; }

const string &ProjectFile::get_content() const noexcept { return m_content; }
