#include <bits/stdc++.h>
using namespace std;

long long N, n, k, ans;
map<long long, long long> dp;

void check_large_n(long long n) {
    if (n > 1e16) {
        cerr << "Warning: Performance bottleneck condition triggered - large n causing many loop iterations!" << endl;
        abort();
    }
}

void check_map_size(const map<long long, long long>& dp) {
    if (dp.size() > 1e6) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive map size!" << endl;
        abort();
    }
}

void check_odd_even_switch(long long n) {
    if (n > 1e15) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent odd/even switching!" << endl;
        abort();
    }
}

void check_high_k(long long n, long long k) {
    if (n > 1e16 && k > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - high k with large n!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> k;

    check_large_n(N);  // Check before processing
    check_high_k(N, k);  // Check before processing

    n = N;
    while (n) {
        check_map_size(dp);  // Check map size within loop, but not inside tight code

        if (n % 2) {
            dp[n] = dp[n * 2] + 1;
            dp[n - 1] = dp[n] + dp[n * 2 - 2] + 1;
            dp[n - 2] = dp[n * 2 - 2] + 1;
            dp[n - 3] = dp[n - 2] + dp[n * 2 - 2] + 1;
        } else {
            dp[n] = dp[n * 2] + dp[n * 2 - 1] + 1;
            dp[n - 1] = dp[n * 2 - 2] + 1;
            dp[n - 2] = dp[n - 1] + dp[n * 2 - 2] + 1;
            dp[n - 3] = dp[n * 2 - 2] + 1;
        }
        
        if (dp[n] >= k && n >= ans) ans = n;
        if (dp[n - 1] >= k && n - 1 >= ans) ans = n - 1;
        if (dp[n - 2] >= k && n - 2 >= ans) ans = n - 2;
        if (dp[n - 3] >= k && n - 3 >= ans) ans = n - 3;
        
        check_odd_even_switch(n);  // Check odd/even switch condition
        
        n /= 2;
    }
    cout << ans << '\n';
    return 0;
}