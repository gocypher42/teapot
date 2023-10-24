#pragma once

#include <string>

using std::string;

class ProjectFile final
{
public:
  explicit ProjectFile(string file_name) : m_name(std::move(file_name)){};

  void set_content(const std::string &content) noexcept { m_content = content; }
  [[nodiscard]] const string &get_name() const noexcept { return m_name; }

private:
  string m_name;
  string m_content;
};
