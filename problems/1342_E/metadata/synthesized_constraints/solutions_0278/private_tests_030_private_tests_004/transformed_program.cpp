#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int G = 3;
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")

// Checkers for performance bottlenecks
void check_qpow_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: qpow_invariant triggered - excessive power calculations" << endl;
        abort();
    }
}

void check_recursive_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: recursive_invariant triggered - deep recursion or high operations count" << endl;
        abort();
    }
}

void check_ntt_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: ntt_invariant triggered - intense large-scale transformations" << endl;
        abort();
    }
}

inline long long read() {
    long long x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x * f;
}

int n, m;
long long t;
int fac[600040], inv[600040];
int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = (long long)ans * a % mod;
        a = (long long)a * a % mod;
        b >>= 1;
    }
    return ans;
}

const int invG = qpow(G, mod - 2);
int f[600040], g[600040], a[600040];
int tr[600040];

void NTT(int *f, int flag, int n) {
    for (int i = 0; i < n; ++i) {
        if (i < tr[i]) swap(f[i], f[tr[i]]);
    }
    for (int p = 2; p <= n; p <<= 1) {
        int len = (p >> 1);
        int wn = qpow(flag ? G : invG, (mod - 1) / p);
        for (int k = 0; k < n; k += p) {
            int buf = 1;
            for (int i = k; i < k + len; ++i) {
                int tmp = (long long)f[i + len] * buf % mod;
                f[i + len] = (f[i] - tmp + mod) % mod;
                f[i] = (f[i] + tmp) % mod;
                buf = (long long)buf * wn % mod;
            }
        }
    }
    if (!flag) {
        int invn = qpow(n, mod - 2);
        for (int i = 0; i < n; ++i) {
            f[i] = (long long)f[i] * invn % mod;
        }
    }
}

void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (long long)fac[i - 1] * i % mod;
    }
    inv[n] = qpow(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; --i) {
        inv[i] = (long long)inv[i + 1] * (i + 1) % mod;
    }
}

int C(int n, int m) {
    return (long long)fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void Solve(int l, int r) {
    if (l + 1 == r) {
        if (!l) return;
        f[l] = (qpow(l, m) - (long long)f[l] * fac[l] % mod + mod) % mod;
        return;
    }
    int mid = (l + r) >> 1;
    Solve(l, mid);
    int lim = r - l;
    for (int i = 0; i < lim; ++i) {
        tr[i] = ((tr[i >> 1] >> 1) | ((i & 1) ? lim >> 1 : 0));
    }
    static int w[600040];
    for (int i = 0; i < lim; ++i) {
        g[i] = inv[i];
    }
    for (int i = l; i < mid; ++i) {
        w[i - l] = (long long)f[i] * inv[i] % mod;
    }
    for (int i = mid; i < r; ++i) {
        w[i - l] = 0;
    }
    NTT(g, 1, lim), NTT(w, 1, lim);
    for (int i = 0; i < lim; ++i) {
        g[i] = (long long)g[i] * w[i] % mod;
    }
    NTT(g, 0, lim);
    for (int i = mid; i < r; ++i) f[i] = (f[i] + g[i - l]) % mod;
    Solve(mid, r);
}

int main() {
    m = read(), t = read();
    if (t >= m) {
        printf("0\n");
        return 0;
    }

    init(m);

    // Check for frequent power calculations
    check_qpow_invariant(m > 1000);  // Assuming a threshold for excessive power usage

    n = m - t;
    if (n == m) {
        printf("%d\n", fac[m]);
        return 0;
    }

    int lim = 1;
    while (lim < n + 1) lim <<= 1;

    // Check for recursive depth or high operations
    check_recursive_invariant(lim > 1000);  // Threshold on lim to detect deep recursion

    Solve(0, lim);

    // Check for large scale NTT transformations
    check_ntt_invariant(lim > 1000);  // Threshold on lim to detect intense NTT

    printf("%d\n", 2LL * f[n] % mod * C(m, n) % mod);
    return 0;
}