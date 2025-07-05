#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
long long int dp[260][260];
long long int cached[260][260];
long long int cc[260][260];
int n, k1;

// Function to check exponential growth invariant
void check_exponential_growth_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to large k triggering excessive modular exponentiation!" << endl;
        abort();
    }
}

// Function to check combinatorial explosion invariant
void check_combinatorial_explosion_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to deep recursive combinatorial computations!" << endl;
        abort();
    }
}

// Function to check nested loop invariant
void check_nested_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to excessive nested loop iterations!" << endl;
        abort();
    }
}

// Function to check memory utilization invariant
void check_memory_utilization_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to high memory consumption affecting cache utilization!" << endl;
        abort();
    }
}

long long int modExpo1(long long int a, long long int b) {
  long long int res = 1;
  for (long long int i = b; i; i = i >> 1, a = (a * a) % 1000000007)
    if (i & 1) res = (res * a) % 1000000007;
  return res;
}

long long int values[260], values1[260];

long long int modExpo(long long int a, long long int b) {
  if (a == k1 - 1)
    return values1[b];
  else
    return values[b];
}

long long int nCr(int n, int r) {
  if (n < 0 || r < 0) return 0;
  if (r == 0) return 1;
  if (n == r) return 1;
  if (r > n) return 0;
  if (n == 0) return 0;
  if (cached[n][r]) return cc[n][r];
  cached[n][r] = true;
  return cc[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % 1000000007;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t clk = clock();
  cin >> n >> k1;

  // Inserted checks after input reading
  check_exponential_growth_invariant(k1 > 10000); // Large k triggers exponential growth
  check_combinatorial_explosion_invariant(n > 200); // High n can cause combinatorial explosions
  check_memory_utilization_invariant(n > 200); // High n impacts memory/cache

  nCr(260 - 1, 260 - 1);
  for (int i = 0; i < 260; i++)
    values1[i] = modExpo1(k1 - 1, i), values[i] = modExpo1(k1, i);
  if (k1 == 1) {
    cout << 1 << endl;
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n + 1; j++) {
      dp[i][j] +=
          (((((modExpo(k1, j) + 1000000007 - modExpo(k1 - 1, j)) % 1000000007) *
             dp[i - 1][j]) %
            1000000007) *
           modExpo(k1 - 1, n - j)) %
          1000000007;
      dp[i][j] %= 1000000007;

      // Nested loop check
      check_nested_loop_invariant(i > 200 && j > 200); // Excessive iterations

      for (int k = 1; k <= n; k++) {
        if (j + k > n) continue;
        long long int temp = modExpo(k1, j) * nCr(n - j, k);
        temp %= 1000000007;
        temp *= dp[i - 1][j];
        temp %= 1000000007;
        temp *= modExpo(k1 - 1, n - j - k);
        temp %= 1000000007;
        dp[i][j + k] += temp;
        dp[i][j + k] %= 1000000007;
      }
    }
  }
  cout << dp[n][n] % 1000000007 << endl;
  cerr << endl
       << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
  return 0;
}