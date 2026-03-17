#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int read() {
  char ch = getchar();
  int w = 1, s = 0;
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  };
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return w * s;
}
inline long long ksm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
inline long long rev(long long x) { return ksm(x, mod - 2); }
inline long long sqr(long long x) { return x * x % mod; }
inline long long add(long long a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
struct node {
  long long x, y, w;
} Ma[1000010];
int n, m;
long long p[1000010], mat[1010][1010], F[1000010];
inline bool cmp(node p, node q) { return p.w < q.w; }
int main() {
  n = read(), m = read();
  int cnt = 0;
  for (register int i = 1; i <= n; ++i) {
    for (register int j = 1; j <= m; ++j) {
      mat[i][j] = read();
    }
  }
  long long r = read(), c = read();
  int tmp = mat[r][c];
  Ma[++cnt].w = tmp;
  Ma[cnt].x = r, Ma[cnt].y = c;
  for (register int i = 1; i <= n; ++i) {
    for (register int j = 1; j <= m; ++j) {
      if (tmp > mat[i][j]) {
        Ma[++cnt].w = mat[i][j];
        Ma[cnt].x = i, Ma[cnt].y = j;
      }
    }
  }
  sort(Ma + 1, Ma + cnt + 1, cmp);
  Ma[0].w = -1e9 - 10;
  Ma[cnt + 1].w = -1e9 - 10;
  long long Sum1 = 0, Sum2 = 0, Sum3 = 0, Sum4 = 0, res = 0;
  int j = 0;
  for (register int i = 1; i <= cnt; i = j + 1) {
    j = i;
    while (Ma[j + 1].w == Ma[j].w) j++;
    if (i == 1) {
      for (register int k = i; k <= j; ++k) {
        F[k] = 0;
        Sum1 = add(Sum1, sqr(Ma[k].x));
        Sum2 = add(Sum2, sqr(Ma[k].y));
        Sum3 = add(Sum3, Ma[k].x);
        Sum4 = add(Sum4, Ma[k].y);
      }
      continue;
    }
    for (register int k = i; k <= j; ++k) {
      F[k] = (1ll *
                  (sqr(Ma[k].x) + sqr(Ma[k].y) + 1ll * Sum1 * rev(i - 1) % mod +
                   1ll * Sum2 * rev(i - 1) % mod -
                   2ll * Sum3 * rev(i - 1) % mod * Ma[k].x % mod -
                   2ll * Sum4 * rev(i - 1) % mod * Ma[k].y % mod) %
                  mod +
              mod + res * rev(i - 1) % mod) %
             mod;
    }
    for (register int k = i; k <= j; ++k) {
      Sum1 = add(Sum1, sqr(Ma[k].x));
      Sum2 = add(Sum2, sqr(Ma[k].y));
      Sum3 = add(Sum3, Ma[k].x);
      Sum4 = add(Sum4, Ma[k].y);
      res = add(F[k], res);
    }
  }
  cout << F[cnt] << "\n";
  return 0;
}
