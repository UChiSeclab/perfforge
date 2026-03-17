#include <bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t) {
  int i = 0;
  int j = 0;
  int l = t.length();
  int len = s.length();
  while (j < l && i < len) {
    if (s[i] == t[j]) {
      i++;
      j++;
    } else
      i++;
  }
  return j == l;
}
int main() {
  string s, t;
  cin >> s;
  cin >> t;
  int l = s.length();
  int maxlen = 0;
  for (int i = 0; i < l; i++) {
    for (int j = i; j < l; j++) {
      int len = j - i + 1;
      string s1 = s.substr(0, i) + s.substr(j + 1);
      if (isSubsequence(s1, t)) {
        maxlen = max(maxlen, len);
      }
    }
  }
  cout << maxlen << endl;
  return 0;
}
