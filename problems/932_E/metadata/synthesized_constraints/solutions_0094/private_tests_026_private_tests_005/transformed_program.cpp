#include <bits/stdc++.h>
using namespace std;

const int K = 5e3 + 5, MOD = 1e9 + 7;
int n, k, s2[K][K], fac1[K], fac2[K], inv[K], ans;

inline void inc(int &a, int b) { (a += b) >= MOD ? a -= MOD : a; }
inline int qsm(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1ll * ans * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }
    return ans;
}
inline int C(int j) {
    return j < 0 || j > n ? 0 : 1ll * fac1[j] * inv[j] % MOD;
}

// Checker for Stirling numbers computation
void check_stirling_invariant(int k) {
    if (k >= 4500) {
        cerr << "Warning: Potential slowdown due to large k in Stirling numbers computation!" << endl;
        abort();
    }
}

// Checker for modular exponentiation
void check_modular_exponentiation_invariant(int n, int k) {
    if (n > (1 << 20)) {
        cerr << "Warning: Potential slowdown due to excessive calls to modular exponentiation!" << endl;
        abort();
    }
}

// Checker for factorial computations
void check_factorial_invariant(int n, int k) {
    if (n > 1e8 && k > 4500) {
        cerr << "Warning: Potential slowdown due to large n and k affecting factorial computations!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> k;

    // Implement checkers
    check_stirling_invariant(k);
    check_modular_exponentiation_invariant(n, k);
    check_factorial_invariant(n, k);

    fac1[0] = 1;
    for (register int i = 1; i <= k; ++i)
        fac1[i] = 1ll * fac1[i - 1] * (n - i + 1) % MOD;
    fac2[0] = 1;
    for (register int i = 1; i <= k; ++i) fac2[i] = 1ll * fac2[i - 1] * i % MOD;
    inv[k] = qsm(fac2[k], MOD - 2);
    for (register int i = k - 1; i >= 0; --i)
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    if (n <= k) {
        for (register int i = 0; i <= n; ++i)
            inc(ans, 1ll * C(i) * qsm(i, k) % MOD);
        return printf("%d\n", ans), 0;
    }
    s2[0][0] = 1;
    for (register int i = 1; i <= k; ++i)
        for (register int j = 1; j <= i; ++j)
            s2[i][j] = s2[i - 1][j - 1], inc(s2[i][j], 1ll * s2[i - 1][j] * j % MOD);
    for (register int i = 0; i <= k; ++i)
        inc(ans, 1ll * fac2[i] * C(i) % MOD * s2[k][i] % MOD * qsm(2, n - i) % MOD);
    printf("%d\n", ans);
    return 0;
}