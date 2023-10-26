#include "project_file.h"
#include <gtest/gtest.h>

TEST(ProjectFileConstrutorTest, ValidateConstrutorWithOnlyAName)
{
  ProjectFile file("file.txt");

  EXPECT_EQ(file.get_name(), "file.txt");
  EXPECT_EQ(file.get_content(), "");
}

TEST(ProjectFileNameSetterTest, ValidateSetterName)
{
  ProjectFile file("");
  file.set_name("file.txt");
  EXPECT_EQ(file.get_name(), "file.txt");
}

TEST(ProjectFileContentSetterTest, ValidateSetterContent)
{
  ProjectFile file("file.txt");
  file.set_content("content");
  EXPECT_EQ(file.get_content(), "content");
}
