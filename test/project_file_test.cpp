#include "file.h"
#include <gtest/gtest.h>

using og::File;

TEST(FileConstrutorTest, ValidateConstrutorWithOnlyAName)
{
  File file("file.txt");

  EXPECT_EQ(file.get_name(), "file.txt");
  EXPECT_EQ(file.get_content(), "");
}

TEST(FileNameSetterTest, ValidateSetterName)
{
  File file("");
  file.set_name("file.txt");
  EXPECT_EQ(file.get_name(), "file.txt");
}

TEST(FileContentSetterTest, ValidateSetterContent)
{
  File file("file.txt");
  file.set_content("content");
  EXPECT_EQ(file.get_content(), "content");
}
