#include <bits/stdc++.h>
using namespace std;
int dp[111][111][111];
int mod = 1e9 + 7;

void check_large_combinatorial_invariant(int n, int k) {
    if (n > 80 && k > 80) { // Adjust threshold based on problem constraints.
        cerr << "Warning: Performance bottleneck - large combinatorial search space!" << endl;
        abort();
    }
}

void check_high_loop_interaction_invariant(int k) {
    if (k > 90) { // Threshold as `k` nears its upper constraint.
        cerr << "Warning: Performance bottleneck - high loop interaction due to k!" << endl;
        abort();
    }
}

void check_memory_overhead_invariant(int n) {
    if (n > 90) { // Threshold for large `n` impacts memory usage.
        cerr << "Warning: Performance bottleneck - memory and computation overhead!" << endl;
        abort();
    }
}

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    // Insert checks after reading input values
    check_large_combinatorial_invariant(n, k);
    check_high_loop_interaction_invariant(k);
    check_memory_overhead_invariant(n);

    for (int i = 1; i <= (n); i++) dp[0][i][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            for (int s = 0; s <= n; s++)
                for (int l = 1; l <= k; l++)
                    if (s + l <= n) {
                        if (l > j) {
                            dp[i][l][s + l] += dp[i - 1][j][s];
                            dp[i][l][s + l] %= mod;
                        } else {
                            dp[i][j][s + l] += dp[i - 1][j][s];
                            dp[i][j][s + l] %= mod;
                        }
                    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = d; j <= k; j++) {
            ans += dp[i][j][n];
            ans %= mod;
        }
    cout << ans << endl;
    int x;
    cin >> x;
}