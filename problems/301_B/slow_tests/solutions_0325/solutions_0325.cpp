#include <bits/stdc++.h>
using namespace std;
bool can(int& n, int& d, vector<int>& a, vector<int>& x, vector<int>& y,
         int t) {
  vector<int> maxTime(n, -1);
  maxTime[0] = t;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (maxTime[i] < 0) continue;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        maxTime[j] =
            max(maxTime[j],
                maxTime[i] - d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) + a[j]);
      }
    }
  }
  return (maxTime[n - 1] >= 0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (0 & 1) freopen("input", "r", stdin);
  if (0 & 2) freopen("output", "w", stdout);
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 1; i + 1 < n; i++) cin >> a[i];
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  int lo = 0, hi = int(2e9), mi;
  while (lo <= hi) {
    mi = (lo + hi) / (2);
    if (!can(n, d, a, x, y, mi))
      lo = mi + 1;
    else
      hi = mi - 1;
  }
  cout << lo << "\n";
  return 0;
}
