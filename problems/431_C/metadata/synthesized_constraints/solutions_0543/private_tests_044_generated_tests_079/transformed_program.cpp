#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k, d;
int dp[105][105][2];

void check_recursive_depth_invariant(int currentDepth, int n, int k) {
    if (currentDepth > 50 && n > 90) { // Example threshold based on problem constraints
        cerr << "Warning: Performance bottleneck triggered due to high recursive depth with large n!" << endl;
        abort();
    }
}

void check_branching_factor_invariant(int k, int n) {
    if (k > 80 && n > 90) { // Example threshold based on problem constraints
        cerr << "Warning: Performance bottleneck triggered due to large branching factor!" << endl;
        abort();
    }
}

int go(int cur = 0, int sum = 0, bool has = 0) {
  check_recursive_depth_invariant(cur, n, k); // Check for recursive depth
  if (sum > n) {
    return 0;
  } else if (has && sum == n) {
    return 1;
  }
  if (dp[cur][sum][has] != -1) {
    return dp[cur][sum][has];
  }
  dp[cur][sum][has] = 0;
  for (int i = 1; i <= k; i++) {
    dp[cur][sum][has] =
        (0LL + dp[cur][sum][has] + go(cur + 1, sum + i, (i >= d) | has)) % mod;
  }
  return dp[cur][sum][has];
}

int main() {
  cin >> n >> k >> d;
  check_branching_factor_invariant(k, n); // Check for branching factor
  for (int i = 0; i <= 101; i++) {
    for (int j = 0; j <= 101; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cout << go() << "\n";
  return 0;
}