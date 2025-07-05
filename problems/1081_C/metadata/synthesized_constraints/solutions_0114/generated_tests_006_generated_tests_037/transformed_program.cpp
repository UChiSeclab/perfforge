#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int MOD = 998244353;
int N, M, K;
long long dp[MAXN][MAXN];

// Invariant checkers
void check_recursive_depth_invariant(int n, int k) {
    if (n > 1000 && k < 100) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursive depth with limited memoization!" << endl;
        abort();
    }
}

void check_branching_factor_invariant(int m, int k) {
    if (k < m / 2 && m > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - increased recursive branching factor!" << endl;
        abort();
    }
}

void check_memoization_invariant(int n, int k) {
    if (n * k > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient memoization utilization!" << endl;
        abort();
    }
}

long long ways(int n, int k) {
    // Before diving into the recursion, check for high recursion and branching factor
    check_recursive_depth_invariant(n, k);
    check_branching_factor_invariant(M, k); // Using global M

    if (n == 1) {
        if (k == 0) return M;
        return 0;
    }
    if (dp[n][k] != -1) return dp[n][k];

    // Recursive call
    return dp[n][k] = (ways(n - 1, k) + ways(n - 1, k - 1) * (M - 1) % MOD) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> N >> M >> K;

    // Checking memoization inefficiency right after input
    check_memoization_invariant(N, K);

    cout << ways(N, K) << "\n";
}