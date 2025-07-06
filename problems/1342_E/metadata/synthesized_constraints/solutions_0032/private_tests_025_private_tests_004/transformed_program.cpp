#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int MX = 2e5 + 5;
long long n, k, f[MX];

long long fpow(long long a, long long p) {
    long long res = 1LL;
    while (p) {
        if (p & 1LL) res = res * a % MOD;
        a = a * a % MOD;
        p >>= 1LL;
    }
    return res;
}

long long nCk(long long N, long long K) {
    long long res = f[N];
    res = res * fpow(f[N - K], MOD - 2LL) % MOD;
    res = res * fpow(f[K], MOD - 2LL) % MOD;
    return res % MOD;
}

long long stirling(long long N, long long K) {
    long long res = 0LL;
    for (int j = 0; j <= K; ++j) {
        long long tmp = nCk(K, j) * fpow(j, N) % MOD;
        if ((K - j) & 1) tmp = -tmp;
        res += tmp;
        if (res >= MOD) res -= MOD;
        if (res < 0) res += MOD;
    }
    res = res * fpow(f[K], MOD - 2LL) % MOD;
    return res;
}

// Checker functions
void check_high_exponentiation_cost(bool condition) {
    if (condition) {
        cerr << "Warning: High exponentiation cost - frequent large exponent calculations" << endl;
        abort();
    }
}

void check_combinatorial_computations(bool condition) {
    if (condition) {
        cerr << "Warning: Extensive combinatorial computations - high cost due to low k relative to n" << endl;
        abort();
    }
}

void check_nested_loop_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: Nested loop complexity - high iterations due to low k relative to n" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;

    // Place checker conditions appropriately
    check_high_exponentiation_cost(n > 100000 && k < 1000);
    check_combinatorial_computations(n > 100000 && k < 1000);
    check_nested_loop_complexity(n > 100000 && k < 1000);

    if (k >= n) {
        cout << 0;
        return 0;
    }

    f[0] = 1LL;
    for (int i = 1; i < MX; ++i) f[i] = f[i - 1] * i % MOD;

    long long res = nCk(n, k) * stirling(n, n - k) % MOD;
    res = res * f[n - k] % MOD;
    if (k) res = res * 2LL % MOD;
    cout << res;
}