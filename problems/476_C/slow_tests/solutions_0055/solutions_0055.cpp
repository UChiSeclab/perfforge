#include <bits/stdc++.h>
const double eps = 1E-9;
const double pi = acos(-1);
const long long mod = 1000000007;
using namespace std;
long long a, b;
long long x;
long long f(long long i) {
  return ((((b * i) % mod) * x) % mod + (a * i) % mod) % mod;
}
int main() {
  scanf("%I64d%I64d", &a, &b);
  x = (a * (a + 1) / 2ll) % mod;
  long long i, kq = 0, j;
  for (i = 1; i < b; ++i) {
    kq = (kq + f(i)) % mod;
  }
  printf("%I64d\n", kq);
}
