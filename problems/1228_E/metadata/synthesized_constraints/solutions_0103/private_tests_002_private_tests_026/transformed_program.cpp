#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;

// Checker for large `k` values
void check_large_k_invariant(long long k) {
    if (k > (long long)1e6) { // Arbitrary chosen threshold; `k` can be large but this is indicative for potential performance issues
        cerr << "Warning: Performance bottleneck condition triggered due to large k!" << endl;
        abort();
    }
}

// Checker for nested loop complexity with large `n`
void check_large_n_invariant(int n) {
    if (n > 200) { // Based on n's upper limit in the problem
        cerr << "Warning: Performance bottleneck condition triggered due to large n in nested loops!" << endl;
        abort();
    }
}

long long qpow(long long a, long long b) {
    long long ans = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}

long long gcd(long long a, long long b) { return b > 0 ? gcd(b, a % b) : a; }

int n, m, T;
int a[maxn];
long long dp[300][300];
int fac[maxn], inv[maxn];
int p[maxn], P;

long long C(int x, int y) {
    if (x == y || y == 0) return 1;
    return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}

long long f[305], g[305];

void init() {
    fac[0] = p[0] = 1;
    for (int i = 1; i < maxn; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
    g[0] = inv[0];
    for (int i = 1; i <= 300; i++)
        p[i] = 1ll * p[i - 1] * P % mod, g[i] = qpow(p[i], mod - 2);
    for (int i = 1; i <= 300; i++) {
        for (int j = 0; j <= i; j++) {
            f[i] = (1ll * f[i] + 1ll * C(i, j) * qpow(p[j], mod - 2) % mod) % mod;
        }
    }
}

int main() {
    cin >> n >> P;
    
    // Insert checker for large k value
    check_large_k_invariant(P);
    
    // Insert checker for large n value in nested loops
    check_large_n_invariant(n);
    
    if (P == 1) {
        cout << 1 << endl;
        return 0;
    }
    P -= 1;
    init();
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) dp[1][i] = 1ll * C(n, i) * g[i] % mod;
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= n; x++) {
            dp[i][x] = 1ll * dp[i][x] * p[n] % mod;
            for (int k = 0; k <= n - x; k++) {
                dp[i + 1][x + k] =
                    (dp[i + 1][x + k] +
                     dp[i][x] * g[k] % mod * C(n - x, k) % mod * f[x] % mod) %
                    mod;
                if (k == 0) {
                    dp[i + 1][x + k] =
                        ((dp[i + 1][x + k] - dp[i][x] % mod) % mod + mod) % mod;
                }
            }
        }
    }
    cout << dp[n][n] % mod << endl;
    return 0;
}