#include <bits/stdc++.h>
using namespace std;

long long const mod = 1e9 + 7;

long long power(long long b, long long p) {
    long long r = 1;
    while (p) {
        if (p & 1) r = (r * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return r;
}

void check_iteration_count_invariant(long long a) {
    if (a > 1e6) { // Threshold chosen based on constraints and potential slowdown.
        cerr << "Warning: Iteration count invariant triggered - too many loop iterations!" << endl;
        abort();
    }
}

void check_arithmetic_operation_invariant(long long a, long long b) {
    if (a > 1e6 && b > 1) { // High `a` combined with non-minimal `b` could be problematic.
        cerr << "Warning: Arithmetic operation invariant triggered - potential arithmetic overload!" << endl;
        abort();
    }
}

void check_exponential_growth_factor_invariant(long long a, long long b) {
    if (a > 1e6 && b > 1e6) { // Both `a` and `b` being large can compound the issue.
        cerr << "Warning: Exponential growth factor invariant triggered - excessive arithmetic operations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long z = power(2, mod - 2);
    long long a, b;
    cin >> a >> b;

    // Insert checks before the main computation starts
    check_iteration_count_invariant(a);
    check_arithmetic_operation_invariant(a, b);
    check_exponential_growth_factor_invariant(a, b);

    long long ans = 0;
    for (long long k = 1; k <= a; k++) {
        long long x = k * b + 1;
        x %= mod;
        x = (x * b) % mod;
        x = (x * (b - 1)) % mod;
        x = (x + mod) % mod;
        x = (x * z) % mod;
        ans = (ans + x) % mod;
    }
    cout << ans << endl;
    return 0;
}