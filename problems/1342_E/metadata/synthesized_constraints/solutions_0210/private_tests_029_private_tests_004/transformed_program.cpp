#include <bits/stdc++.h>
using namespace std;

int n;
long long k;

// Checker functions
void check_pow_invariant(int n, long long k, int i, int threshold) {
    if (n - i >= threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive modular exponentiation!" << endl;
        abort();
    }
}

void check_combination_invariant(int n, long long k, int threshold) {
    if (k < threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent combination calculations!" << endl;
        abort();
    }
}

void check_loop_invariant(int n, long long k, int threshold) {
    if (k < threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive loop iterations!" << endl;
        abort();
    }
}

int Pow(int x, int a) {
  int ret = 1;
  while (a) {
    if (a & 1) ret = ret * 1ll * x % 998244353;
    x = x * 1ll * x % 998244353, a >>= 1;
  }
  return ret;
}

int J[500006], iJ[500006];

int C(int a, int b) {
  return J[a] * 1ll * iJ[b] % 998244353 * iJ[a - b] % 998244353;
}

void solve() {
  cin >> n >> k;

  // Performance checkers to catch bottleneck conditions
  check_combination_invariant(n, k, 1);
  check_loop_invariant(n, k, 1);

  if (k >= n) return puts("0"), void();
  
  J[0] = iJ[0] = 1;
  for (int i = 1, iend = (n << 1); i <= iend; ++i)
    J[i] = J[i - 1] * 1ll * i % 998244353, iJ[i] = Pow(J[i], 998244353 - 2);
  
  if (k == 0) return cout << J[n] << endl, void();
  
  int res = 0;
  for (int i = k, iend = n; i <= iend; ++i) {
    // Check for modular exponentiation overhead
    check_pow_invariant(n, k, i, n / 2); // Arbitrary threshold for demonstration

    res = (res + (i - k & 1 ? 998244353 - 1 : 1) * 1ll * C(n, n - i) %
                     998244353 * Pow(n - i, n) % 998244353 * C(i, k)) %
          998244353;
  }
  
  cout << res * 2 % 998244353 << endl;
}

signed main() {
  solve();
}