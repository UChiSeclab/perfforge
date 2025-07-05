#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;

// Function to compute power modulo M
long long pwr(long long a, long long b, long long m = M) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1) ret = ret * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ret;
}

// Checker for repeated power calculations
void check_repeated_power_calculations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to repeated power calculations!" << endl;
        abort();
    }
}

// Checker for combinatorial and factorial overhead
void check_combinatorial_overhead(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to large combinatorial calculations!" << endl;
        abort();
    }
}

// Checker for loop-intensive calculations
void check_loop_intensive_calculations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to intensive loop calculations!" << endl;
        abort();
    }
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;

  // Check for performance bottlenecks based on input conditions
  check_repeated_power_calculations(k == 0);  // Check if k is 0, leading to high power calculations
  check_combinatorial_overhead(n >= 100000);  // Check if n is very large, causing overhead
  check_loop_intensive_calculations(n == k);  // Check if n equals k, triggering full loop iterations

  if (k >= n) {
    cout << 0 << '\n';
    return 0;
  }
  k = n - k;
  vector<long long> fac(5e5), inv = fac;
  inv[0] = fac[0] = 1;
  for (int i = 1; i < 5e5; ++i) {
    fac[i] = i * fac[i - 1] % M;
    inv[i] = pwr(fac[i], M - 2);
  }
  auto ncr = [&](int nn, int rr) {
    return (fac[nn] * (inv[rr] * inv[nn - rr] % M) % M);
  };
  long long ans = 0;
  for (int i = 0; i < k; ++i) {
    long long cur = ncr(k, i) * pwr(k - i, n) % M;
    if (i & 1)
      ans = (ans - cur + M) % M;
    else
      ans = (ans + cur) % M;
  }
  ans = ans * ncr(n, k) % M;
  if (k != n) ans = ans * 2 % M;
  cout << ans << '\n';
}