#include <bits/stdc++.h>
using namespace std;

int ans;
int dp[2][202][202];
int n, k, d;

// Checker functions
void check_high_iterations_invariant(int n, int k) {
    if (n > 80 && k > 80) { // Assume 80 is a high threshold within the constraint of 100
        cerr << "Warning: Performance bottleneck condition triggered - high loop iterations due to large n and k!" << endl;
        abort();
    }
}

void check_array_update_invariant(int n, int k) {
    if (n * k > 8000) { // A high threshold indicating frequent array updates
        cerr << "Warning: Performance bottleneck condition triggered - frequent array updates in nested loops!" << endl;
        abort();
    }
}

void check_modulo_operations_invariant(int n, int k) {
    if (n * k > 8000) { // Same threshold as it involves the same loop depth
        cerr << "Warning: Performance bottleneck condition triggered - accumulated modulo operations!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &d);
    
    // Check invariants after input
    check_high_iterations_invariant(n, k);
    check_array_update_invariant(n, k);
    check_modulo_operations_invariant(n, k);

    if (n >= d and n <= k) ans++;
    for (int i = 1; i <= k; i++) dp[0][i][i] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= n; l++)
                for (int h = 1; h <= k; h++) {
                    dp[1][l + j][max(h, j)] += dp[0][l][h];
                    dp[1][l + j][max(h, j)] %= 1000000007;
                }
        }
        for (int j = d; j <= k; j++) ans = (ans + dp[1][n][j]) % 1000000007;
        memcpy(dp[0], dp[1], sizeof(dp[0]));
        memset(dp[1], 0, sizeof(dp[1]));
    }
    printf("%d\n", ans);
}