#include "stdafx.h"
#include "gtest/gtest.h"
#include "AnagramSolver.h"

TEST(AnagramSolverTest, isAnagramTest) {

  EXPECT_TRUE(AnagramSolver::isAnagram("nap", "pan"));
  EXPECT_TRUE(AnagramSolver::isAnagram("note", "tone"));
  EXPECT_TRUE(AnagramSolver::isAnagram("tarp", "part"));
  EXPECT_FALSE(AnagramSolver::isAnagram("nap", "pat"));
  EXPECT_FALSE(AnagramSolver::isAnagram("cat", "tacky"));

}