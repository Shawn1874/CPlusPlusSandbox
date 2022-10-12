#include "stdafx.h"
#include "gtest/gtest.h"
#include <regex>
TEST(TestRegex, TestSingleMatch) {
   std::string xml("<SIDD xmlns=\"urn:SIDD:2.0.0\" xmlns:ism=\"urn : us : gov : ic : ism : 13\"");
   std::smatch nsMatch;
   std::regex siddRegEx ("\"urn:SIDD:[0-9]\\.[0-9]\\.[0-9]\"");
   bool found = std::regex_search(xml, nsMatch, siddRegEx);
   EXPECT_TRUE(found);
   EXPECT_EQ(nsMatch.size(), 1);
   EXPECT_EQ(nsMatch[0], "\"urn:SIDD:2.0.0\"");

   xml = "<SIDD xmlns=\"urn:SIDD:1.2.3\" xmlns:ism=\"urn : us : gov : ic : ism : 13\"";
   found = std::regex_search(xml, nsMatch, siddRegEx);
   EXPECT_TRUE(found);
   EXPECT_EQ(nsMatch.size(), 1);
   EXPECT_EQ(nsMatch[0], "\"urn:SIDD:1.2.3\"");
}

/**
* std:regex classes don't provide a way to return all possible matches in
* one call so a loop is needed.  It's important to get the suffix of the 
* first match and reset the string to avoid a continuous loop.
*/
TEST(TestRegex, TestMultipleMatches) {
   std::string strr("255.254.1.2");

   std::regex rgx("([0-9]{3})");
   std::smatch match;
   size_t numMatches = 0;
   while (std::regex_search(strr, match, rgx)) {
      ++numMatches;
      strr = match.suffix();
   }
   EXPECT_EQ(numMatches, 2);
}