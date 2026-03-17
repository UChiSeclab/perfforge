#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9;
const long long MB = 20;
const long long MOD = 998244353;
const long long maxN = 1e6;
long long mod_pow(long long a, long long b) {
  if (!b) return 1;
  if (b % 2) return a * mod_pow(a, b - 1) % MOD;
  long long q = mod_pow(a, b / 2);
  return q * q % MOD;
}
long long fact[maxN], rev[maxN];
long long c(long long n, long long k) {
  if (n < k) return 0;
  return (fact[n] * rev[k] % MOD) * rev[n - k] % MOD;
}
void solve() {
  long long n, k;
  cin >> k >> n;
  if (n > k) {
    cout << 0;
    return;
  }
  fact[0] = 1;
  for (long long i = 1; i < maxN; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  for (long long i = 0; i < maxN; i++) {
    rev[i] = mod_pow(fact[i], MOD - 2);
  }
  long long ans = 0;
  for (long long i = 1; i <= k; i++) {
    long long cnt = k / i - 1;
    ans += c(cnt, n - 1);
    ans %= MOD;
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout.precision(12);
  srand(time(0));
  long long t = 1;
  while (t--) solve();
}
