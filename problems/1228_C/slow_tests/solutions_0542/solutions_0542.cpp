#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long calc(long long n, long long x) {
  long long z = 0;
  while (n) {
    z += n / x;
    n /= x;
  }
  return z;
}
long long mul(long long x, long long y) {
  x %= mod;
  y %= mod;
  return (x * y) % mod;
}
long long pp(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}
int main(int argc, char const *argv[]) {
  long long x, n;
  cin >> x >> n;
  ;
  const long long MX = 2 * sqrt(x);
  std::vector<bool> v(MX, 0);
  std::vector<long long> p;
  v[1] = 1;
  for (int i = 1; i < MX; ++i) {
    if (v[i]) continue;
    if (x % i == 0) p.push_back(i);
    for (int j = 2 * i; j < MX; j += i) v[j] = 1;
  }
  set<long long> P;
  long long tmp = x;
  for (long long xx : p) {
    if (tmp % xx == 0) {
      while (tmp % xx == 0) tmp /= xx;
    }
  }
  if (tmp > 1) p.push_back(tmp);
  long long ans = 1;
  for (long long xx : p) {
    ans = mul(ans, pp(xx, calc(n, xx)));
  }
  cout << ans << endl;
  return 0;
}
