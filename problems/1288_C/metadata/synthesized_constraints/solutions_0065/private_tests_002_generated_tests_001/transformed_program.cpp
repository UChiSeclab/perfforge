#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 11;
const int MOD = 1e9 + 7;
int n, m;
int dp[M][N][N];

// Check for high recursion depth or branching factor
void check_recursion_invariant(int maxDepth, int currentDepth, int branchingFactor, int thresholdDepth, int thresholdBranching) {
    if (currentDepth > thresholdDepth || branchingFactor > thresholdBranching) {
        cerr << "Warning: Recursion invariant triggered - high recursion depth or branching factor!" << endl;
        abort();
    }
}

// Check for a wide state space due to large input values
void check_state_space_invariant(int n, int m, int threshold) {
    if (n > threshold && m == 10) {
        cerr << "Warning: State space invariant triggered - large n with maximum m!" << endl;
        abort();
    }
}

// Check for large value range causing extensive recursion
void check_value_range_invariant(int n, int threshold) {
    if (n > threshold) {
        cerr << "Warning: Value range invariant triggered - large n causing extensive recursion!" << endl;
        abort();
    }
}

int solve(int idx, int a, int b) {
    // Check for recursion depth and range at each recursive call
    check_recursion_invariant(m, idx, b - a, 7, 10);

    if (idx >= m) return 1;
    int& r = dp[idx][a][b];
    if (r != -1) return r;
    r = solve(idx + 1, a, b);
    if (a < b) {
        r = (r + solve(idx, a + 1, b)) % MOD;
        r = (r + solve(idx, a, b - 1)) % MOD;
    }
    if (a + 1 < b) r = ((r - solve(idx, a + 1, b - 1)) % MOD + MOD) % MOD;
    return r;
}

int main() {
    cin >> n >> m;
    
    // Insert checks after input is read
    check_state_space_invariant(n, m, 900);
    check_value_range_invariant(n, 900);

    memset(dp, -1, sizeof dp);
    cout << solve(0, 1, n) << '\n';
    return 0;
}