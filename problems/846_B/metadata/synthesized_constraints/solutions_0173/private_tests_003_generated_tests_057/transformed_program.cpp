#include <bits/stdc++.h>
using namespace std;

// Function to check the DP initialization bottleneck
void check_dp_initialization(int n, int k) {
    if ((n * (k + 1)) > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large DP table initialization!" << endl;
        abort();
    }
}

// Function to check the DP updates bottleneck
void check_dp_updates(int n, int k) {
    if ((n * (k + 1) * k) > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive DP updates!" << endl;
        abort();
    }
}

// Function to check the possible points bottleneck
void check_possible_points(int n, int k) {
    if ((n * (k + 1)) > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of possible points!" << endl;
        abort();
    }
}

int n, k;
long long m;
int t[50];
long long dp[50][2505];

int main(void) {
    scanf("%d%d%lld", &n, &k, &m);

    // Insert checks after reading inputs
    check_dp_initialization(n, k); // Check for DP initialization bottleneck
    check_dp_updates(n, k);        // Check for DP updates bottleneck
    check_possible_points(n, k);   // Check for possible points bottleneck

    for (int i = 0; i < k; i++) {
        scanf("%d", &t[i]);
    }
    sort(t, t + k);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n * (k + 1); j++) {
            dp[i][j] = 1000000000007;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i * (k + 1); j++) {
            if (dp[i][j] < 1000000000007) {
                long long cost = 0;
                for (int a = 0; a <= k; a++) {
                    dp[i + 1][j + a + (a == k ? 1 : 0)] =
                        min(dp[i + 1][j + a + (a == k ? 1 : 0)], dp[i][j] + cost);
                    cost += (long long)t[a];
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= (k + 1) * n; i++) {
        if (m >= dp[n][i]) {
            res = max(res, i);
        }
    }
    printf("%d\n", res);
    return 0;
}