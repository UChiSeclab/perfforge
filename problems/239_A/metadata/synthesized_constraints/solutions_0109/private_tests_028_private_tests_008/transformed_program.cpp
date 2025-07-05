#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;

inline long long add(long long x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}

inline long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}

inline long long mul(long long x, long long y) { return (x * y) % mod; }

inline long long powr(long long a, long long b) {
  long long x = 1 % mod;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}

inline long long inv(long long a) { return powr(a, mod - 2); }

// Performance checkers
void check_large_iteration_range(long long n, long long k) {
    if (n / k > 100000) {  // Arbitrary threshold to detect large iteration range
        cerr << "Warning: Performance bottleneck condition triggered - large iteration range!" << endl;
        abort();
    }
}

void check_low_filtering_condition(long long n, long long y, long long k) {
    if (y < k && n / k > 1000) {  // Condition where i*k > y rarely filters out iterations
        cerr << "Warning: Performance bottleneck condition triggered - low filtering by condition!" << endl;
        abort();
    }
}

void solve() {
  long long y, n, k, fg = 1;
  cin >> y >> k >> n;

  // Check for performance conditions
  check_large_iteration_range(n, k);
  check_low_filtering_condition(n, y, k);

  for (long long i = 1; i < (n / k) + 1; i++) {
    if (i * k > y) {
      fg = 0;
      cout << i * k - y << " ";
    }
  }

  if (fg) cout << "-1";
  return;
}

signed main() {
  long long t = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (t--) {
    solve();
  }
  return 0;
}