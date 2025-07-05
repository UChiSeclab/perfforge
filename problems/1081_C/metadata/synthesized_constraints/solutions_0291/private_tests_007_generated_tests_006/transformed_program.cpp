#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e3 + 5;
const long long M = (long long)998244353;
long long dp[N][N];
int n, k, m;

void check_high_k_invariant(int n, int k) {
    if (k > n / 2) {
        cerr << "Warning: High 'k' value may cause performance bottleneck!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n, int k) {
    if (k * n > 1000000) {  // Example threshold based on problem constraints
        cerr << "Warning: Nested loops with high indices may cause slowdowns!" << endl;
        abort();
    }
}

void check_computation_invariant(int n, int k, int m) {
    if (k > 0.8 * n && m > 100) {  // Hypothetical condition for detecting heavy operations
        cerr << "Warning: High computational overhead detected!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> m >> k;

    // Check performance invariants based on input conditions
    check_high_k_invariant(n, k);
    check_nested_loop_invariant(n, k);
    check_computation_invariant(n, k, m);

    long long res = 0ll;
    dp[1][0] = m;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = (dp[i - 1][j] % M + dp[i - 1][j - 1] % M * (m - 1) % M) % M;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}