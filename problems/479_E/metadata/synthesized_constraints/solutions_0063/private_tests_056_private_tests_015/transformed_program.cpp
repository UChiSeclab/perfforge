#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int dp[2][5005];

void check_starting_position_near_boundary(int a, int n, int k) {
    if ((a == 1 || a == n) && k > 100) { // Assume a large k causes performance issues
        cerr << "Warning: Performance bottleneck triggered due to starting position near boundary!" << endl;
        abort();
    }
}

void check_large_trips_max_range(int k, int a, int b, int n) {
    if (k > 1000 && abs(a - b) > n / 2) { // Assume large k with maximum range
        cerr << "Warning: Performance bottleneck triggered due to large number of trips and maximum range!" << endl;
        abort();
    }
}

void check_symmetrical_position(int a, int b, int n) {
    if (abs(a - b) == abs(n - a)) { // Symmetrical condition
        cerr << "Warning: Performance bottleneck triggered due to symmetrical position relative to forbidden floor!" << endl;
        abort();
    }
}

int gao(int a, int n, int k) {
    for (int i = 1; i < n; i++) dp[0][i] = 0;
    dp[0][a] = 1;
    for (int i = 1; i <= k; i++) {
        int c = i & 1;
        for (int i = 1; i <= n; i++) dp[c][i] = 0;
        for (int i = 1; i <= n; i++) {
            dp[c][1] = (dp[c][1] + dp[c ^ 1][i]) % MOD;
            dp[c][i] = (dp[c][i] + MOD - dp[c ^ 1][i]) % MOD;
            dp[c][i + 1] = (dp[c][i + 1] + dp[c ^ 1][i]) % MOD;
            int p = min(n + 1, i + i);
            dp[c][p] = (dp[c][p] + MOD - dp[c ^ 1][i]) % MOD;
        }
        for (int i = 2; i <= n; i++) {
            dp[c][i] = (dp[c][i] + dp[c][i - 1]) % MOD;
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) ret = (ret + dp[k & 1][i]) % MOD;
    return ret;
}

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    // Insert checks after reading input to avoid overhead in loops
    check_starting_position_near_boundary(a, n, k);
    check_large_trips_max_range(k, a, b, n);
    check_symmetrical_position(a, b, n);

    if (a < b)
        cout << gao(b - a, b - 1, k) << endl;
    else
        cout << gao(a - b, n - b, k) << endl;

    return 0;
}