#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

// Checker functions
void check_large_k_invariant(long long k) {
    if (k > 1e8) {
        cerr << "Warning: Performance bottleneck condition triggered due to large k!" << endl;
        abort();
    }
}

void check_high_n_invariant(long long n) {
    if (n > 240) {
        cerr << "Warning: Performance bottleneck condition triggered due to high n!" << endl;
        abort();
    }
}

void check_combinatorial_invariant(long long n) {
    if (n > 240) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive combinatorial calculations!" << endl;
        abort();
    }
}

long long powmod(long long a, long long n) {
    long long ans = 1;
    while (n) {
        if (n % 2 == 1) ans = ans * a % mod;
        n /= 2;
        a = a * a % mod;
    }
    return ans;
}

long long fac[250 * 250 + 5], fnv[250 * 250 + 5];
long long C(int n, int m) {
    if (m < 0 || n < 0) return 0;
    if (n == 0 || m == 0) return 1;
    return fac[n] * fnv[m] % mod * fnv[n - m] % mod;
}

long long dp[255][255], cnt[255][255];

int main() {
    long long n, k;
    cin >> n >> k;

    // Insert the checks after reading input
    check_large_k_invariant(k);
    check_high_n_invariant(n);
    check_combinatorial_invariant(n);

    if (k == 1) return 0 * printf("1\n");
    fac[0] = fnv[0] = 1;
    for (long long i = 1; i <= n * n; ++i) fac[i] = fac[i - 1] * i % mod;
    for (long long i = 1; i <= n * n; ++i) fnv[i] = powmod(fac[i], mod - 2);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int kk = max(1, j - i); kk <= j; ++kk) {
                int add = j - i;
                long long p =
                    C(i, kk - add) * C(n - i, add) % mod * powmod(k - 1, n - kk) % mod;
                cnt[i][j] +=
                    C(i, kk - add) * C(n - i, add) % mod * powmod(k - 1, n - kk) % mod;
                cnt[i][j] %= mod;
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) dp[1][i] = C(n, i) * powmod(k - 1, n - i) % mod;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = j; k <= n; ++k) {
                dp[i + 1][k] += dp[i][j] * cnt[j][k] % mod;
                dp[i + 1][k] %= mod;
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}