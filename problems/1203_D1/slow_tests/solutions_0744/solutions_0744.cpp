#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 4e5 + 10;
const ll inf = 1e18 + 10;
const ll MOD = 998244353;
string s, t;
int n, m;
int main() {
  cin >> s >> t;
  n = s.size(), m = t.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (n - j + i - 1 < m) continue;
      int p = 0, q = 0;
      while (p < n) {
        if (i <= p && p <= j) p = j + 1;
        if (p < n && q < m && s[p] == t[q]) q++;
        p++;
      }
      if (q == m) ans = max(ans, j - i + 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
