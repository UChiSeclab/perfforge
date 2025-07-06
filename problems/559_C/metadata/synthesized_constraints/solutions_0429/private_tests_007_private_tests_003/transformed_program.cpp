#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 2010;
const int mod = 1e9 + 7;
struct dd {
  int x, y;
};
dd a[M];
int f[M];
long long inv[N << 1], fac[N << 1];

// Checker for large board dimensions
void check_large_dimension_invariant(int h, int w) {
    if ((h + w) > 200000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large board dimensions!" << endl;
        abort();
    }
}

// Checker for high number of black cells
void check_black_cells_invariant(int n) {
    if (n > 1900) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of black cells!" << endl;
        abort();
    }
}

// Function to read input
int re() {
  int x = 0;
  char c = getchar();
  bool p = 0;
  for (; c < '0' || c > '9'; c = getchar()) p = (c == '-' || p) ? 1 : 0;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c - '0');
  return p ? -x : x;
}

int comp(dd x, dd y) {
  if (x.x == y.x) return x.y < y.y;
  return x.x < y.x;
}

int ksm(int x, int y) {
  int s = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod)
    if (y & 1) s = 1LL * s * x % mod;
  return s;
}

int C(int x, int y) { return fac[y] * inv[x] % mod * inv[y - x] % mod; }

int main() {
  int i, j, h, w, n, o;
  h = re();
  w = re();
  n = re();

  // Place checkers after reading input
  check_large_dimension_invariant(h, w);
  check_black_cells_invariant(n);

  for (i = 1; i <= n; i++) {
    a[i].x = re();
    a[i].y = re();
  }
  sort(a + 1, a + n + 1, comp);
  for (fac[0] = i = 1, o = h + w; i <= o; i++) fac[i] = fac[i - 1] * i % mod;
  inv[o] = ksm(fac[o], mod - 2);
  for (i = o - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  a[n + 1].x = h;
  a[n + 1].y = w;
  for (i = 1; i <= n + 1; i++) {
    f[i] = C(a[i].x - 1, a[i].x + a[i].y - 2);
    for (j = 1; j < i; j++)
      if (a[j].x <= a[i].x && a[j].y <= a[i].y)
        f[i] =
            (f[i] - 1LL * f[j] *
                        C(a[i].x - a[j].x, a[i].x + a[i].y - a[j].x - a[j].y) %
                        mod) %
            mod;
  }
  printf("%d", (f[n + 1] + mod) % mod);
  return 0;
}