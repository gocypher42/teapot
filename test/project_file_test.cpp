#include "project_file.h"
#include <gtest/gtest.h>

TEST(ProjectFileConstrutorTest, ValidateConstrutorWithOnlyAName)
{
  ProjectFile file("file.txt");

  EXPECT_EQ(file.get_name(), "file.txt");
  EXPECT_EQ(file.get_content(), "");
}
