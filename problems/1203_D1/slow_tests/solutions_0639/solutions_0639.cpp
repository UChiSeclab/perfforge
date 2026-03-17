#include <bits/stdc++.h>
using namespace std;
bool check(string txt, string pat) {
  long long int n = txt.length(), m = pat.length();
  long long int i = 0, j = 0;
  while (i < n && j < m) {
    if (txt[i] == pat[j]) {
      j++;
    }
    i++;
  }
  if (j < m) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string txt, pat;
  cin >> txt >> pat;
  long long int ans = 0;
  for (long long int(i) = (0); (i) < (txt.length()); (i)++) {
    string pre = txt.substr(0, i);
    for (long long int len = 1; len <= txt.length() - i; len++) {
      string sub = txt.substr(i, len);
      string suff = txt.substr(i + len, txt.length() - i - len);
      string tmp = pre + suff;
      if (tmp.length() >= pat.length()) {
        if (check(tmp, pat)) {
          ans = max(ans, len);
        }
      }
    }
  }
  cout << ans;
  return 0;
}
