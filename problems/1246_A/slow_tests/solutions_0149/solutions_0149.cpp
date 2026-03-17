#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  int64_t n, p;
  cin >> n >> p;
  for (int64_t i = 1; i < 1e6; ++i) {
    n -= p;
    if (__builtin_popcount(n) > i) {
      continue;
    }
    if (n < i) {
      continue;
    }
    cout << i;
    return 0;
  }
  cout << -1;
}
