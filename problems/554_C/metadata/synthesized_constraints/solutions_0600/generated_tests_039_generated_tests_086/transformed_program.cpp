#include <bits/stdc++.h>
using namespace std;

long long nck[1005][1005];

long long m(long long a) {
  return ((a % 1000000007) + 1000000007) % 1000000007;
}

// Recursive Depth Checker
void check_recursive_depth(int n, int r) {
    if (n > 50 && r > 25) {
        cerr << "Warning: Performance bottleneck condition triggered - large recursive depth!" << endl;
        abort();
    }
}

// Memoization Effectiveness Checker
void check_memoization_effectiveness(int n, int r, long long nckValue) {
    if (nckValue == 0 && n > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - ineffective memoization!" << endl;
        abort();
    }
}

long long ncr(long long n, long long r) {
    check_recursive_depth(n, r); // Check before recursion depth increases
    if (r > n) return 0ll;
    if (n == r || r == 0) return 1ll;
    if (nck[n][r] != 0) return nck[n][r];
    long long result = m(ncr(n - 1, r) + ncr(n - 1, r - 1));
    nck[n][r] = result;
    check_memoization_effectiveness(n, r, nck[n][r]); // Check memoization effectiveness
    return nck[n][r];
}

// Combination Computations Checker
void check_combination_computations(int sm, int currentColorBalls) {
    if (sm > 500 && currentColorBalls > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - heavy combination computations!" << endl;
        abort();
    }
}

int main() {
  int k;
  scanf("%d", &k);
  vector<int> a(k);
  for (int &i : a) scanf("%d", &i);
  vector<long long> dp(1005);
  dp[1] = 1;
  long long sm = a[0];
  for (int i = 2; i <= k; i++) {
    sm += a[i - 1];
    check_combination_computations(sm, a[i - 1]); // Check before performing heavy computations
    dp[i] = m(dp[i - 1] * ncr(sm - 1, a[i - 1] - 1));
  }
  printf("%lld\n", dp[k]);
}