#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long a[2000];

void check_large_n(long long n) {
    if (n > 900) {
        cerr << "Warning: Performance bottleneck condition triggered due to large value of n!" << endl;
        abort();
    }
}

void check_nested_loops(long long n, long long m) {
    if (n > 900 && m > 5) {
        cerr << "Warning: Performance bottleneck due to deeply nested loops!" << endl;
        abort();
    }
}

void check_repeated_calculations(long long n, long long calls) {
    if (n > 900 && calls > 1000000) {
        cerr << "Warning: Performance bottleneck due to excessive repeated calculations!" << endl;
        abort();
    }
}

long long power(long long n, long long r) {
    long long ans = 1;
    long long call_count = 0; // Counter for repeated calculations
    while (r > 0) {
        if (r & 1) ans = (ans * n) % mod;
        n = (n * n) % mod;
        r >>= 1;
        call_count++;
    }
    check_repeated_calculations(n, call_count); // Check for excessive calls
    return ans;
}

long long fact(long long n) {
    if (a[n] != 0) return a[n];
    long long ans = 1;
    for (long long i = 1; i <= n; i++) ans = (ans * i) % mod;
    return a[n] = ans;
}

long long comb(long long n, long long m) {
    return ((((fact(n) % mod) * (power(fact(m), mod - 2))) % mod) *
            (power(fact(n - m), mod - 2) % mod)) %
           mod;
}

long long arrays(long long n, long long m) {
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        for (long long j = i; j <= n; j++) {
            long long x = (((comb(i + m - 2, m - 1) % mod) *
                            (comb(n - j + m - 1, m - 1) % mod)) %
                           mod);
            ans = (ans + x) % mod;
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;

    // Checkers for input and loop complexity
    check_large_n(n);
    check_nested_loops(n, m);

    cout << arrays(n, m) << endl;
    return 0;
}