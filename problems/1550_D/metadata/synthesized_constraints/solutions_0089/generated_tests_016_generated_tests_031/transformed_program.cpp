#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int n = 0, l = 0, r = 0;
int fact[300001];

int pw(int a, int b) {
    // Check for modular exponentiation bottleneck
    check_modular_exponentiation_bottleneck(b);

    int c = 1;
    while (b) {
        if (b % 2 == 0) {
            a = a * a % MOD;
            b /= 2;
        } else {
            c = c * a % MOD;
            b--;
        }
    }
    return c;
}

int C(int n, int k) {
    // Check for combination calculation bottleneck
    check_combination_calculation_bottleneck(n, k);

    if (k == 0 || k == n)
        return 1;
    if (k < 0 || k > n)
        return 0;
    return fact[n] * pw(fact[k], MOD - 2) % MOD * pw(fact[n - k], MOD - 2) % MOD;
}

int solve_for(int minuses) {
    int mn = min(abs(1 - l), abs(r - n));
    int mx = max(r - 1, n - l);

    // Check for loop iterations bottleneck
    check_loop_iterations_bottleneck(mn, mx);

    int res = 0;
    res += mn * C(n, minuses) % MOD;
    res %= MOD;
    for (int d = mn + 1; d <= mx; d++) {
        int left_both = max(1ll, l + d);
        int right_both = min(n, r - d);
        if (right_both < left_both - 1)
            break;
        int can_both = max(0ll, right_both - left_both + 1);
        int have_minuses = n - right_both;
        int want_minuses = minuses - have_minuses;
        if (want_minuses < 0)
            continue;
        res += C(can_both, want_minuses) % MOD;
        res %= MOD;
    }
    return res;
}

void solve() {
    cin >> n >> l >> r;
    int res = solve_for(n / 2);
    if (n % 2 == 1)
        res += solve_for(n / 2 + 1);
    res %= MOD;
    cout << res;
}

signed main() {
    fact[0] = 1;
    for (int i = 1; i <= 300000; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}