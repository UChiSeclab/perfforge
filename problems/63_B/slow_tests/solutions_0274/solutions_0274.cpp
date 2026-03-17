#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int main() {
  int a, t, n, i, j, k, l, mn = INT_MAX, mx = 0;
  cin >> n >> k;
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    mn = min(mn, a);
    m[a]++;
  }
  int p = mn;
  while (p < k) {
    ans++;
    mn = INT_MAX;
    for (int i = k - 1; i >= p; i--) {
      if (m[i] > 0) m[i]--, m[i + 1]++;
      if (m[i] > 0) mn = min(mn, i);
      if (m[i + 1] > 0) mn = min(mn, i + 1);
    }
    p = mn;
  }
  cout << ans << "\n";
}
