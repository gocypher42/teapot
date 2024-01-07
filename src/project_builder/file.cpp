#include "file.h"
#include <string>

using std::string;

namespace og {

File::File(string file_name) : Node(std::move(file_name)){};

void File::set_content(const std::string &content) noexcept
{
  m_content = content;
}

const string &File::get_content() const noexcept { return m_content; }

}// namespace og
