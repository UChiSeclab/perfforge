#include <bits/stdc++.h>
using namespace std;
const int HW = 200007;
const int N = 2007;
const int MOD = 1000000007;
int n;
int r[N], c[N];
int f[HW], invf[HW];
int dp[N];
int bpow(int a, int b) {
  if (b == 0) return 1;
  int result = bpow(a, b / 2);
  return (long long)result * result % MOD * (b % 2 == 1 ? a : 1) % MOD;
}
int comb(int n, int k) {
  return (long long)f[n] * invf[n - k] % MOD * invf[k] % MOD;
}
int count_ways(int i) {
  if (dp[i] != -1) return dp[i];
  dp[i] = comb(r[i] + c[i] - 2, c[i] - 1);
  for (int j = 0; j <= n; ++j)
    if (r[j] <= r[i] && c[j] <= c[i] && i != j) {
      dp[i] -= (long long)count_ways(j) *
               comb(r[i] - r[j] + c[i] - c[j], c[i] - c[j]) % MOD;
      if (dp[i] < 0) dp[i] += MOD;
    }
  return dp[i];
}
int main() {
  int h, w;
  cin >> h >> w >> n;
  for (int i = 0; i < n; ++i) cin >> r[i] >> c[i];
  r[n] = h, c[n] = w;
  f[0] = 1, invf[0] = 1;
  for (int i = 1; i <= h + w; ++i) {
    f[i] = (long long)f[i - 1] * i % MOD;
    invf[i] = bpow(f[i], MOD - 2);
  }
  for (int i = 0; i <= n; ++i) dp[i] = -1;
  cout << count_ways(n) << '\n';
  return 0;
}
