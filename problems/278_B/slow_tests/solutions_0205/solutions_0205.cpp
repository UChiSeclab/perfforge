#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, t;
  map<string, int> m;
  scanf("%d", &n);
  string s, l;
  for (int i = (int)0; i < (int)n; ++i) {
    cin >> s;
    for (int j = (int)0; j < (int)int(s.size()); ++j) {
      for (int k = (int)j; k < (int)int(s.size()); ++k) {
        l = s.substr(j, k - j + 1);
        m[l]++;
      }
    }
  }
  char ch, c;
  for (i = 1; i <= 2; i++) {
    s = "";
    for (int j = (int)0; j < (int)i; ++j) s += 'a';
    for (c = 'a'; c <= 'z'; c++) {
      for (ch = 'a'; ch <= 'z'; ch++) {
        s[i - 1] = ch;
        if (i > 1) s[i - 2] = c;
        if (!m[s]) {
          cout << s << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
