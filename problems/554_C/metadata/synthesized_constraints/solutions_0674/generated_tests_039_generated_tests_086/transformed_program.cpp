#include <bits/stdc++.h>
using namespace std;

long long dp[2005][2005];

long long comb(long long n, long long k) {
    if ((k == 0) || k == n) return 1;
    if (dp[n][k] != 0) return dp[n][k];
    long long x = comb(n - 1, k - 1) % 1000000007 + comb(n - 1, k) % 1000000007;
    dp[n][k] = x % 1000000007;
    x %= 1000000007;
    return x;
}

// Checker functions
void check_large_ball_count(long long totalBalls, long long currentCombination) {
    if (totalBalls > 800 && currentCombination > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - large total ball count with low memoization benefit!" << endl;
        abort();
    }
}

void check_uneven_distribution(long long *a, long long n) {
    long long maxBalls = 0, minBalls = LONG_MAX;
    for (long long i = 0; i < n; ++i) {
        maxBalls = max(maxBalls, a[i]);
        minBalls = min(minBalls, a[i]);
    }
    if (maxBalls > 500 && (maxBalls > 2 * minBalls)) {
        cerr << "Warning: Performance bottleneck condition triggered - uneven distribution of balls!" << endl;
        abort();
    }
}

void check_high_recursion_depth(long long n, long long k) {
    if (n > 800 && k < 100) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth due to color sequence!" << endl;
        abort();
    }
}

void solve() {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];

    // Insert checker for uneven distribution after reading input
    check_uneven_distribution(a, n);

    long long ans = 1;
    long long cnt = a[0];
    for (long long i = 1; i < n; i++) {
        ans *= comb(cnt + 1 + a[i] - 2, a[i] - 1);
        
        // Insert checker for large ball count within loop
        check_large_ball_count(cnt + a[i], a[i] - 1);
        
        cnt += a[i];
        ans %= 1000000007;
    }

    // Check high recursion depth before output
    check_high_recursion_depth(cnt, n);
    
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}