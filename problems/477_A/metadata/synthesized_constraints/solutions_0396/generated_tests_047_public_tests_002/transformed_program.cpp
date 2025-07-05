#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks

void check_large_b_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large b!" << endl;
        abort();
    }
}

void check_arithmetic_operations_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to costly arithmetic operations!" << endl;
        abort();
    }
}

void check_conditional_branching_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to conditional branching!" << endl;
        abort();
    }
}

int main() {
    long long aa, b;
    cin >> aa >> b;

    // Check for large 'b' causing excessive loop iterations
    check_large_b_invariant(b > 1000000);

    long long i;
    long long mod = 1000000007;
    long long sum = 0;

    // Check for costly arithmetic operations based on 'b'
    check_arithmetic_operations_invariant(b > 1000000);

    for (i = 1; i < b; i++) {
        long long first = ((i * b) % mod + i) % mod;
        long long k1 = (aa * first) % mod;
        long long p, d;
        long long m = (i * b) % mod;

        // Check for conditional branching overhead
        check_conditional_branching_invariant(b > 1000000 && aa % 2 != 0);

        if (aa % 2 == 0) {
            p = aa / 2;
            p = (p * (aa - 1)) % mod;
            d = (p * m) % mod;
        } else {
            p = (aa - 1) / 2;
            p = (p * (aa)) % mod;
            d = (p * m) % mod;
        }
        long long s = (k1 + d) % mod;
        sum = (sum + s) % mod;
    }
    cout << sum << "\n";
    return 0;
}