#pragma once
#include <string>
#include <unordered_map>
#include <deque>

#pragma once
#ifndef __AnagramSolver__
#define __AnagramSolver__

class AnagramSolver
{
public:
  static bool isAnagram(std::string, std::string);
  static std::unordered_map<std::string, std::deque<std::string> > buildAnagramMap(std::deque<std::string> possibleAnagrams);
};

#endif
