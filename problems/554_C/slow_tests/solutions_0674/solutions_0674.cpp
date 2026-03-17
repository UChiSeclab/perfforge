#include <bits/stdc++.h>
using namespace std;
long long dp[2005][2005];
long long comb(long long n, long long k) {
  if ((k == 0) || k == n) return 1;
  if (dp[n][k] != 0) return dp[n][k];
  long long x = comb(n - 1, k - 1) % 1000000007 + comb(n - 1, k) % 1000000007;
  dp[n][k] = x % 1000000007;
  x %= 1000000007;
  return x;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 1;
  long long cnt = a[0];
  for (long long i = 1; i < n; i++) {
    ans *= comb(cnt + 1 + a[i] - 2, a[i] - 1);
    cnt += a[i];
    ans %= 1000000007;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
long long modPow(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long x = a * a;
    x %= 1000000007;
    return modPow(x, b / 2);
  }
  return (a * modPow(a, b - 1)) % 1000000007;
}
