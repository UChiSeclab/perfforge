#include <bits/stdc++.h>
const long long mod = 998244353;

struct Element {
  int r, c;
  long long v;
  Element() {}
  Element(int r, int c, long long v) : r(r), c(c), v(v) {}
};

Element a[10000005];
long long ans[1005][1005];

long long power(long long a, long long b) {
  long long res = 1;
  int callCount = 0;  // To track how many times this function is called
  while (b) {
    if (b % 2) res = res * a % mod;
    a = a * a % mod;
    b /= 2;
    callCount++;
  }
  check_power_function_invariant(callCount); // Check for excessive calls
  return res;
}

long long inv(long long u) { return power(u, mod - 2); }

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      long long v;
      scanf("%lld", &v);
      a[(i - 1) * m + j] = Element(i, j, v);
    }
  }
  
  int all = n * m;
  check_sort_invariant(all); // Check before sorting if number of elements is large

  std::sort(a + 1, a + 1 + all,
            [](Element& u, Element& v) { return u.v < v.v; });

  int x0, y0;
  scanf("%d%d", &x0, &y0);
  long long sqSum = 0, xSum = 0, ySum = 0, eSum = 0;
  int p = 1;
  int uniqueValueCount = 0; // To track unique values processed

  while (p <= all) {
    int np = p;
    while (np + 1 <= all && a[np + 1].v == a[p].v) np++;
    
    // Counting unique values
    uniqueValueCount++;

    for (int i = p; i <= np; i++) {
      long long r = a[i].r, c = a[i].c;
      long long E =
          (sqSum + (p - 1) * 1ll * (r * r + c * c) % mod + eSum) % mod;
      E = (E - 2ll * r * xSum % mod - 2ll * c * ySum % mod) % mod;
      if (E < 0) E += mod;
      E = E * inv(p - 1) % mod;
      ans[r][c] = E;
    }
    for (int i = p; i <= np; i++) {
      long long r = a[i].r, c = a[i].c;
      sqSum = (sqSum + r * r % mod + c * c % mod) % mod;
      eSum = (eSum + ans[r][c]) % mod;
      xSum = (xSum + r) % mod;
      ySum = (ySum + c) % mod;
    }
    p = np + 1;
  }

  check_main_loop_invariant(uniqueValueCount); // Check for excessive accumulation

  printf("%lld\n", ans[x0][y0]);
  return 0;
}