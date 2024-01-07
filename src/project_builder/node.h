#pragma once

#include <string>

namespace og {

class Node
{
public:
  explicit Node(std::string name) : m_name(std::move(name)) {}

  void set_name(const std::string &name) noexcept;
  [[nodiscard]] const std::string &get_name() const noexcept;

private:
  std::string m_name;
};

}// namespace og
