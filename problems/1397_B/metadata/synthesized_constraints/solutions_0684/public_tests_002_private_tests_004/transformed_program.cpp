#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_base_iteration(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to large range of base c!" << endl;
        abort();
    }
}

void check_expensive_power_calculations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to expensive power calculations in loops!" << endl;
        abort();
    }
}

void check_large_search_space(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to large search space for c!" << endl;
        abort();
    }
}

void solve() {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i <= n - 1; i++) cin >> a[i];

    // Calculate u
    long long u = 1e14;
    u = (long long)pow(u, ((double)1.0) / (n - 1));

    // Insert check for large base iteration
    check_large_base_iteration(u > 1e7); // Example threshold for large base iteration

    long long ans = 1e18;
    sort(a, a + n);

    // Insert check for large search space
    check_large_search_space(n > 50000); // Example threshold for large search space

    for (long long c = 1; c <= u; c++) {
        long long cur_ans = 0;
        for (long long i = 0; i < n; i++) {
            cur_ans += abs(a[i] - (long long)pow(c, i));

            // Insert check for expensive power calculations
            check_expensive_power_calculations(i > 10 && c > 10);  // Example condition
        }
        ans = min(ans, cur_ans);
    }
    cout << ans;
    return;
}

int main() {
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}