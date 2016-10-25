#include <iostream>
#include <vector>

using namespace std;

// p is the cached results.
bool checkPalindrome(string s, int start, int end, int **p) {
  if (p[start][end] == -1) {
    if (end - start > 2) {
      if (s[start] == s[end]) {
        if (checkPalindrome(s, start + 1, end - 1, p)) {
          p[start][end] = 1;
          return true;
        } else {
          p[start][end] = 0;
          return false;
        }
      } else {
        p[start][end] = 0;
        return false;
      }
    } else {
      if (s[start] == s[end]) {
        p[start][end] = 1;
        return true;
      } else {
        p[start][end] = 0;
        return false;
      }
    }
  }
  else return p[start][end] == 1;
}

void printPalindrome(string s) {
  int slen = s.length();
  int **p = new int *[slen];
  for (int i = 0; i < slen; i++) {
    p[i] = new int[slen];
  }
  for (int i = 0; i < slen; i++)
    for (int j = 0; j < slen; j++)
      p[i][j] = -1; // do not know
  for (int i = 0; i < slen - 1; i++) {
    for (int j = slen - 1; j > i + 1; j--) {
      if (checkPalindrome(s, i, j, p)) {
        cout << s.substr(i, j - i + 1) << endl;
      }
    }
  }
  for (int i = 0; i < slen; i++) {
    delete[] p[i];
  }
  delete[] p;
}

int main(){

    string s = "abaabccba";

    printPalindrome(s);

return 0;
}
