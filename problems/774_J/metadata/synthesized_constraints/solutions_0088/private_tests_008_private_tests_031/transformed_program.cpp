#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_state_space(int n, int questionMarkCount) {
    if (n > 80 && questionMarkCount > 30) {
        cerr << "Warning: High state space exploration triggered!" << endl;
        abort();
    }
}

void check_expensive_nested_loops(int n) {
    if (n > 90) {
        cerr << "Warning: Expensive nested loops triggered!" << endl;
        abort();
    }
}

void check_large_dp_table(int n) {
    if (n > 90) {
        cerr << "Warning: Large DP table memory usage triggered!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    
    // Count '?' characters in input
    int questionMarkCount = count(s.begin(), s.end(), '?');

    // Insert checks after reading inputs
    check_high_state_space(n, questionMarkCount); // Checks for high state space exploration
    check_expensive_nested_loops(n); // Checks for expensive nested loop execution
    check_large_dp_table(n); // Checks for large DP table memory usage

    s.push_back('Y');
    n++;
    bool dp[105][105][105] = {0};
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int gap = 0; gap <= n; gap++)
            for (int mx = 0; mx <= n; mx++) {
                if (!dp[i][gap][mx]) continue;
                if (s[i] == 'Y') {
                    dp[i + 1][0][max(mx, gap)] = 1;
                }
                if (s[i] == 'N') {
                    dp[i + 1][gap + 1][mx] = 1;
                }
                if (s[i] == '?') {
                    dp[i + 1][0][max(mx, gap)] = 1;
                    dp[i + 1][gap + 1][mx] = 1;
                }
            }
    bool ans = dp[n][0][k];
    cout << (ans ? "YES" : "NO") << "\n";
    return 0;
}