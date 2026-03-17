#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;
const int EMOD = 998244353;
int n, m, k;
long long dp[2222][2222];
long long f(int i, int k) {
  if (dp[i][k] != -1) return dp[i][k];
  if (!k && i == n) return 1LL;
  if (i == n) return 0LL;
  return dp[i][k] = ((m * f(i + 1, k - 1)) % EMOD + f(i + 1, k) % EMOD) % EMOD;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  long long ans = m;
  m--;
  memset(dp, -1, sizeof(dp));
  ans = (ans * f(1, k)) % EMOD;
  printf("%lld\n", ans);
  return 0;
}
