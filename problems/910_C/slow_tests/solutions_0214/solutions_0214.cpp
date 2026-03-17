#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e6 + 50;
int n, f[N][10], a[N], vis[N];
char s[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    int m = strlen(s + 1);
    for (int j = 1; j <= m; ++j) ++f[m - j + 1][s[j] - 'a'];
    vis[s[1] - 'a'] = 1;
  }
  for (int i = 0; i <= 9; ++i) a[i] = i;
  long long ans = 1e18;
  do {
    if (vis[a[0]]) continue;
    long long ret = 0, now = 1;
    for (int i = 1; i <= 7; ++i) {
      for (int j = 1; j <= 9; ++j) ret += f[i][a[j]] * j * now;
      now *= 10;
    }
    ans = min(ans, ret);
  } while (next_permutation(a, a + 10));
  printf("%lld\n", ans);
}
