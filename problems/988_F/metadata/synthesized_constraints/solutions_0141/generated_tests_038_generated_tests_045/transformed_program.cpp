#include <bits/stdc++.h>
using namespace std;

long long a, n, m, l, r, rain[2010], w[2010], End[2010];
const long long Inf = 1e11;
long long dp[2010][2010];

void check_recursion_depth_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high effective recursion depth or prolonged carrying due to sparse umbrellas." << endl;
        abort();
    }
}

void check_memoization_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of recursive states due to rain segments and sparse umbrellas." << endl;
        abort();
    }
}

void check_umbrella_weight_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - heavy umbrellas carried over long distances." << endl;
        abort();
    }
}

long long Rec(long long i, long long taken) {
    // Check recursion depth and memoization usage
    check_recursion_depth_invariant(i > 1000);
    check_memoization_invariant(dp[i][taken] != -1);

    if (i == a + 1) return 0;
    if (dp[i][taken] != -1) return dp[i][taken];

    long long Res1 = Inf, Res2 = Inf, Res3 = Inf;
    if (w[i]) Res1 = w[i] + Rec(i + 1, i);
    if (taken) Res2 = w[taken] + Rec(i + 1, taken);
    if (!rain[i] || End[i]) Res3 = Rec(i + 1, 0);

    // Check if carrying heavy umbrellas over extended distances
    check_umbrella_weight_invariant((Res1 > 10 * a) || (Res2 > 10 * a));

    return dp[i][taken] = min(Res1, min(Res2, Res3));
}

int main() {
    cin >> a >> n >> m;

    for (long long i = 0; i < n; i++) {
        cin >> l >> r;
        l++;
        r++;
        End[r]++;
        for (long long j = l; j <= r; j++) rain[j]++;
    }

    for (long long i = 1; i <= a; i++) w[i] = Inf;

    for (long long i = 0; i < m; i++) {
        cin >> l >> r;
        l++;
        w[l] = min(r, w[l]);
    }

    memset(dp, -1, sizeof(dp));

    Rec(1, 0) >= Inf ? cout << "-1" : cout << Rec(1, 0);
    return 0;
}