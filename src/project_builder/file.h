#pragma once

#include "node.h"
#include <string>

namespace og {

using std::string;

class File final : public Node
{
public:
  explicit File(string file_name);

  void set_content(const std::string &content) noexcept;
  [[nodiscard]] const string &get_content() const noexcept;

private:
  string m_content;
};

}// namespace og
