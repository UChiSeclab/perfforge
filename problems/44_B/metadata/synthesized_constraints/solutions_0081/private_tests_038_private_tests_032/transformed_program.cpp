#include <bits/stdc++.h>
using namespace std;

// Checker for high iteration count with maximum capacity
void check_max_capacity_invariant(long long n, long long a, long long b, long long c) {
    if (n >= 5000 && a == 5000 && b == 5000 && c == 5000) {
        cerr << "Warning: max_capacity_invariant triggered - high iteration count with maximum capacity" << endl;
        abort();
    }
}

// Checker for nested loop with large search space
void check_large_search_space_invariant(long long n, long long b, long long c) {
    if (b > 4000 && c > 2000 && n > 4500) {
        cerr << "Warning: large_search_space_invariant triggered - nested loop with large search space" << endl;
        abort();
    }
}

void solve() {
    long long n, a, b, c, ans = 0;
    cin >> n >> a >> b >> c;
    
    // Check for performance bottlenecks after reading inputs
    check_max_capacity_invariant(n, a, b, c);
    check_large_search_space_invariant(n, b, c);

    for (long long i = 0; i <= c && 2 * i <= n; i++) {
        for (long long j = 0; j <= min(b, n - 2 * i); j++) {
            long long need = n - (2 * i + j);
            if (need * 2 <= a) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t = 1;
    while (t--) {
        solve();
    }
    return 0;
}