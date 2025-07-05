#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_small_n_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to small n and large z!" << endl;
        abort();
    }
}

void check_power_computation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered by expensive power computations!" << endl;
        abort();
    }
}

void check_large_z_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to large z!" << endl;
        abort();
    }
}

void solve() {
    long long i, j, k, x, y, z, n, mi = 1e16, sum = 0;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    if (n == 1 || n == 2) {
        cout << a[0] - 1;
        return;
    }
    z = (long long)pow(1e18, 1.0 / (n - 1));

    // Check for potential performance issues due to small n
    check_small_n_invariant(n == 3);

    if (n == 3) {
        z = (long long)pow(10, 7);
    }

    // Check for large z that could lead to performance issues
    check_large_z_invariant(z > 1e7);

    for (i = 1; i <= z; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            y = (long long)pow(i, j);

            // Check for potential expensive power computation
            check_power_computation_invariant(i > 1e7);

            sum += abs(a[j] - y);
        }
        mi = min(mi, sum);
    }
    cout << mi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t = 1;
    while (t-- > 0) {
        solve();
    }
}