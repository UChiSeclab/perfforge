#include <bits/stdc++.h>
using namespace std;

// Function to check the invariant for large m * b product
void check_mb_product_invariant(long long m, long long b) {
    if (m * b > 1000000) { // Threshold based on problem constraints
        cerr << "Warning: Performance bottleneck due to large m * b product!" << endl;
        abort();
    }
}

// Function to check the invariant for high iteration count
void check_iteration_count_invariant(long long iteration_count) {
    if (iteration_count > 1000000) { // Threshold to indicate excessive iterations
        cerr << "Warning: Performance bottleneck due to high iteration count!" << endl;
        abort();
    }
}

// Function to check the invariant for extensive loop computation
void check_loop_computation_invariant(long long m, long long b) {
    if (m * b > 1000000) { // Threshold for overlapping conditions
        cerr << "Warning: Performance bottleneck due to extensive loop computation!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    long long m, b;
    long long ans = 0;
    cin >> m >> b;

    // Insert runtime checks before entering the loop
    check_mb_product_invariant(m, b);
    check_iteration_count_invariant(m * b);
    check_loop_computation_invariant(m, b);

    for (long long i = 0; i <= m * b; i++) {
        long long maxx = floor(-i * 1.0 / m) + b;
        ans = max(ans,
                  (maxx + 1) * i * (i + 1) / 2 + maxx * (maxx + 1) * (i + 1) / 2);
    }
    cout << ans << endl;
    return 0;
}