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

  // std::out doesn't seem to go where I want it to with google test so I'll have to figure this out some other time.
  //for (auto i = anagramMap.begin(); i != anagramMap.end(); ++i) {
  //  std::cout << i->first << " : ";
  //  std::deque<string> temp = i->second;
  //  for (auto n = temp.begin(); n != temp.end(); ++i) {
  //    std::cout << *n << ", ";
  //  }
  //  std::cout << std::endl;
  //}
}