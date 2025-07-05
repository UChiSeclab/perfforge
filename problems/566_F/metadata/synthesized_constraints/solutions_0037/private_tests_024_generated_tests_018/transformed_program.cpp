#include <bits/stdc++.h>
using namespace std;

const int N = 1e6, M = 320, K = 1001;
const int oo = 1e9 + 7;
int dp[N + 1], n, a[N + 1], ans;

// Invariant checker for small divisors
void check_small_divisor_invariant(int value) {
    if (value == 1) {
        cerr << "Warning: Performance bottleneck condition triggered due to small divisor (1)!" << endl;
        abort();
    }
}

// Invariant checker for large loop bounds
void check_large_loop_bound_invariant(int maxValue, int divisor) {
    if (divisor <= 1 && maxValue / divisor > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large loop bounds!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        // Check invariant for small divisors upon reading each element
        check_small_divisor_invariant(a[i]);
    }
    
    for (int i = n; i >= 1; --i) {
        // Check invariant for large loop bounds
        check_large_loop_bound_invariant(N, a[i]);
        
        for (int j = 1; j <= N / a[i]; ++j) {
            dp[a[i]] = max(dp[a[i]], dp[a[i] * j] + 1);
        }
        ans = max(ans, dp[a[i]]);
    }
    cout << ans;
}