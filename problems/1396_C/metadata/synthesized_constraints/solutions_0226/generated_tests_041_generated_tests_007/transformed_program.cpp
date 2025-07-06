#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 20;
const long long maxg = 8;
long long x[maxn], y[maxn];
long long dp[maxn][maxg];

// Checker functions
void check_reload_time_invariant(long long r1, long long r2, long long r3, long long d) {
    if (r1 > 1e8 || r2 > 5e8 || r3 > 5e8) {
        cerr << "Warning: High reload time relative to teleportation time, possible slowdown!" << endl;
        abort();
    }
}

void check_monster_distribution_invariant(long long n, const vector<long long>& a) {
    long long max_monsters = *max_element(a.begin(), a.end());
    if (n > 1e5 && max_monsters > 8e5) {
        cerr << "Warning: Large number of stages with uneven monster distribution!" << endl;
        abort();
    }
}

void check_transition_complexity_invariant(long long n, long long d) {
    if (d < 10 && n > 1e5) {
        cerr << "Warning: Frequent low-cost transitions could cause inefficiencies!" << endl;
        abort();
    }
}

void check_strategic_depth_invariant(long long n, const vector<long long>& a, long long maxg) {
    long long total_monsters = accumulate(a.begin(), a.end(), 0LL);
    if (total_monsters * maxg > 1e8) {
        cerr << "Warning: Large strategic depth due to high monster count and gun options!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector<long long> a(n);
    
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Insert performance checks
    check_reload_time_invariant(r1, r2, r3, d);
    check_monster_distribution_invariant(n, a);
    check_transition_complexity_invariant(n, d);
    check_strategic_depth_invariant(n, a, maxg);

    for (long long i = 0; i < n; i++) {
        x[i] = 1LL * r1 * a[i] + r3;
        y[i] = min(1LL * r1 * a[i] + r1, r2) + r1;
    }
    memset(dp, 63, sizeof dp);
    dp[0][1] = 0;
    for (long long i = 0; i < n - 1; i++)
        for (long long j = 1; j < maxg; j++)
            for (long long k = 1; k < maxg; k++) {
                long long cal = dp[i][j] + 1LL * k * d;
                if ((j % 2) != (k % 2) && (j % 2) == 0) continue;
                if ((j + 1) / 2 + k / 2 >= 2)
                    cal += y[i];
                else
                    cal += x[i];
                dp[i + 1][k] = min(dp[i + 1][k], cal);
            }
    long long res = 8e18;
    for (long long i = 1; i < maxg; i++) {
        if ((i + 1) / 2 >= 2)
            res = min(res, dp[n - 1][i] + y[n - 1]);
        else
            res = min(res, dp[n - 1][i] + x[n - 1]);
    }
    cout << res << endl;
}