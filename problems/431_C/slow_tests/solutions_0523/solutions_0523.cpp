#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long n, k, d;
long long dp[101][101][101];
long long f(long long max_val, long long num_val, long long num) {
  if (num <= 0) return 0;
  if (num_val == 1) {
    if (num > max_val) return 0;
    return 1;
  }
  if (dp[max_val][num_val][num] != -1) return dp[max_val][num_val][num];
  long long i;
  long long ans = 0;
  for (i = 1; i <= max_val; i++) {
    ans = mod_add(f(max_val, num_val - 1, num - i), ans);
  }
  return dp[max_val][num_val][num] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, i, j, ans, temp, sum;
  string sans;
  t = 1;
  while (t--) {
    memset(dp, -1, sizeof(dp));
    sans = "NO";
    ans = temp = sum = 0;
    cin >> n >> k >> d;
    for (i = 1; i <= n; i++) {
      ans = (ans + f(k, i, n) - f(d - 1, i, n) + mod) % mod;
    }
    cout << ans;
  }
  return 0;
}
