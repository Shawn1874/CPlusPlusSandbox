#include "stdafx.h"
#include "gtest/gtest.h"
#include <unordered_map>
#include <string>

TEST(UnorderedMapTests, LookupTests) {

  // Create an unordered_map of three strings (that map to strings)
  std::unordered_map<std::string, std::string> colors = {
      {"RED","#FF0000"},
      {"GREEN","#00FF00"},
      {"BLUE","#0000FF"}
  };

  EXPECT_FALSE(colors.empty());
  EXPECT_EQ(colors.size(), 3);

  auto color = colors.find("BLUE");
  ASSERT_TRUE(color != colors.end());
  EXPECT_EQ(color->first, "BLUE");
  EXPECT_EQ(color->second, "#0000FF");


  color = colors.find("YELLOW");
  ASSERT_TRUE(color == colors.end());

  auto occurrences = colors.count("GREEN");
  EXPECT_EQ(occurrences, 1);
  occurrences = colors.count("VIOLET");
  EXPECT_EQ(occurrences, 0);
}

TEST(UnorderedMapTests, ArrayOperatorTest) {
  // Create an unordered_map of three strings (that map to strings)
  std::unordered_map<std::string, std::string> colors = {
      {"RED","#FF0000"},
      {"GREEN","#00FF00"},
      {"BLUE","#0000FF"}
  };

  EXPECT_EQ(colors["GREEN"], "#00FF00");
  auto value = colors["TEAL"] = "#008080";
  EXPECT_EQ(value, "#008080");
}