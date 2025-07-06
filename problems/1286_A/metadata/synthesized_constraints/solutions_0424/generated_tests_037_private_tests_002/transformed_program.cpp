#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

// Checker functions
void check_nested_loop_invariant(const vector<int>& A) {
    int zero_count = count(A.begin(), A.end(), 0);
    if (zero_count > A.size() / 2) { // Example threshold: more than half are zeros
        cerr << "Warning: Performance bottleneck condition triggered due to excessive zeros in the input!" << endl;
        abort();
    }
}

void check_dp_table_size_invariant(int N, int zero_count) {
    if (N > 80 && zero_count > N / 2) { // Example thresholds
        cerr << "Warning: Performance bottleneck due to large DP table operations!" << endl;
        abort();
    }
}

void check_parity_adjustment_invariant(const vector<int>& A) {
    int zero_count = count(A.begin(), A.end(), 0);
    if (zero_count > A.size() / 3) { // Example threshold: significant fraction are zeros
        cerr << "Warning: Performance bottleneck due to frequent parity adjustments!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < (int)(N); i++) cin >> A[i];

    // Insert checks after reading input
    int zero_count = count(A.begin(), A.end(), 0);
    check_nested_loop_invariant(A);
    check_dp_table_size_invariant(N, zero_count);
    check_parity_adjustment_invariant(A);

    vector<vector<vector<vector<int>>>> dp(
        N + 1, vector<vector<vector<int>>>(
                   N + 1, vector<vector<int>>(N + 1, vector<int>(2, (1e9)))));
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    int o = (N + 1) / 2;
    int e = N / 2;
    for (int i = 0; i < (int)(N); i++) {
        for (int j = 0; j < (int)(N); j++) {
            for (int k = 0; k < (int)(N); k++) {
                if (A[i] == 0) {
                    dp[i + 1][j + 1][k][0] = min(dp[i][j][k][0], dp[i][j][k][1] + 1);
                    dp[i + 1][j][k + 1][1] = min(dp[i][j][k][0] + 1, dp[i][j][k][1]);
                } else if (A[i] % 2 == 0) {
                    dp[i + 1][j][k][1] = (1e9);
                    dp[i + 1][j][k][0] = min(dp[i][j][k][0], dp[i][j][k][1] + 1);
                } else {
                    dp[i + 1][j][k][0] = (1e9);
                    dp[i + 1][j][k][1] = min(dp[i][j][k][1], dp[i][j][k][0] + 1);
                }
            }
        }
        if (A[i] != 0 && A[i] % 2 == 0) e--;
        if (A[i] != 0 && A[i] % 2 == 1) o--;
    }
    cout << min(dp[N][e][o][0], dp[N][e][o][1]) << endl;
}