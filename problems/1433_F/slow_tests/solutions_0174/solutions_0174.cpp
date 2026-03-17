#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS = 1e-8;
const int INF = 0x3F3F3F3F;
const ll LINF = 4611686018427387903;
const int MOD = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  const int N = 70 * 35 * 70 + 25;
  bitset<N> dp[2];
  dp[1] = 1;
  int n, m, k, prv = 0, cur = 1;
  cin >> n >> m >> k;
  vector<bitset<70 * 35 + 25>> owo(m / 2 + 1);
  for (int i = 0; i < n; i++) {
    swap(prv, cur);
    for (int i = 0; i <= m / 2; i++) owo[i].reset();
    owo[0][0] = 1;
    for (int j = 1, x; j <= m; j++) {
      cin >> x;
      for (int k = m / 2; k; k--) owo[k] = (owo[k - 1] << x) | owo[k];
    }
    for (int i = 1; i <= m / 2; i++) owo[i] = owo[i] | owo[i - 1];
    for (int j = 0; j <= 70 * 35 + 5; j++)
      if (owo[m / 2][j]) dp[cur] = dp[cur] | (dp[prv] << j);
  }
  int ans = 0;
  for (int i = k; i < N; i += k)
    if (dp[cur][i]) ans = i;
  cout << ans << '\n';
  return 0;
}
