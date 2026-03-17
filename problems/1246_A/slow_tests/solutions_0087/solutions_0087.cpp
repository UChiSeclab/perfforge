#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c & 15);
  return x * f;
}
template <typename T>
inline bool cmax(T& x, T y) {
  return x < y ? (x = y), 1 : 0;
}
template <typename T>
inline bool cmin(T& x, T y) {
  return x > y ? (x = y), 1 : 0;
}
inline long long QP(long long x, long long y, long long Mod) {
  long long ans = 1;
  for (; y; y >>= 1, x = (x * x) % Mod)
    if (y & 1) ans = (ans * x) % Mod;
  return ans;
}
long long n;
inline long long low(long long x) {
  long long cnt = 0;
  while (x) {
    x ^= x & -x;
    cnt++;
  }
  return cnt;
}
signed main() {
  n = read();
  long long k = read();
  for (register long long i = 1; i <= 1e6 + 10; i++)
    if (n - k * i >= i && low(n - k * i) <= i) return !printf("%lld\n", i);
  puts("-1");
  return 0;
}
