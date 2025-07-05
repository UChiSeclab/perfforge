#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001];
int n, m, k;

// Checker functions
void check_recursion_invariant(int i, int f, int n, int k) {
    if (i > n - k && f > k / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth and branching factor!" << endl;
        abort();
    }
}

void check_memoization_invariant(int computedValues) {
    if (computedValues > 0.75 * 2001 * 2001) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive state combinations in memoization!" << endl;
        abort();
    }
}

void check_input_combination_invariant(int n, int k) {
    if (n > 1500 && k > n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered - large n and relatively high k!" << endl;
        abort();
    }
}

void check_combination_complexity_invariant(int m, int k) {
    if (m > 1500 && k > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of colors and transitions!" << endl;
        abort();
    }
}

long long find(int i, int f) {
    check_recursion_invariant(i, f, n, k); // Check recursion depth and branching

    if (i == 1) {
        if (f == 0)
            return m;
        else
            return 0;
    }
    if (dp[i][f] != -1) return dp[i][f];
    return dp[i][f] = (find(i - 1, f) % 998244353 +
                       (find(i - 1, f - 1) % 998244353 * (m - 1) % 998244353) %
                           998244353) %
                      998244353;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    check_input_combination_invariant(n, k); // Check input combinations
    check_combination_complexity_invariant(m, k); // Check combination complexity

    memset(dp, -1, sizeof(dp));

    // Check memoization table usage before running the main computation
    int computedValues = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (dp[i][j] != -1) ++computedValues;
        }
    }
    check_memoization_invariant(computedValues);

    cout << find(n, k) << "\n";
    return 0;
}