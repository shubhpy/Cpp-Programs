// Print all palindromes of size
// greater than equal to 3 of a given
// string. (DP)

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Q: checking palindrome does not consider
//    space, case insensitive, right?
// A: True.

void checkPalindrome(string s) {
	if (s.size() < 3) return;

	vector<bool> memo(s.size(), 0);
	for (int i = s.size() - 1; i >= 0; --i) {
		for (int j = s.size() - 1; j >= i; --j) {
			if (s[i] == s[j] && (j <= i + 1 || memo[j - 1])) {
				memo[j] = 1;
				if (j - i + 1 >= 3)
					cout << s.substr(i, j - i + 1) << endl;
			}
			else memo[j] = 0;
		}
	}

}



int main() {
	// string s = "122112321";
	//string s = "cabbaabbacasdasdsdsdsdassadsadasdasadsadasda";
	string s = "aabobseesanna";
	checkPalindrome(s);

	return EXIT_SUCCESS;
}
