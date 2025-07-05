#include <bits/stdc++.h>
using namespace std;

// Function to check loop iteration count
void check_loop_iteration_invariant(long long m, long long b) {
    if (m * b > 1000000) { // Threshold chosen to capture excessive loop counts
        cerr << "Warning: Performance bottleneck condition triggered - loop iteration count too high!" << endl;
        abort();
    }
}

// Function to check high m value
void check_m_value_invariant(long long m, long long b) {
    if (m > 950 && b > 8000) { // Thresholds chosen based on high values towards constraints
        cerr << "Warning: Performance bottleneck condition triggered - high m value causes excessive iterations!" << endl;
        abort();
    }
}

// Function to check arithmetic overhead
void check_arithmetic_overhead_invariant(long long m, long long b) {
    if (m * b > 500000) { // Threshold chosen to limit arithmetic overhead
        cerr << "Warning: Performance bottleneck condition triggered - high arithmetic overhead in loop!" << endl;
        abort();
    }
}

int main() {
    long long m, b;
    cin >> m >> b;

    // Check invariants before entering the loop
    check_loop_iteration_invariant(m, b);
    check_m_value_invariant(m, b);
    check_arithmetic_overhead_invariant(m, b);

    long long c = b * m;
    long long ans = 0;
    for (long long i = 0; i <= c; i++) {
        long long y = b - ceil(i * 1.0 / m);
        long long cur = i * (i + 1) / 2 * (y + 1) + y * (y + 1) / 2 * (i + 1);
        ans = max(ans, cur);
    }
    cout << ans << endl;
}