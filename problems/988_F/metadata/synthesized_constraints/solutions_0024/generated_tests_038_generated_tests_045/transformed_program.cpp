#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e10;

ll n, m, q;
ll rain[2005], fatigue[2005], dp[2005][2005][2];

// Checkers for performance bottlenecks
void check_state_space_explosion(int a, int n, int m) {
    if (a > 1500 && m > 100) { // Heuristic threshold for explosion
        cerr << "Warning: Performance bottleneck condition triggered - State space explosion!" << endl;
        abort();
    }
}

void check_recursion_depth(int maxDepth) {
    if (maxDepth > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - Recursion depth too large!" << endl;
        abort();
    }
}

void check_umbrella_configurations(int m) {
    if (m > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - Too many umbrella configurations!" << endl;
        abort();
    }
}

void check_effective_memoization(int cacheHits, int recursiveCalls) {
    if (cacheHits < recursiveCalls / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - Ineffective memoization!" << endl;
        abort();
    }
}

ll rec(ll i, ll j, ll f) {
    static int recursiveCalls = 0;
    static int cacheHits = 0;
    recursiveCalls++;

    if (i > n) {
        return 0;
    }
    if (dp[i][j][f] != -1) {
        cacheHits++;
        return dp[i][j][f];
    }
    if (f) {
        if (!rain[i]) {
            return dp[i][j][f] =
                min(rec(i + 1, j, 1) + fatigue[j],
                    min(rec(i + 1, i, 1) + fatigue[i], rec(i + 1, n + 1, 0)));
        } else {
            return dp[i][j][f] = min(rec(i + 1, j, 1) + fatigue[j],
                                     rec(i + 1, i, 1) + fatigue[i]);
        }
    } else {
        if (!rain[i]) {
            return dp[i][j][f] =
                min(rec(i + 1, i, 1) + fatigue[i], rec(i + 1, n + 1, 0));
        } else {
            return dp[i][j][f] = rec(i + 1, i, 1) + fatigue[i];
        }
    }
}

void speed_solve() {
    int a;
    cin >> a >> q >> m;

    // Insert checker functions with initial parameters
    check_state_space_explosion(a, q, m);
    check_umbrella_configurations(m);

    memset(rain, 0, sizeof(rain));
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        for (ll j = l; j < r; j++) {
            rain[j] = 1;
        }
    }
    for (ll i = 0; i < 2005; i++) {
        fatigue[i] = inf;
    }
    for (ll i = 0; i < m; i++) {
        ll x, p;
        cin >> x >> p;
        fatigue[x] = min(fatigue[x], p);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = rec(0, n + 1, 0);

    // Check for memoization effectiveness after recursion
    check_effective_memoization(cacheHits, recursiveCalls);

    if (ans >= inf) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    speed_solve();
    return 0;
}