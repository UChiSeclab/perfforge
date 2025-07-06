#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;

long long mul(long long a, long long b) {
    a %= mod, b %= mod;
    return a * b % mod;
}

long long add(long long a, long long b) {
    a %= mod, b %= mod;
    a += b, a %= mod;
    return a;
}

// Checker functions
void check_loop_iterations(long long b) {
    if (b > 1000000) {  // Arbitrary but large threshold for b
        cerr << "Warning: Performance bottleneck condition triggered - high loop iterations due to large b!" << endl;
        abort();
    }
}

void check_arithmetic_operations(long long a, long long b) {
    if (b * a > 10000000) {  // Threshold based on constraints and operation count
        cerr << "Warning: Performance bottleneck condition triggered - excessive arithmetic operations!" << endl;
        abort();
    }
}

void check_complexity(long long a, long long b) {
    if (b * b > 10000000) {  // Threshold indicating potential quadratic-like complexity
        cerr << "Warning: Performance bottleneck condition triggered - potential quadratic complexity due to b!" << endl;
        abort();
    }
}

int main(int argc, char const *argv[]) {
    long long a, b;
    cin >> a >> b;

    // Checkers
    check_loop_iterations(b);  // Detects high loop iterations
    check_arithmetic_operations(a, b);  // Detects excessive arithmetic operations
    check_complexity(a, b);  // Detects complexity issues

    long long res = 0;
    for (int(q) = (1); (q) < (int)(b); ++(q)) {
        res = add(res, mul(mul(q, b), a * (a + 1) / 2));
        res = add(res, a * q);
    }
    cout << res << endl;
    return 0;
}