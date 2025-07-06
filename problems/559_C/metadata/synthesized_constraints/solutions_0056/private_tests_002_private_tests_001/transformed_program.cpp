#include <bits/stdc++.h>
using namespace std;
const int N = 100100, M = 2010, MOD = 1e9 + 7;
int dp[M], fact[2 * N], inv[2 * N];
pair<int, int> p[M];

// Modular operation
int mod(int x) { return ((x % MOD) + MOD) % MOD; }

// Power module operation
int powmod(int a, int x) {
    if (x == 0) return 1;
    if (x % 2 == 0) {
        int half = powmod(a, x / 2);
        return ((long long)half * half) % MOD;
    }
    return ((long long)a * powmod(a, x - 1)) % MOD;
}

// Precomputation of factorials and inversions
void pre(int n) {
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = ((long long)i * fact[i - 1]) % MOD;
        inv[i] = powmod(fact[i], MOD - 2);
    }
}

// Combination function
int nCp(int n, int p) {
    int ans = ((long long)fact[n] * inv[p]) % MOD;
    ans = ((long long)ans * inv[n - p]) % MOD;
    return ans;
}

// Calculate number of ways to go from p1 to p2
int go(pair<int, int> p1, pair<int, int> p2) {
    return nCp(p2.first - p1.first + p2.second - p1.second, p2.first - p1.first);
}

// Invariant check implementations
void check_combinatorial_invariant(int h, int w) {
    if (h + w > 200000) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive combinatorial calculations for large h + w!" << endl;
        abort();
    }
}

void check_modular_inversion_invariant(int h, int w) {
    if (h + w > 200000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive modular inversions due to large factorial computations!" << endl;
        abort();
    }
}

void check_large_board_dimensions(int h, int w) {
    if (h > 10000 || w > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - large board dimensions causing factorial scaling issues!" << endl;
        abort();
    }
}

int main() {
    int h, w, m;
    scanf("%d %d %d", &h, &w, &m);
    
    // Run performance checks
    check_combinatorial_invariant(h, w);
    check_modular_inversion_invariant(h, w);
    check_large_board_dimensions(h, w);

    pre(h + w);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    p[m] = make_pair(h, w);
    sort(p, p + m);

    for (int i = 0; i <= m; i++) {
        dp[i] = go(make_pair(1, 1), p[i]);
        for (int j = 0; j < i; j++) {
            if (p[j].second <= p[i].second) {
                int tmp = ((long long)dp[j] * go(p[j], p[i])) % MOD;
                dp[i] = mod(dp[i] - tmp);
            }
        }
    }

    printf("%d\n", dp[m]);
    return 0;
}