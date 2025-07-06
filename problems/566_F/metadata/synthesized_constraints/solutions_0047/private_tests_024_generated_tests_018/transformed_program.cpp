#include <bits/stdc++.h>
using namespace std;
int a[1000002], dp[1000002];

// Checkers for performance bottlenecks
void check_low_divisor_invariant(int value) {
    if (value == 1) {
        cerr << "Warning: Performance bottleneck condition triggered due to low divisor value (1)!" << endl;
        abort();
    }
}

void check_high_multiples_iterations(int value, int limit) {
    if (value * 2 < limit) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of multiples!" << endl;
        abort();
    }
}

int main() {
  int n, i, j, ans = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    dp[a[i]] = 1;
    // Check for low divisor value
    check_low_divisor_invariant(a[i]);
  }
  for (i = 0; i < n; i++) {
    int x = a[i];
    // Check for high multiples iterations before entering the nested loop
    check_high_multiples_iterations(x, 1000001);
    for (j = 2; x * j < 1000001; j++) {
      dp[j * x] = max(dp[x] + 1, dp[j * x]);
    }
  }
  for (i = 0; i < n; i++) {
    ans = max(ans, dp[a[i]]);
  }
  cout << ans << endl;
  return 0;
}