#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, k, total[N], MinP[N], p[N], A[N];
long long a, x, y, ans;
inline int quick_pow(long long v, int c) {
  long long res = 1;
  while (c) {
    if (c & 1) res *= v;
    if (v > 100000) return v;
    v *= v;
    c >>= 1;
    if (res > 100000) break;
  }
  return res;
}
template <class T>
inline void sd(T& x) {
  char c;
  T y = 1;
  while (c = getchar(), (c < 48 || 57 < c) && c != -1)
    if (c == 45) y = -1;
  x = c - 48;
  while (c = getchar(), 47 < c && c < 58) x = x * 10 + c - 48;
  x *= y;
}
int main() {
  sd(n), sd(k);
  int Max = 1;
  for (register int i = 1; i <= n; ++i) {
    sd(A[i]);
    Max = max(A[i], Max);
  }
  for (register int i = 2; i <= Max; i++) {
    if (p[i] != 0) continue;
    for (register int j = i; j <= Max; j += i) p[j] = i;
  }
  for (register int i = 1; i <= n; ++i) {
    x = y = 1;
    while (A[i] > 1) {
      int j = p[A[i]], cnt = 0;
      while (A[i] % j == 0) A[i] /= j, cnt++;
      cnt %= k;
      x *= quick_pow(j, cnt);
      y *= quick_pow(j, (k - cnt) % k);
      if (y > 100000) break;
    }
    if (y < 100001 && y >= 0) ans += total[y], total[x]++;
  }
  printf("%lld", ans);
  return 0;
}
