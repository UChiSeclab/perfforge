#include <bits/stdc++.h>
using namespace std;
int n, p[1000001 + 1], t[1000001 + 1], d[1000001 + 1], maxi;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0, a, b; i < n; i++) {
    cin >> a >> b;
    p[a] = b;
    maxi = max(maxi, a);
  }
  t[0] = p[0] != 0;
  for (int i = 1; i <= maxi; i++) {
    t[i] = t[i - 1] + (p[i] != 0);
  }
  d[0] = 0;
  for (int i = 1; i <= maxi; i++) {
    if (p[i]) {
      d[i] = t[i - 1];
      if (i - p[i] - 1 >= 0) {
        d[i] -= t[i - p[i] - 1];
        d[i] += d[i - p[i] - 1];
      }
    } else {
      if (i > 0) d[i] = d[i - 1];
    }
  }
  int mini = INT_MAX;
  for (int i = 0; i <= maxi + 1; i++) {
    mini = min(mini, d[i - 1] + t[maxi] - t[i - 1]);
  }
  cout << mini << "\n";
  return 0;
}
