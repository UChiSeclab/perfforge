#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS = 1e-8;
const int INF = 0x3F3F3F3F;
const ll LINF = 4611686018427387903;
const int MOD = 1e9 + 7;

// Checker Functions

// Check for small k values leading to inefficient looping
void check_small_k_invariant(int k, int N) {
    if (k < 2) {
        cerr << "Warning: Performance bottleneck triggered - small k value leading to inefficient looping." << endl;
        abort();
    }
}

// Check for large product of n and m/2 relative to k
void check_large_product_invariant(int n, int m, int k) {
    if (n * (m / 2) > 1000) { // The threshold is arbitrary and should be adjusted based on empirical testing
        cerr << "Warning: Potential performance issue due to large product of n and m/2 relative to k." << endl;
        abort();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    const int N = 70 * 35 * 70 + 25;
    bitset<N> dp[2];
    dp[1] = 1;
    int n, m, k, prv = 0, cur = 1;
    cin >> n >> m >> k;

    // Insert checks based on inferred invariants
    check_small_k_invariant(k, N);   // Check for small k values
    check_large_product_invariant(n, m, k);  // Check for large product of n and m/2

    vector<bitset<70 * 35 + 25>> owo(m / 2 + 1);
    for (int i = 0; i < n; i++) {
        swap(prv, cur);
        for (int i = 0; i <= m / 2; i++) owo[i].reset();
        owo[0][0] = 1;
        for (int j = 1, x; j <= m; j++) {
            cin >> x;
            for (int k = m / 2; k; k--) owo[k] = (owo[k - 1] << x) | owo[k];
        }
        for (int i = 1; i <= m / 2; i++) owo[i] = owo[i] | owo[i - 1];
        for (int j = 0; j <= 70 * 35 + 5; j++)
            if (owo[m / 2][j]) dp[cur] = dp[cur] | (dp[prv] << j);
    }
    int ans = 0;
    for (int i = k; i < N; i += k)
        if (dp[cur][i]) ans = i;
    cout << ans << '\n';
    return 0;
}