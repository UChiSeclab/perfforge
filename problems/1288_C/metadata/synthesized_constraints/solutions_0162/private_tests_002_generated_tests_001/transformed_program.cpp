#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, m, dp[12][1005][1005];

// Check if recursion is likely to be too expensive
void check_recursion_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large recursion state space!" << endl;
        abort();
    }
}

// Check for large DP table initialization
void check_initialization_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large DP table initialization!" << endl;
        abort();
    }
}

// Check for large combinatorial complexity
void check_combinatorial_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large combinatorial complexity!" << endl;
        abort();
    }
}

int f(int i, int a, int b) {
    if (a < 1 || b > n) return 0;
    if (i == m + 1) return 1;
    if (dp[i][a][b] != -1) return dp[i][a][b];
    int ans = (f(i, a + 1, b) + f(i, a, b - 1)) % MOD;
    ans = (ans - f(i, a + 1, b - 1) + MOD) % MOD;
    if (a <= b) ans = (ans + f(i + 1, a, b)) % MOD;
    return dp[i][a][b] = ans;
}

int main() {
    scanf("%d %d", &n, &m);
    
    // Check if n and m are likely to cause deep recursion
    check_recursion_invariant(n > 500 && m >= 9);
    
    // Check for large DP table initialization
    check_initialization_invariant(n * m > 5000);
    
    // Check if the combinatorial complexity is too high
    check_combinatorial_invariant(n > 900 && m > 8);

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) dp[i][j][k] = -1;

    printf("%d\n", f(1, 1, n));
    return 0;
}