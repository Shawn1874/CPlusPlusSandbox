#pragma once
#include <algorithm>
#include <vector>
#include <stdexcept>

class Algorithms
{
public:
  Algorithms();
  ~Algorithms();

  template <typename BidirIter>
  static void Reverse(BidirIter begin, BidirIter end)
  {
    // 0, 1, 2, 3, end
    for( ; begin != --end && begin != end; ++begin)
    {
      std::swap(*begin, *end);
    }
  }

  /*
  * Merges sorted range source into the sorted range destination.  If ranges are not sorted, the behavior
  * is undefined.  Caller must ensure that destination is large enough to contain the merged ranges or
  * the behavior is undefined.  This method will not allocate memory.
  */
  template <typename FwdIter>
  static void MergeSortedRanges(FwdIter sourceFirst, FwdIter sourceLast, FwdIter destFirst, FwdIter destLast)
  {
    // iterate over the source range
    // determine the location within the destination
    // swap element from source with element from destination
    // iterate over the remainder of the destination swapping the temporary until end of range reached
    FwdIter tempIter;
    bool found = false;

    while(sourceFirst != sourceLast)
    {
      for(; destFirst != destLast; ++destFirst)
      {
        if(*sourceFirst < *destFirst)
        {
          found = true;
          break;
        }
      }

      // *destFirst must be replaced with value from source but values must be shifted

      auto tempValue = *sourceFirst;
      *destLast = 0;
      destLast++;
      tempIter = destFirst + 1;

      for( ; destFirst != destLast; ++destFirst)
      {
        std::swap(tempValue, *destFirst);
      }

      ++sourceFirst;
      destFirst = tempIter;

      found = false;
    }
  }

    /*

    Given an array nums containing n distinct numbers in the range [0, n], return the only
    number in the range that is missing from the array. 

    example:
      Input: nums = [3,0,1] with a size of 3 therefore n = 3
      Output: 2

    */
  static int findMissingNumberInContainer(const std::vector<int> values) {
    std::vector<int>::size_type n(0), endRange(values.size());
    auto begin = values.begin(); 
    auto last = values.end();

    for (; n < endRange; ++n) {
      if (std::find(begin, last, n) == last) {
        return n;
      }
    }
    return n;
  }

  /*

   Given an array nums containing n distinct numbers in the range [min, max], return the only
   number in the range that is missing from the array. The actual range must be at least of 
   length (max - min) otherwise the result will be undefined behavior and the function may 
   return a non-sensical value.  If the range is (max - min) + 1 and there is no value missing
   then the return value will be max + 1.

   example:
     Input: nums = [3,0,1,-1] where min = -1, and max = 3
     Output: 2

   */
  template <typename FwdIter>
    static int findMissingNumberInRange(FwdIter begin, FwdIter end, int min, int max)
  {
      int n = min;
      for (; n <= max; n++) {
        if (std::find(begin, end, n) == end) {
          return n;
        }
      }

      return n;
  }

 template <typename ContainerT, typename ComparatorT>
    static void bubbleSort(ContainerT& values, ComparatorT compare) {
      for (size_t i = 0; i < values.size() - 1; ++i) {
        for (size_t j = 0; j < values.size() - 1; ++j) {
          if (compare(values[j], values[j + 1])) {
            std::swap(values[j], values[j + 1]);
          }
        }
      }
    }

    template <typename ContainerT, typename ComparatorT>
    static void bubbleSort2(ContainerT& values, ComparatorT compare) {
      for (size_t i = 0; i < values.size(); ++i) {
        for (size_t j = i + 1; j < values.size(); ++j) {
          if (compare(values[i], values[j])) {
            std::swap(values[i], values[j]);
          }
        }
      }
    }

    static void factorial(int a, int* result) {
      if (nullptr == result) {
        throw new std::invalid_argument("1 or more inputs is a nullptr");
      }

      *result = a;

      while (a > 1) {
        *result *= (a - 1);
        --a;
      }
    }
};

