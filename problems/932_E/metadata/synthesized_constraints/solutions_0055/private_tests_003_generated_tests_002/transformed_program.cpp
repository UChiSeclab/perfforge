#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
const long long M = 5e3 + 10;
long long n, ans, k, s[M][M], dfac[M];

long long poww(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return r;
}

long long fac[M], inv[M];

void init() {
    fac[0] = 1;
    for (long long i = 1; i < M; i++) fac[i] = fac[i - 1] * i % Mod;
    for (long long i = 0; i < M; i++) inv[i] = poww(fac[i], Mod - 2);
}

long long p = Mod;

long long C(long long m, long long n) {
    return fac[m] * inv[m - n] % p * inv[n] % p;
}

// Performance checkers
void check_large_k_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large k with nested computations!" << endl;
        abort();
    }
}

void check_power_function_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient power computations!" << endl;
        abort();
    }
}

void check_factorial_stirling_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - factorial and Stirling table growth!" << endl;
        abort();
    }
}

signed main() {
    cin >> n >> k;

    // Check for large k causing nested computation bottlenecks
    check_large_k_invariant(k > 4000);

    s[0][0] = 1;
    if (k >= n) {
        init();
        for (long long i = 1; i <= n; i++) {
            // Check for inefficient power computations in a loop
            check_power_function_invariant(i > 1000);

            ans = (ans + C(n, i) * poww(i, k)) % Mod;
        }
        cout << ans;
        return 0;
    }

    for (long long i = 1; i <= k; i++) {
        for (long long j = 1; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j] % Mod) % Mod;
    }

    // Check for factorial and Stirling table growth
    check_factorial_stirling_invariant(k > 4000);

    dfac[0] = 1;
    for (long long i = 1; i <= k; i++) dfac[i] = dfac[i - 1] * (n - i + 1) % Mod;

    for (long long i = 0; i <= k; i++) {
        // Check for inefficient power computations in a loop
        check_power_function_invariant(n - i > 1000);

        ans = (ans + s[k][i] * dfac[i] % Mod * poww(2, n - i) % Mod) % Mod;
    }

    cout << ans;
    return 0;
}