#include <bits/stdc++.h>
using namespace std;

// Performance checker functions
void check_unknown_invariant(const std::string& s, int n) {
    int consecutiveUnknowns = 0;
    for (char c : s) {
        if (c == '?') {
            consecutiveUnknowns++;
            if (consecutiveUnknowns > n / 2) { // Threshold: more than half of the episodes are unknown
                cerr << "Warning: Performance bottleneck condition triggered - too many unknown episodes!" << endl;
                abort();
            }
        } else {
            consecutiveUnknowns = 0;
        }
    }
}

void check_input_size_invariant(int n) {
    if (n > 90) { // Threshold: n close to the maximum constraint
        cerr << "Warning: Performance bottleneck condition triggered - large input size!" << endl;
        abort();
    }
}

void check_dp_reset_invariant(const std::string& s) {
    int resetCount = 0;
    for (char c : s) {
        if (c == '?') {
            resetCount++;
            if (resetCount > 30) { // Arbitrary threshold for frequent DP resets
                cerr << "Warning: Performance bottleneck condition triggered - frequent resetting of DP states!" << endl;
                abort();
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Insert performance checks
    check_input_size_invariant(n);        // Check for large input size
    check_unknown_invariant(s, n);        // Check for too many unknown episodes
    check_dp_reset_invariant(s);          // Check for frequent DP resets

    int dp[n + 1][101];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 100; j++) dp[i][j] = -1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 100; j++) {
            if (i == 0) {
                if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
                continue;
            }
            if (s[i - 1] == 'Y') {
                if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
                continue;
            }
            if (s[i - 1] == 'N') {
                if (j == 0) dp[i][j] = 0;
                if (j == 1)
                    dp[i][j] = 1;
                else if (j > 1) {
                    if (j <= k) {
                        if (dp[i - 1][j - 1] == 1)
                            dp[i][j] = 1;
                        else if (dp[i - 1][j - 1] == 0)
                            dp[i][j] = 0;
                        else
                            dp[i][j] = 2;
                    } else {
                        if (dp[i - 1][j - 1] == 1)
                            dp[i][j] = 1;
                        else if (dp[i - 1][j - 1] == 0)
                            dp[i][j] = 0;
                        else {
                            for (int l = 1; l < 101; l++) {
                                if (dp[i - 1][l] == 2) dp[i - 1][l] = 0;
                            }
                            for (int l = 2; l < j; l++) {
                                if (dp[i][l] == 2) dp[i][l] = 0;
                            }
                            dp[i][j] = 0;
                        }
                    }
                }
            }
            if (s[i - 1] == '?') {
                if (j == 0) dp[i][j] = 2;
                if (dp[i - 1][j - 1] == 2 or dp[i - 1][j - 1] == 1)
                    dp[i][j] = 2;
                else
                    dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    int ans1 = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = k + 1; j <= 100; j++) {
            if (dp[i][j] == 1) ans1 = 1;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (dp[i][k] == 1 or dp[i][k] == 2) {
            ans = 1;
        }
    }
    if (ans == 1 and ans1 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}