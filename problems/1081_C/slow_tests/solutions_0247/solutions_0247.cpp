#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
int modpow(int a, int p) {
  int ans = 1;
  while (p > 0) {
    if (p & 1) ans = 1LL * ans * a % MOD;
    a = 1LL * a * a % MOD;
    p >>= 1;
  }
  return ans;
}
long long inv(int n) { return modpow(n, MOD - 2); }
ll mult(int a, int b) { return a * 1ll * b % MOD; }
ll dp[2001][2001];
int solvedp() {
  int n, m, k;
  cin >> n >> m >> k;
  dp[1][0] = m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = (dp[i][j] + dp[i - 1][j] % MOD) % MOD;
      if (j > 0)
        dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1] * (m - 1) % MOD) % MOD) % MOD;
    }
  }
  return dp[n][k];
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> fact(2333, 0);
  fact[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * (ll)i % MOD;
  }
  ll res =
      mult(mult(mult(mult(fact[n - 1], inv(fact[k])), inv(fact[n - 1 - k])), m),
           modpow(m - 1, k));
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << solvedp() << endl;
  return 0;
}
