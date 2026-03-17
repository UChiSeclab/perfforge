#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pci = pair<char, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
const ll infll = 1e18 + 3;
const int maxn = 1e6 + 77;
const int nmax = 1e6 + 577;
const ll basell = 1e18 + 3;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
const int inf = 1009000999;
const int nv = 100505;
const int baseint = 1000200013;
const ld PI = acos(-1.0);
inline bool EQ(ld a, ld b) { return fabs(a - b) < 1e-9; }
inline bool IF(int a, int b, int c) { return (a >= b && a <= c); }
inline bool IFS(int a, int b, int c) { return (a > b && a < c); }
int a[nmax];
int dp[nmax];
int inline solve() {
  ios::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    dp[a[i]] = 1;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 2 * a[i]; j < nmax; j += a[i]) {
      dp[j] = max(dp[j], dp[a[i]] + 1);
    }
    ans = max(ans, dp[a[i]]);
  }
  cout << ans;
  return 0;
}
int32_t main() {
  solve();
  return 0;
}
