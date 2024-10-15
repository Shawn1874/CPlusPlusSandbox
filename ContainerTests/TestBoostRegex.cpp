#include "stdafx.h"
#include "gtest/gtest.h"
#include <boost/regex.hpp>
#include <string>

TEST(TestBoostregex, TestLookbehindIterator) {
   std::string testStr("FOO:123   ");
   boost::smatch matches;
   boost::regex expr("^[A-Za-z]+:[0-9]+\\s*(?<=^.{10})");
   bool found = boost::regex_search(testStr, matches, expr);
   EXPECT_TRUE(found);
   EXPECT_EQ(1, matches.size());  // fails and shows 3 instead
   EXPECT_EQ(testStr, matches[0]);

   testStr = "bar:56789    ";
   std::string toMatch("bar:56789 ");
   found = boost::regex_search(testStr, matches, expr);
   EXPECT_TRUE(found);
   EXPECT_EQ(1, matches.size());  // fails and shows 3 instead
   EXPECT_EQ(toMatch, matches[0]);
}

TEST(TestBoostregex, TestLookbehind) {
   std::string testStr("FOO:123   ");
   boost::regex expr("^[A-Za-z]+:[0-9]+\\s*(?<=^.{10})");
   bool found = boost::regex_search(testStr, expr);
   EXPECT_TRUE(found);

   testStr = "A:34567890";
   found = boost::regex_search(testStr, expr);
   EXPECT_TRUE(found);

   testStr = "FOOBAR:003";
   found = boost::regex_search(testStr, expr);
   EXPECT_TRUE(found);

   testStr = "FOOBAR:01       ";
   found = boost::regex_search(testStr, expr);
   EXPECT_TRUE(found);

   testStr = "A1:3456789";
   found = boost::regex_search(testStr, expr);
   EXPECT_FALSE(found);

   testStr = "BAR:3456 123";
   found = boost::regex_search(testStr, expr);
   EXPECT_FALSE(found);
}

TEST(TestBoostregex, TestMatchResults) {
   const std::string pattern = "(abc)(def)";
   const std::string target = "abcdef"; 
   boost::regex regexPattern(pattern, boost::regex::extended);
   boost::smatch what;

   bool isMatchFound = boost::regex_match(target, what, regexPattern);
   EXPECT_TRUE(isMatchFound);
   std::string match(what[0]);
   EXPECT_EQ(target, what[0]);
}