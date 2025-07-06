#include <bits/stdc++.h>
const long double PI = acos(-1);
using namespace std;

inline long long mod(long long n, long long m) {
    long long ret = n % m;
    if (ret < 0) ret += m;
    return ret;
}

long long exp(long long a, long long k) {
    if (k == 0) return 1LL;
    if (k == 1) return a;
    long long ax = exp(a, k / 2);
    ax = mod(ax * ax, 998244353);
    if (k % 2) ax = mod(ax * a, 998244353);
    return ax;
}

long long fat[212345], inv[212345];

long long finv(long long n) {
    return exp(n, 998244353 - 2);
}

long long C(long long n, long long k) {
    long long num = fat[n];
    long long den = mod(inv[k] * inv[n - k], 998244353);
    return mod(num * den, 998244353);
}

void check_modulo_operations_invariant(long long c) {
    if (c > 100000) { 
        cerr << "Warning: Performance bottleneck condition triggered - extensive modulo operations!" << endl;
        abort();
    }
}

void check_exponentiation_invariant(long long n, long long k) {
    if (n > 100000 && k < 100) {
        cerr << "Warning: Performance bottleneck condition triggered - expensive recursive exponentiation!" << endl;
        abort();
    }
}

void check_combination_invariant(long long n, long long c) {
    if (c > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive combinatorial calculations!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fat[0] = 1;
    inv[0] = 1;
    long long n, k;
    cin >> n >> k;

    if (k > n - 1) {
        cout << 0 << '\n';
        return 0;
    }

    for (long long i = 1; i <= n; i++) {
        fat[i] = mod(fat[i - 1] * i, 998244353);
        inv[i] = finv(fat[i]);
    }

    long long c = n - k;

    // Insert checkers before potentially costly operations
    check_modulo_operations_invariant(c);
    check_exponentiation_invariant(n, k);
    check_combination_invariant(n, c);

    long long ans = 0;
    for (long long i = 0; i <= c; i++) {
        if (i % 2) {
            ans = mod(ans - C(c, i) * exp(c - i, n), 998244353);
        } else {
            ans = mod(ans + C(c, i) * exp(c - i, n), 998244353);
        }
    }

    ans = mod(ans * C(n, c), 998244353);
    if (k > 0) ans = mod(ans * 2LL, 998244353);

    cout << ans << '\n';
}