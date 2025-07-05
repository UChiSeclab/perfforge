#include <bits/stdc++.h>

int dp[20005];
int n;
int cnt[3];

void check_initialization_invariant(int n) {
    if (n > 5000) {
        cerr << "Warning: Performance bottleneck condition triggered - large initialization range!" << endl;
        abort();
    }
}

void check_nested_loops_invariant(int cnt0, int cnt1, int cnt2) {
    if (cnt0 + cnt1 + cnt2 > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations!" << endl;
        abort();
    }
}

void check_update_invariant(int n, int a, int b, int c) {
    if (0.5 * a + b + 2 * c >= n) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent updates!" << endl;
        abort();
    }
}

void check_capacity_invariant(int n, int v, int cnti) {
    if (n < v * cnti) {
        cerr << "Warning: Performance bottleneck condition triggered - capacity exceeded!" << endl;
        abort();
    }
}

int main() {
    int i, j, a, b, c, v, k;
    scanf("%d%d%d%d", &n, &cnt[0], &cnt[1], &cnt[2]);

    // Convert n from liters to half-liters and check initialization conditions
    n = n * 2;
    check_initialization_invariant(n);

    // Check conditions for nested loops and value updates
    check_nested_loops_invariant(cnt[0], cnt[1], cnt[2]);
    check_update_invariant(n, cnt[0], cnt[1], cnt[2]);

    for (i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (i = 0; i < 3; i++) {
        if (i == 0)
            v = 1;
        else if (i == 1)
            v = 2;
        else
            v = 4;

        // Check capacity invariant for each different type of bottle size
        check_capacity_invariant(n, v, cnt[i]);

        for (j = n; j >= 0; j--) {
            if (dp[j] != 0) {
                for (k = 1; k <= cnt[i]; k++) {
                    if (j + k * v > n) break;
                    dp[j + k * v] = dp[j + k * v] + dp[j];
                }
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}