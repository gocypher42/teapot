#pragma once

#include <string>

using std::string;

class ProjectFile final
{
public:
  explicit ProjectFile(string file_name);

  void set_name(const std::string &name) noexcept;
  void set_content(const std::string &content) noexcept;
  [[nodiscard]] const string &get_name() const noexcept;
  [[nodiscard]] const string &get_content() const noexcept;

private:
  string m_name;
  string m_content;
};
