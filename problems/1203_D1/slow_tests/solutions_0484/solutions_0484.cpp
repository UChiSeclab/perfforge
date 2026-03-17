#include <bits/stdc++.h>
using namespace std;
long long int ceil1(long long int n, long long int m) {
  if (n % m == 0) {
    return n / m;
  }
  return n / m + 1;
}
void solve() {
  long long int i, j, k, c, ans = 0;
  string s, t;
  cin >> s >> t;
  long long int l = s.size();
  for (i = 0; i < l; i++) {
    for (j = i; j < l; j++) {
      c = 0;
      for (k = 0; k < l; k++) {
        if (k >= i && k <= j) continue;
        if (s[k] == t[c]) c++;
      }
      if (c == t.size()) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  long long int q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
