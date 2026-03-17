#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int MAXN = 1000006;
long long a, b;
long long suma(long long e, long long l) {
  long long m1 = e, m2 = e + 1;
  if (m1 % 2 == 0)
    m1 /= 2;
  else
    m2 /= 2;
  m1 %= mod;
  m2 %= mod;
  e %= mod;
  return (m1 * m2 % mod * b % mod * l % mod + l * (e + 1)) % mod;
}
int main() {
  scanf("%lld%lld", &a, &b);
  long long ret = 0;
  for (int l = 1; l < b; ++l) {
    ret += suma(a, l);
    ret += mod - l;
  }
  printf("%lld\n", ret % mod);
  return 0;
}
