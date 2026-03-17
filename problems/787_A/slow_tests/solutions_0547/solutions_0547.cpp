#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 5;
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  for (long long i = 0; i < N; i++) {
    long long x = b + i * a;
    double y = ((1.0) * (x - d)) / c;
    if (ceil(y) == floor(y) && y >= 0) {
      cout << x << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  clock_t start = clock();
  long long t = 1;
  while (t--) {
    solve();
  }
  clock_t stop = clock();
  return 0;
}
