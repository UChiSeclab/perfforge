#include <bits/stdc++.h>
using namespace std;
const int inf = 2e7;
const int N = 72;

int n, m, k, a[N][N], rowDP[N][N], dp[N][N][N], allDP[N][N], ans;

// Function to check column invariant
void check_column_invariant(int m) {
    if (m > 60) { // Threshold chosen to indicate a large size close to the upper limit
        cerr << "Warning: Performance bottleneck triggered by large number of columns (m)" << endl;
        abort();
    }
}

// Function to check divisibility invariant
void check_divisibility_invariant(int k) {
    if (k > 50) { // Threshold chosen to indicate significant complexity
        cerr << "Warning: Performance bottleneck triggered by large value of k" << endl;
        abort();
    }
}

// Function to check choice invariant
void check_choice_invariant(int m) {
    if (m / 2 > 30) { // Threshold related to choosing many elements
        cerr << "Warning: Performance bottleneck triggered by large choice constraint (m/2)" << endl;
        abort();
    }
}

void countRowDP(int row) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int t = 0; t < N; t++) dp[i][j][t] = -inf;
    for (int i = 0; i < N; i++) dp[i][0][0] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= min(i, m / 2); j++)
            for (int r = 0; r < k; r++) {
                dp[i][j][(r + a[row][i]) % k] =
                    max(dp[i][j][(r + a[row][i]) % k], dp[i - 1][j - 1][r] + a[row][i]);
                dp[i][j][r] = max(dp[i][j][r], dp[i - 1][j][r]);
            }
    for (int r = 0; r < k; r++) {
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= min(i, m / 2); j++)
                rowDP[row][r] = max(rowDP[row][r], dp[i][j][r]);
    }
}

int main() {
    cin >> n >> m >> k;

    // Insert performance checkers after reading input
    check_column_invariant(m);        // Check for column-related performance issues
    check_divisibility_invariant(k);  // Check for divisibility-related performance issues
    check_choice_invariant(m);        // Check for choice constraint-related performance issues

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) rowDP[i][j] = -inf;

    for (int i = 1; i <= n; i++) countRowDP(i);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) allDP[i][j] = -inf;

    allDP[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int r = 0; r < k; r++)
            for (int t = 0; t < k; t++) {
                allDP[i][(r + t) % k] =
                    max(allDP[i][(r + t) % k], allDP[i - 1][r] + rowDP[i][t]);
                allDP[i][r] = max(allDP[i][r], allDP[i - 1][r]);
            }
    cout << max(0, allDP[n][0]);
}