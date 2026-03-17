#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double EPS = 1e-9;
const long double PI = acos(-1);
const long long INF = 1e18;
const long long mod = 1e9 + 7;
long long factorial(long long n) {
  if (n == 0) return 1;
  long long x = 1;
  for (long long i = 1; i <= n; i++) {
    x = (x * i) % mod;
  }
  return x;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    y = y >> 1;
  }
  return res % mod;
}
long long modInverse(long long n) { return power(n, mod - 2); }
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return ((factorial(n) % mod) *
          (modInverse(((factorial(r) % mod) * (factorial(n - r) % mod)) % mod) %
           mod) %
          mod);
}
long long xor_1_x(long long x) {
  if (x % 4 == 0) return x;
  if (x % 4 == 1) return 1;
  if (x % 4 == 2) return x + 1;
  return 0;
}
bool prime(long long n) {
  if (n < 2) return false;
  for (long long x = 2; x * x <= n; x++) {
    if (n % x == 0) return false;
  }
  return true;
}
vector<long long> factors(long long n) {
  vector<long long> f;
  for (long x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.push_back(x);
      n /= x;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}
int dp[1000005], p[1000005], pf[1000005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_cases = 1, tt = 1;
  while (test_cases--) {
    int n, mx = 0;
    cin >> n;
    memset(p, 0, sizeof(p)), memset(pf, 0, sizeof(pf));
    int power[1000005];
    memset(power, 0, sizeof(power));
    for (int i = 0; i <= n - 1; i++) {
      int a, b;
      cin >> a >> b;
      power[a] = b;
      p[a] = 1;
      mx = max(mx, a);
    }
    for (int i = 0; i <= mx; i++) {
      pf[i] = (i - 1 >= 0 ? pf[i - 1] : 0) + p[i];
    }
    memset(dp, 0, sizeof(dp));
    int ans = 1e7;
    for (int i = 0; i <= mx; i++) {
      if (p[i]) {
        if (i - power[i] < 0)
          dp[i] = pf[i] - 1;
        else {
          if (i - power[i] == 0) {
            if (p[0] == 0)
              dp[i] = dp[i - power[i]] + pf[i] - pf[i - power[i]] - 1;
            else
              dp[i] = dp[i - power[i]] + pf[i] - (pf[i - power[i]] - 1) - 1;
          } else
            dp[i] = dp[i - power[i] - 1] + pf[i] - pf[i - power[i] - 1] - 1;
        }
        ans = min(ans, dp[i] + pf[mx] - pf[i]);
      } else {
        dp[i] = (i - 1 >= 0 ? dp[i - 1] : 0);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
