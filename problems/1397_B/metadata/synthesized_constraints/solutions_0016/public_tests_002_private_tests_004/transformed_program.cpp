#include <bits/stdc++.h>
using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

// Checker Functions
void check_iteration_invariant(long long c, int n) {
    if (pow(c, n - 1) < 1e13) {
        cerr << "Warning: Performance bottleneck condition triggered due to high iteration count!" << endl;
        abort();
    }
}

void check_cost_invariant(long long cost, int n) {
    if (cost > 1e12 * n) { // Arbitrary large threshold for cost
        cerr << "Warning: Performance bottleneck condition triggered due to large cost calculation!" << endl;
        abort();
    }
}

void check_small_n_large_values_invariant(long long* a, int n) {
    long long maxValue = *max_element(a, a + n);
    if (n < 10 && maxValue > 1e8) { // Example condition for small n and large values
        cerr << "Warning: Performance bottleneck condition triggered due to small n and large values!" << endl;
        abort();
    }
}

void solve() {
  int n;
  cin >> n;
  long long a[n];

  for (int i = 0; i < n; i++) cin >> a[i];

  // Check for small n and large values
  check_small_n_large_values_invariant(a, n);

  sort(a, a + n);
  long long c = 1, minCost = 1e17, f = 0, ans;

  // Main loop checker
  while (pow(c, n - 1) < 1e13) {
    long long cost = 0;

    for (int i = 0; i < n; i++) {
      cost += abs(a[i] - pow(c, i));
    }

    // Cost computation checker
    check_cost_invariant(cost, n);

    minCost = min(minCost, cost);
    c++;

    // Iteration count checker
    check_iteration_invariant(c, n);
  }

  cout << minCost << "\n";
}

int main() {
  fast_io();
  solve();
  return 0;
}