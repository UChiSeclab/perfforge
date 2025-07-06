#include <bits/stdc++.h>
const int MOD = 1000000007;
inline int add(int a, int b) { return (a += b) >= MOD ? a - MOD : a; }
inline int sub(int a, int b) { return (a -= b) < 0 ? a + MOD : a; }
inline int mul(int a, int b) { return 1ll * a * b % MOD; }
inline int qpow(int a, int p) {
  int ret = 1;
  for (p += (p < 0) * (MOD - 1); p; p >>= 1, a = mul(a, a))
    if (p & 1) ret = mul(ret, a);
  return ret;
}
const int MAXN = 5010;
int Strb[MAXN][MAXN];
int fac[MAXN];
int inv[MAXN];
int n, k;

// Checker to detect if k is large, potentially causing slow quadratic operations
void check_stirling_invariant(int k) {
    if (k > 4000) { // Threshold chosen considering upper limit and problem context
        cerr << "Warning: Performance bottleneck condition triggered - large k causing heavy Stirling number computations!" << endl;
        abort();
    }
}

// Checker to detect potential performance issues from large exponentiation operations
void check_exponentiation_invariant(int n, int k) {
    if (n > 100000 && k > 1000) { // Arbitrary threshold to detect performance impact
        cerr << "Warning: Performance bottleneck condition triggered - large n and k causing repeated exponentiation!" << endl;
        abort();
    }
}

int main() {
  std::cin >> n >> k;

  // Perform checks for potential bottlenecks
  check_stirling_invariant(k);
  check_exponentiation_invariant(n, k);

  if (n <= k) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    inv[n] = qpow(fac[n], MOD - 2);
    for (int i = n; i >= 1; --i) inv[i - 1] = mul(inv[i], i);
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
      ans = add(ans, mul(mul(fac[n], mul(inv[i], inv[n - i])), qpow(i, k)));
    }
    printf("%d\n", ans);
    return 0;
  }
  Strb[0][0] = 1;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= i; ++j)
      Strb[i][j] = add(Strb[i - 1][j - 1], mul(j, Strb[i - 1][j]));
  int ans = 0, p = n;
  for (int i = 1; i <= k; p = mul(p, n - i), ++i) {
    ans = add(ans, mul(Strb[k][i], mul(p, qpow(2, n - i))));
  }
  printf("%d\n", ans);
}