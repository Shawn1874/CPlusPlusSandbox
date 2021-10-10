#include "AnagramSolver.h"
#include <algorithm>

using std::string;
using std::unordered_map;
using std::deque;

	/**
 * Finds anagrams and builds a multidimensional container.  Size of the first dimension
 * is the number of sets of anagrams found, and 2nd dimension 1 row each for each set of anagrams.
 *
 * Approach:
 * Foreach element of the input array, compare to the first element of each row to determine if
 * it is an anagram of something already within the solution array. The first string of the input
 * will be added to the first arraylist since there is nothing yet to compare to.  From that point
 * loop over all rows and check if the next string is an anagram of the first word in the row.
 * Either append the string to an existing row or add it as the first string to a new row.
 *
 * @param possibleAnagrams container of strings such as "ate", "tea", "note", "tone"
 * @return deque < deque < string >> where each row is a set of anagrams
 */
deque < deque < string >> AnagramSolver::buildAnagramList(deque<string>  possibleAnagrams) {
	deque < deque < string >> solution;

 	// 1st iteration the list will be empty so first string will be added
 	// 2nd iteration - if not anagram of any of the first elements of each list then add a new array list with s
 	//    as the first element
	for (string a : possibleAnagrams) {
 		bool inserted = false;

 		for (deque<string>& d : solution) {

 			if (isAnagram(d[0], a)) {
 				inserted = true;
 				d.push_back(a);
 			}
 		}

 		if (!inserted) {
			deque < string > temp { a }; 
 			solution.push_back(temp);
 		}
 	}
 	return solution;
 }

 /**
	* Finds anagrams and builds a HashMap<String, ArrayList<String>>.
	*
	* Approach:
	* If the HashMap is empty then the first string will be inserted with an empty ArrayList as the value.
	* Subsequent strings will be compared to the keys.  If it is an anagram then add it to the ArrayList of
	* values.
	*
	* @param possibleAnagrams ArrayList of strings such as "ate", "tea", "note", "tone"
	* @return
	*/
unordered_map<string, deque<string>>  AnagramSolver::buildAnagramMap(deque<string> possibleAnagrams) {
	unordered_map<string, deque<string>> solution;

		// 1st iteration the list will be empty so first string will be added
		// 2nd iteration - if not anagram of any of the first elements of each list then add a new array list with s
		//    as the first element
		for (string a : possibleAnagrams) {
			bool inserted = false;

			for (auto i = solution.begin(); i != solution.end(); ++i) {

				if (isAnagram(i->first, a)) {
					i->second.push_back(a);
					inserted = true;
				}
			}

			// Add a pair<string, deque<string>> to the map where the value is an empty deque
			if (!inserted) {
				deque<string> anagrams;
				solution[a] = anagrams;
			}
		}
		return solution;
	}

	/**
	 * Tests whether the parameters are anagrams of one another.  An anagram of a word is one that uses the same characters
	 * to form another word.  For instance pear is an anagram of pare, and reap.
	 *
	 * Approach:
	 * First a short circuit evaluation is performed since the arrays must be the same length to be anagrams.  If the length
	 * matches then sort the two input parameters
	 * @param first string
	 * @param second string to compare against first
	 * @return true if the the two words are anagrams and false if these are not anagrams.
	 */
bool AnagramSolver::isAnagram(string first, string second) {

  if (first.size() != second.size()) {
    return false;
  }
  else {
    // in order for one to be an anagram of another, each character must occur the same number of times 
    // in the other string
    sort(second.begin(), second.end());
    sort(first.begin(), first.end());
    return (first == second);
  }
}