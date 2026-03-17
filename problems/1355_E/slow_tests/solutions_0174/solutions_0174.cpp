#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int N = 100010;
const int mod = 998244353;
const double PI = 3.1415926535898;
int n;
long long a, r, m;
long long h[N];
inline long long calc(long long x) {
  long long p = 0, q = 0;
  for (int i = 1; i <= n; ++i) {
    if (h[i] <= x)
      p += x - h[i];
    else
      q += h[i] - x;
  }
  return min(p * a + q * r,
             min(p, q) * m + (p - min(p, q)) * a + (q - min(p, q)) * r);
}
int main() {
  scanf("%d %lld %lld %lld", &n, &a, &r, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &h[i]);
  }
  long long l = 0, r = 2000000000, mid, ret = 0;
  for (int t = 1; t <= 233; ++t) {
    mid = (l + r) >> 1;
    if (calc(mid) < calc((mid + r) >> 1))
      r = (mid + r) >> 1;
    else
      l = mid;
  }
  printf("%lld\n", calc(l));
  return 0;
}
