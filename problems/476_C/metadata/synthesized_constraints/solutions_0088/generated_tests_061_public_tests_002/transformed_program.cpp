#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

long long power(long long a, long long x) {
    if (x == 0) return (1);
    long long p = power(a, x / 2);
    p = (p * p) % M;
    if (x % 2 == 0) return (p);
    return ((p * a) % M);
}

// Check for large values of b that could lead to performance bottlenecks
void check_large_b(long long b) {
    if (b > 1000000) { // Example threshold; adjust if necessary
        cerr << "Warning: Performance bottleneck condition triggered due to large b!" << endl;
        abort();
    }
}

// Check for heavy arithmetic operations expected due to large b
void check_arithmetic_operations(long long b) {
    if (b > 1000000) { // Example threshold; adjust if needed
        cerr << "Warning: Heavy arithmetic and modulo operations triggered!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;
    cin >> a >> b;

    // Insert performance checks
    check_large_b(b);
    check_arithmetic_operations(b);

    long long ans = 0;
    long long x = power(2, M - 2);
    for (long long i = 1; i <= b - 1; i++) {
        long long l = (b * i) % M;
        long long h = ((a * b) % M * i) % M;
        long long n = a;
        long long sum = (l + h) % M;
        sum = ((sum * n) % M * x) % M;
        ans = (ans + (n * i) % M + sum) % M;
    }
    cout << ans << "\n";
}