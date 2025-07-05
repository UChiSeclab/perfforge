#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
const int mod = 1000000000 + 7;
long long S[maxn][maxn];

long long qpow(long long a, long long k) {
    long long res = 1;
    while (k) {
        if (k & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

long long inv(long long x) { return qpow(x, mod - 2); }

// Performance invariant checks
void check_power_computation_invariant(long long n, long long k) {
    if (n > 100000 && k > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive power computation!" << endl;
        abort();
    }
}

void check_stirling_calculation_invariant(long long n, long long k) {
    if (n > k && k > 3000) {
        cerr << "Warning: Performance bottleneck condition triggered - expensive Stirling number calculation!" << endl;
        abort();
    }
}

void check_large_n_invariant(long long n, long long k) {
    if (n > 500000 && n > k) {
        cerr << "Warning: Performance bottleneck condition triggered - large n loop dependency!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Insert checks right after reading input
    check_power_computation_invariant(n, k);
    check_stirling_calculation_invariant(n, k);
    check_large_n_invariant(n, k);
    
    if (n <= k) {
        long long ans = 0, c = 1;
        for (int i = 1; i <= n; i++) {
            c = c * (n - i + 1) % mod * inv(i) % mod;
            ans = (ans + c * qpow(i, k) % mod) % mod;
        }
        printf("%lld\n", ans);
    } else {
        S[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= i; j++) {
                S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j]) % mod;
            }
        }
        long long ans = 0;
        long long t1 = 1, t2 = 1;
        for (int j = 1; j <= k; j++) {
            t1 = t1 * j % mod;
            t2 = t2 * (n - j + 1) % mod * inv(j) % mod;
            ans = (ans + S[k][j] * t1 % mod * t2 % mod * qpow(2, n - j) % mod) % mod;
        }
        printf("%lld\n", ans);
    }
    getchar();
    getchar();
    return 0;
}