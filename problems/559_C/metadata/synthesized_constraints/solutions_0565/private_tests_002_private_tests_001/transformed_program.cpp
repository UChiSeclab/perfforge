#include <bits/stdc++.h>
using namespace std;
long long h, w, n;
pair<long long, long long> a[2005];
long long fact[200005];
long long ifact[200005];
long long dp[2005];

long long exp(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0) {
    long long r = exp(a, b / 2);
    return (r * r) % 1000000007;
  }
  long long r = exp(a, b - 1);
  return (r * a) % 1000000007;
}

long long C(long long n, long long k) {
  return (((fact[n] * ifact[k]) % 1000000007) * ifact[n - k]) % 1000000007;
}

// Checker functions to detect performance bottlenecks
void check_large_dimensions_invariant(long long h, long long w) {
    if (h > 50000 && w > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered - large factorial precomputation!" << endl;
        abort();
    }
}

void check_high_computation_invariant(long long h, long long w) {
    if (h > 90000 || w > 90000) {
        cerr << "Warning: Performance bottleneck condition triggered - high computational load due to large dimensions!" << endl;
        abort();
    }
}

void check_sparse_black_cells_invariant(long long n, long long h, long long w) {
    if (n < 10 && (h > 95000 || w > 95000)) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse black cells with large board dimensions!" << endl;
        abort();
    }
}

int main() {
  scanf("%lld %lld %lld", &h, &w, &n);

  // Insert checker function calls after reading inputs
  check_large_dimensions_invariant(h, w);
  check_high_computation_invariant(h, w);
  check_sparse_black_cells_invariant(n, h, w);

  for (long long i = 0; i < n; i++) {
    scanf("%lld %lld", &a[i].first, &a[i].second);
    a[i].first--;
    a[i].second--;
  }
  sort(a, a + n);
  a[n++] = make_pair(h - 1, w - 1);
  fact[0] = 1;
  ifact[0] = 1;
  for (long long i = 1; i <= max(w, h) * 2; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
    ifact[i] = exp(fact[i], 1000000007 - 2);
  }
  for (long long i = 0; i < n; i++) {
    long long num = C(a[i].first + a[i].second, a[i].first);
    for (long long j = 0; j < i; j++) {
      if (a[j].first <= a[i].first && a[j].second <= a[i].second) {
        int sub =
            (dp[j] * C((a[i].first - a[j].first) + (a[i].second - a[j].second),
                       a[i].first - a[j].first)) %
            1000000007;
        num = (num - sub + 1000000007) % 1000000007;
      }
    }
    dp[i] = num;
  }
  cout << dp[n - 1] << endl;
}