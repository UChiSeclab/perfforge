#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

// Checker functions for performance bottlenecks
void check_high_k_invariant(int n, int k) {
    if (k > n * 0.9) { // Assuming a threshold where k is close to n (e.g., within 10%)
        cerr << "Warning: Performance bottleneck condition triggered - high k relative to n!" << endl;
        abort();
    }
}

void check_large_m_invariant(int m) {
    if (m > 1500) { // Assuming a performance threshold for a high number of colors
        cerr << "Warning: Performance bottleneck condition triggered - large number of colors m!" << endl;
        abort();
    }
}

void check_quadratic_complexity_invariant(int n, int k) {
    if (n > 1000 && k > 1000) { // Assuming large values lead to inefficiency
        cerr << "Warning: Performance bottleneck condition triggered - quadratic complexity!" << endl;
        abort();
    }
}

int modpow(int a, int p) {
    int ans = 1;
    while (p > 0) {
        if (p & 1) ans = 1LL * ans * a % MOD;
        a = 1LL * a * a % MOD;
        p >>= 1;
    }
    return ans;
}

long long inv(int n) { return modpow(n, MOD - 2); }
ll mult(int a, int b) { return a * 1ll * b % MOD; }
ll dp[2001][2001];
int solvedp() {
    int n, m, k;
    cin >> n >> m >> k;

    // Insert performance checks after reading inputs
    check_high_k_invariant(n, k);
    check_large_m_invariant(m);
    check_quadratic_complexity_invariant(n, k);

    dp[1][0] = m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j] % MOD) % MOD;
            if (j > 0)
                dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1] * (m - 1) % MOD) % MOD) % MOD;
        }
    }
    return dp[n][k];
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> fact(2333, 0);
    fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * (ll)i % MOD;
    }
    ll res =
        mult(mult(mult(mult(fact[n - 1], inv(fact[k])), inv(fact[n - 1 - k])), m),
             modpow(m - 1, k));
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << solvedp() << endl;
    return 0;
}