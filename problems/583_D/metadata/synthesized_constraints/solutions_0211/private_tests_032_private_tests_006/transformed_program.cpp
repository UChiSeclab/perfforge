#include <bits/stdc++.h>
using namespace std;
const int N = 220;
long long temp[N], A[N * N], calc[2][305], dp[N * N], freq[305];

// Checker function for large T compared to n
void check_large_T_invariant(long long n, long long T) {
    if (T > 2 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - T is significantly larger than n!" << endl;
        abort();
    }
}

// Checker function for excessive iterations in nested loops
void check_high_iteration_invariant(long long cntr, long long n) {
    if (cntr > n * n) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterated operations in nested loops!" << endl;
        abort();
    }
}

int main() {
    long long sz, cntr = 1, n, T, ans = 0;
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> temp[i];
        freq[temp[i]]++;
    }

    // Check for large T relative to n
    check_large_T_invariant(n, T);

    if (T <= 2 * n) {
        for (int i = 1; i <= T; i++)
            for (int j = 1; j <= n; j++) A[cntr++] = temp[j];
        for (int i = cntr - 1; i >= 1; i--) {
            dp[i] = calc[0][A[i]] + 1;
            ans = max(ans, dp[i]);
            for (int j = A[i]; j >= 1; j--) calc[0][j] = max(calc[0][j], dp[i]);
        }
        cout << ans << endl;
    } else {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) A[cntr++] = temp[j];

        // Check for high iteration in nested loops
        check_high_iteration_invariant(cntr, n);

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < cntr; i++) {
            dp[i] = calc[0][A[i]] + 1;
            for (int j = A[i]; j <= 300; j++) calc[0][j] = max(calc[0][j], dp[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = cntr - 1; i >= 1; i--) {
            dp[i] = calc[1][A[i]] + 1;
            for (int j = A[i]; j >= 1; j--) calc[1][j] = max(calc[1][j], dp[i]);
        }
        for (int i = 1; i <= 300; i++)
            for (int j = i; j <= 300; j++)
                ans = max(ans, calc[0][i] + (freq[i] * (T - (2 * n))) + calc[1][j]);
        cout << ans << endl;
    }
}