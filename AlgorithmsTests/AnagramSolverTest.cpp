#include "stdafx.h"
#include "gtest/gtest.h"
#include "AnagramSolver.h"
#include <iostream>

using std::deque;
using std::unordered_map;
using std::string;

TEST(AnagramSolverTest, isAnagramTest) {

  EXPECT_TRUE(AnagramSolver::isAnagram("nap", "pan"));
  EXPECT_TRUE(AnagramSolver::isAnagram("note", "tone"));
  EXPECT_TRUE(AnagramSolver::isAnagram("tarp", "part"));
  EXPECT_FALSE(AnagramSolver::isAnagram("nap", "pat"));
  EXPECT_FALSE(AnagramSolver::isAnagram("cat", "tacky"));
}

/**
Test the method with this declaration
std::unordered_map<std::string, deque<std::string>>  AnagramSolver::buildAnagramMap(std::deque<std::string> possibleAnagrams) {
*/
TEST(AnagramSolverTest, BuildAnagramMapTest) {
  unordered_map<string, deque<string>> anagramMap;
  deque<string> words = { "nap", "pan", "pare", "tone", "tarp", "note", "part", "pear", "reap", "rape" };
  anagramMap = AnagramSolver::buildAnagramMap(words);

  EXPECT_EQ(anagramMap.size(), 4);

  ASSERT_TRUE(anagramMap.find("nap") != anagramMap.end());
  deque<string> first{ "pan" };
  EXPECT_EQ(anagramMap["nap"], first);

  ASSERT_TRUE(anagramMap.find(words[2]) != anagramMap.end());
  deque<string> second{ "pear", "reap", "rape" };
  EXPECT_EQ(anagramMap[words[2]], second);

  ASSERT_TRUE(anagramMap.find("tone") != anagramMap.end());
  deque<string> third{ "note" };
  EXPECT_EQ(anagramMap[words[3]], third);

  deque<string> fourth { "part", };
  ASSERT_TRUE(anagramMap.find("tarp") != anagramMap.end());
  EXPECT_EQ(anagramMap[words[4]], fourth);
}

/**
Test the method with this declaration
deque < deque < string >> AnagramSolver::buildAnagramList(deque<string>  possibleAnagrams) which
returns a 2D deque where each row is a a set of strings that are anagrams
*/
TEST(AnagramSolverTest, BuildAnagramListTest) {
  deque<string> words = { "nap", "pan", "pare", "tone", "tarp", "note", "part", "pear", "reap", "rape" };
  auto anagramList = AnagramSolver::buildAnagramList(words);
  EXPECT_EQ(anagramList.size(), 4);

  deque<string> first{ "nap", "pan" };
  EXPECT_EQ(anagramList[0], first);
  deque<string> second { "pare", "pear", "reap", "rape" };
  EXPECT_EQ(anagramList[1], second);
  deque<string> third { "tone", "note" };
  EXPECT_EQ(anagramList[2], third);
  deque<string> fourth { "tarp", "part", };
  EXPECT_EQ(anagramList[3], fourth);
}