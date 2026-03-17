#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const double eps = 1e-8;
const double pi = acos(-1.0);
long long cnt[60];
long long a[60], b[60];
long long n, q, u, v, tot, cost, ans;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long qpow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) {
      res *= x;
      res %= mod;
    }
    x *= x;
    x %= mod;
    y >>= 1;
  }
  return res;
}
long long slove() {
  long long res = 1, sum = 0, cnt;
  for (int i = 1; i <= tot; ++i) {
    if (cost % a[i] == 0) {
      cnt = 0;
      while (cost % a[i] == 0) {
        cost /= a[i];
        cnt++;
        sum++;
      }
      res *= qpow(b[cnt], mod - 2);
      res %= mod;
    }
  }
  res *= b[sum];
  res %= mod;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  b[0] = 1;
  for (long long i = 1; i < 60; ++i) {
    b[i] = (b[i - 1] * i) % mod;
  }
  cin >> n;
  long long tmp = n;
  for (long long i = 2; i * i <= n; ++i) {
    if (tmp % i == 0) {
      a[++tot] = i;
      while (tmp % i == 0) {
        tmp /= i;
      }
    }
  }
  if (tmp > 1) a[++tot] = tmp;
  cin >> q;
  while (q--) {
    ans = 0;
    cin >> u >> v;
    if (u == v) {
      cout << "1\n";
      continue;
    }
    if (u < v) swap(u, v);
    if (u % v == 0) {
      cost = u / v;
      ans = slove();
    } else {
      long long g = gcd(u, v);
      cost = u / g;
      ans = slove();
      cost = v / g;
      ans *= slove();
      ans %= mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
