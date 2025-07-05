#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_position_range(int maxPosition) {
    if (maxPosition > 100000) {  // Arbitrary threshold based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - large position range!" << endl;
        abort();
    }
}

void check_extensive_dp_calculations(int maxPosition, int n) {
    if (maxPosition > 100000 && n > 10000) {  // Thresholds based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - extensive dynamic programming calculations!" << endl;
        abort();
    }
}

void check_frequent_nonzero_checks(int maxPosition) {
    if (maxPosition > 50000) {  // Arbitrary threshold to indicate frequent non-zero checks
        cerr << "Warning: Performance bottleneck condition triggered - frequent non-zero checks!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = INT_MIN;
    cin >> n;
    int a[n];
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> a[i] >> x;
        m[a[i]] = x;
    }
    sort(a, a + n);

    // Integrate checkers with the maximum position of beacons
    int maxPosition = a[n - 1];
    check_large_position_range(maxPosition);
    check_extensive_dp_calculations(maxPosition, n);
    check_frequent_nonzero_checks(maxPosition);

    int dp[maxPosition + 1];
    for (int i = 0; i < maxPosition + 1; i++) {
        if (m[i] != 0) {
            if (i - m[i] - 1 >= 0)
                dp[i] = dp[i - m[i] - 1] + 1;
            else
                dp[i] = 1;
        } else
            dp[i] = i - 1 >= 0 ? dp[i - 1] : 0;
        ans = max(ans, dp[i]);
    }
    cout << n - ans << "\n";
}