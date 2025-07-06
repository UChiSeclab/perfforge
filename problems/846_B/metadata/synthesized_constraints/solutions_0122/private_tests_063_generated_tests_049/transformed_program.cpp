#include <bits/stdc++.h>
using namespace std;
int n, k, m, x[50], ta;
long long dp[50 * 50 + 1];

// Invariant Checker Functions
void check_high_n_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: High 'n' value invariant triggered - many tasks causing overhead" << endl;
        abort();
    }
}

void check_high_k_and_nested_loops_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: High 'k' and nested loops invariant triggered - extensive recomputation" << endl;
        abort();
    }
}

void check_insufficient_time_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Insufficient time invariant triggered - inadequate time for tasks" << endl;
        abort();
    }
}

void check_large_dp_operations_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Large 'dp' operations invariant triggered - extensive operations on dp array" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i++) scanf("%d", x + i);
    sort(x + 1, x + k + 1);
    for (int i = 1; i <= k; i++) x[i] += x[i - 1];
    m++;

    // Check for high 'n' value invariant (potential overhead from many tasks)
    check_high_n_invariant(n > 40);

    // Check for high 'k' and nested loops invariant (extensive recomputation)
    check_high_k_and_nested_loops_invariant(n * k > 2000);

    // Check for insufficient time invariant (not enough time for all tasks)
    check_insufficient_time_invariant(m < n);

    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 2500; j >= 0; j--)
            if (dp[j])
                for (int kk = 1; kk <= k; kk++) {
                    ta = kk;
                    if (kk == k) ta++;
                    if (!dp[j + ta] || dp[j + ta] > dp[j] + x[kk])
                        dp[j + ta] = dp[j] + x[kk];
                }

    // Check for large 'dp' operations invariant (extensive operations on dp array)
    check_large_dp_operations_invariant(n * k * 2500 > 100000);

    for (int i = 2500; i >= 0; i--)
        if (dp[i] && dp[i] <= m) {
            printf("%d\n", i);
            return 0;
        }
    return 0;
}