#include <bits/stdc++.h>
using namespace std;
const int N = 205;
long long dp[N][N][N];
int n, k;
string s, t;

// Invariant check for high replacement allowance
void check_high_replacement_invariant(int n, int k) {
    if (k > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - High replacement allowance can lead to combinatorial explosion!" << endl;
        abort();
    }
}

// Invariant check for high branching factor
void check_branching_factor_invariant(int k) {
    if (k > 100) {  // Arbitrary threshold for high branching factor combined with replacements
        cerr << "Warning: Performance bottleneck condition triggered - High branching factor with large replacements!" << endl;
        abort();
    }
}

// Invariant check for large DP state space
void check_dp_state_space_invariant(int n, int k) {
    if (n * k > 15000) {  // Arbitrary threshold indicating large DP state space
        cerr << "Warning: Performance bottleneck condition triggered - Large DP state space!" << endl;
        abort();
    }
}

long long solve(int i, int j, int m) {
    if (i == n) return 0;
    long long &r = dp[i][j][m];
    if (r != -1) return r;
    long long res = (s[i] == t[1]) * j + solve(i + 1, j + (s[i] == t[0]), m);
    if (m) {
        for (int x = 0; x < 26; x++) {
            res = max(res, (x + 'a' == t[1]) * j + solve(i + 1, j + (x + 'a' == t[0]), m - 1));
        }
    }
    return r = res;
}

int main() {
    cin >> n >> k >> s >> t;
    memset(dp, -1, sizeof(dp));
    
    // Insert performance invariant checks
    check_high_replacement_invariant(n, k);
    check_branching_factor_invariant(k);
    check_dp_state_space_invariant(n, k);

    cout << solve(0, 0, k) << '\n';
    return 0;
}