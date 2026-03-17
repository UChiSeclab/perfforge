#include <bits/stdc++.h>
using namespace std;
const long long LIM = 1e5, N = LIM + 10;
const long long INF = 1e10;
long long C, ans, a[N];
long long n, K;
std::vector<long long> fac;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void dfs(long long x, long long dep) {
  if (x > LIM) return;
  if (x > C / x) return;
  if (x == C / x)
    ans += a[x] * (a[x] - 1) / 2;
  else if (C / x <= LIM)
    ans += a[x] * a[C / x];
  for (long long i = dep; i < (long long)fac.size(); i++) {
    long long t = fac[i], s = x * t;
    for (; C % s == 0; s = s * t) dfs(s, i + 1);
  }
}
signed main() {
  n = read(), K = read();
  for (long long i = 1; i <= n; i++) ++a[read()];
  for (long long i = 1; i <= LIM; i++) {
    long long f = 1;
    C = 1;
    for (long long j = 1; j <= K; j++) {
      if (C * i > INF) {
        f = 0;
        break;
      }
      C *= i;
    }
    if (f == 0) continue;
    fac.clear();
    long long t = i;
    for (long long j = 2; 1ll * j * j <= t; j++)
      if (!(t % j)) {
        fac.push_back(j);
        while (!(t % j)) t /= j;
      }
    if (t > 1) fac.push_back(t);
    sort(fac.begin(), fac.end());
    dfs(1, 0);
  }
  printf("%lld\n", ans);
  return 0;
}
