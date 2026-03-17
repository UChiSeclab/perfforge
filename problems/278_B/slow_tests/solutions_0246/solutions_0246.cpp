#include <bits/stdc++.h>
using namespace std;
string t[31];
int n;
bool fin(string s) {
  for (int i = 0; i < n; ++i)
    if (t[i].find(s) != string::npos) return false;
  return true;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> t[i];
  for (int l = 1; l <= 3; ++l)
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        for (int k = 0; k < 26; ++k) {
          string s = "";
          s += ('a' + i);
          if (l > 1) s += ('a' + j);
          if (l > 2) s += ('a' + k);
          if (fin(s)) cout << s, exit(0);
        }
      }
    }
  return 0;
}
