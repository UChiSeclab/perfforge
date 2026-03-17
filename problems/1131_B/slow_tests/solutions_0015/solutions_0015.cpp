#include <bits/stdc++.h>
#pragma optimize("O3")
using namespace std;
const long long MOD = 998244353;
const long long INF = 1e9 + 7;
const int base = 2e5 + 1;
const int MAX = 1e5 + 2;
const double EPS = 1e-9;
const double PI = acos(-1.);
const int MAXN = 3 * 1e5 + 47;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  int n;
  cin >> n;
  vector<long long> x(n), y(n);
  for (long long i = (0); i < (n); ++i) cin >> x[i] >> y[i];
  long long cnt = 0;
  long long t = 0;
  for (long long i = (0); i < (n); ++i) {
    while (t <= min(x[i], y[i])) {
      t++;
      cnt++;
    }
    t = max(t, max(x[i], y[i]));
  }
  cout << cnt;
  cerr << "\nTime elapsed: " << clock() / (double)CLOCKS_PER_SEC << '\n';
  return 0;
}
