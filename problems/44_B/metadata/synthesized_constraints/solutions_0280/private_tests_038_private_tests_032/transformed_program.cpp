#include <bits/stdc++.h>

// Checker functions
void check_high_sum_invariant(int sum) {
    if (sum > 19900) { // Checking if doubled `n` is close to max constraint
        cerr << "Warning: Performance bottleneck condition triggered - Sum too high!" << endl;
        abort();
    }
}

void check_large_bottle_invariant(int a, int b, int c) {
    if (a > 4500 || b > 4500 || c > 4500) { // Checking if bottle counts are close to their max constraint
        cerr << "Warning: Performance bottleneck condition triggered - Large number of available bottles!" << endl;
        abort();
    }
}

void check_combinatorial_explosion_invariant(int sum, int a, int b, int c) {
    if (sum > 19000 && (a > 4000 || b > 4000 || c > 4000)) {
        // This checks a combination where both `sum` and available bottles are large
        cerr << "Warning: Performance bottleneck condition triggered - Combinatorial explosion potential!" << endl;
        abort();
    }
}

int dp[20001][4];
int a[3];
int main() {
    int N, sum;
    scanf("%d %d %d %d", &sum, &a[0], &a[1], &a[2]);
    
    // Apply the performance checks before processing
    sum <<= 1;
    check_high_sum_invariant(sum);
    check_large_bottle_invariant(a[0], a[1], a[2]);
    check_combinatorial_explosion_invariant(sum, a[0], a[1], a[2]);

    N = 3;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int n = 0; n < N; ++n) {
        for (int s = 0; s < sum + 1; ++s) {
            for (int i = 0; i < a[n] + 1; ++i) {
                if (s < (1 << n) * i) break;
                dp[s][n + 1] += dp[s - (1 << n) * i][n];
            }
        }
    }
    printf("%d\n", dp[sum][N]);
    return 0;
}