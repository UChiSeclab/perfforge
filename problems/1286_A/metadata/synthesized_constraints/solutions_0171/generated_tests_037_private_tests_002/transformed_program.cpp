#include <bits/stdc++.h>

template <class T>
std::vector<T> vec(int len, T elem) {
  return std::vector<T>(len, elem);
}

constexpr int INF = 1 << 30;

// Checker function for missing bulbs
void check_missing_bulbs_invariant(int missingBulbs, int n) {
    if (missingBulbs > n / 2) { // Condition to check if there are many missing bulbs
        std::cerr << "Warning: Performance bottleneck condition triggered - too many missing bulbs!" << std::endl;
        abort();
    }
}

// Checker function for balancing odds and evens
void check_balancing_invariant(int evens, int odds) {
    if (abs(evens - odds) < 10) { // Threshold for balancing odds and evens
        std::cerr << "Warning: Performance bottleneck condition triggered - challenging balance between odds and evens!" << std::endl;
        abort();
    }
}

// Checker function for DP size
void check_dp_size_invariant(int n) {
    if (n > 75) { // Arbitrary threshold based on problem constraints
        std::cerr << "Warning: Performance bottleneck condition triggered - large DP table size!" << std::endl;
        abort();
    }
}

int main() {
  int n;
  std::cin >> n;

  // Check for large DP tables
  check_dp_size_invariant(n);

  int evens = n / 2;
  int odds = n - evens;
  std::vector<int> xs(n);
  int missingBulbs = 0;

  for (auto& x : xs) {
    std::cin >> x;
    if (x == 0) {
      x = -1;
      missingBulbs++; // Count missing bulbs
      continue;
    }
    x %= 2;
    --(x == 0 ? evens : odds);
  }

  // Check for too many missing bulbs
  check_missing_bulbs_invariant(missingBulbs, n);

  // Check for challenging balance between odds and evens
  check_balancing_invariant(evens, odds);

  auto dp = vec(n + 1, vec(n + 1, vec(2, INF)));
  if (xs[0] < 0) {
    if (odds > 0) {
      dp[odds - 1][evens][1] = 0;
    }
    if (evens > 0) {
      dp[odds][evens - 1][0] = 0;
    }
  } else {
    dp[odds][evens][xs[0]] = 0;
  }
  for (int i = 1; i < n; ++i) {
    auto ndp = vec(n + 1, vec(n + 1, vec(2, INF)));
    int x = xs[i];
    for (int odd = 0; odd <= n; ++odd) {
      for (int even = 0; even <= n; ++even) {
        if (x < 0) {
          if (odd > 0) {
            ndp[odd - 1][even][1] =
                std::min(dp[odd][even][1], dp[odd][even][0] + 1);
          }
          if (even > 0) {
            ndp[odd][even - 1][0] =
                std::min(dp[odd][even][1] + 1, dp[odd][even][0]);
          }
        } else {
          ndp[odd][even][x] = std::min(dp[odd][even][0] + (x != 0),
                                       dp[odd][even][1] + (x != 1));
        }
      }
    }
    dp = ndp;
  }
  std::cout << std::min(dp[0][0][0], dp[0][0][1]) << std::endl;
  return 0;
}