#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_nested_iteration_invariant(int questionMarksCount) {
    if (questionMarksCount > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive combinations from uncertain episodes!" << endl;
        abort();
    }
}

void check_dp_table_size_invariant(int n, int uncertainSegments) {
    if (uncertainSegments > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of uncertain segments in DP table!" << endl;
        abort();
    }
}

void check_memory_usage_invariant(int dpSizeEstimate) {
    if (dpSizeEstimate > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive memory usage due to DP states!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int dp[100 + 5][100 + 5][105];
    memset(dp, 0, sizeof(dp));
    string s;
    cin >> s;

    // Add invariant checks after reading input
    int questionMarksCount = count(s.begin(), s.end(), '?');
    check_nested_iteration_invariant(questionMarksCount);

    int uncertainSegments = 0; // To be calculated based on '?' clusters
    for (char c : s) {
        if (c == '?') {
            ++uncertainSegments;
        }
    }
    check_dp_table_size_invariant(n, uncertainSegments);
    
    int dpSizeEstimate = n * 100 * 100; // Rough estimate
    check_memory_usage_invariant(dpSizeEstimate);

    s += 'Y';
    n++;
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int mx = 0; mx <= 100; mx++) {
                if (dp[i][j][mx] == 0) continue;
                if (s[i] == 'N') {
                    dp[i + 1][j + 1][mx] = 1;
                }
                if (s[i] == 'Y') {
                    dp[i + 1][0][max(j, mx)] = 1;
                }
                if (s[i] == '?') {
                    dp[i + 1][0][max(mx, j)] = 1;
                    dp[i + 1][j + 1][mx] = 1;
                }
            }
        }
    }
    if (dp[n][0][k]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}