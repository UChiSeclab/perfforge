#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
long long n, m;
long long dp[1010][1010][15];

void check_recursion_depth_invariant(long long n, long long m) {
    if (n > 900 && m > 8) {
        cerr << "Warning: High recursion depth and call volume due to large n and m!" << endl;
        abort();
    }
}

void check_combination_exploration_invariant(long long n, long long m) {
    if ((n > 900 || m > 8) && n * m > 7000) {
        cerr << "Warning: Extensive combination exploration due to high n or m!" << endl;
        abort();
    }
}

void check_dp_table_utilization_invariant(long long n, long long m) {
    if (n * m > 9000) {
        cerr << "Warning: High DP table utilization, potential memory footprint issue!" << endl;
        abort();
    }
}

long long fn(long long i, long long j, long long k) {
    if (i > j) return 0;
    if (k >= m) return 1;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    long long ans = 0;
    ans += fn(i + 1, j, k);
    ans %= mod;
    ans += fn(i, j - 1, k);
    ans %= mod;
    ans += fn(i, j, k + 1);
    ans %= mod;
    ans -= fn(i + 1, j - 1, k);
    return dp[i][j][k] = ans % mod;
}

void solve() {
    cin >> n >> m;

    // Insert checks after reading inputs
    check_recursion_depth_invariant(n, m);
    check_combination_exploration_invariant(n, m);
    check_dp_table_utilization_invariant(n, m);

    memset(dp, -1, sizeof(dp));
    long long value = fn(1, n, 0);
    if (value < 0)
        cout << value + mod;
    else
        cout << value;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}