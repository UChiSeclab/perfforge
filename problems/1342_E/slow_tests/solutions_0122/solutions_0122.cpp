#include <bits/stdc++.h>
using namespace std;
const double PI = 4 * atan(1);
const long long mod = 998244353;
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
      res %= mod;
    }
    b = b >> 1;
    a *= a;
    a %= mod;
  }
  return res;
}
long long modInv(long long a) { return power(a, mod - 2); }
long long ncr(long long n, long long r, vector<long long>& fact) {
  long long res = fact[n];
  res = res * modInv(fact[r]);
  res %= mod;
  res = res * modInv(fact[n - r]);
  res %= mod;
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  if (k > n - 1) {
    cout << 0 << "\n";
    return 0;
  }
  vector<long long> fact(n + 1);
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] = (fact[i] % mod + mod) % mod;
  }
  if (k == 0) {
    long long ans = fact[n];
    cout << ans << "\n";
    return 0;
  }
  long long c = n - k;
  long long ans = 0;
  for (long long i = 0; i <= c; i++) {
    long long temp = 0;
    temp = ncr(c, i, fact);
    temp = (temp % mod + mod) % mod;
    temp *= power(c - i, n);
    temp = (temp % mod + mod) % mod;
    if (i % 2)
      ans -= temp;
    else {
      ans += temp;
    }
    ans = (ans % mod + mod) % mod;
  }
  ans = ans * ncr(n, c, fact);
  ans = (ans % mod + mod) % mod;
  ans = ans * 2;
  ans = (ans % mod + mod) % mod;
  cout << ans << "\n";
  return 0;
}
