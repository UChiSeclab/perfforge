#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double EPS = 1e-9;
const long double PI = acos(-1);
const long long INF = 1e18;
const long long mod = 1e9 + 7;

void check_mx_invariant(int mx) {
    if (mx > 100000) { // Broad threshold considering the constraints
        cerr << "Warning: Performance bottleneck condition triggered due to large mx!" << endl;
        abort();
    }
}

void check_array_invariant(int n, int mx) {
    if ((mx > 10 * n) && (n < 100)) { // Assumes sparsity if mx is much larger than n
        cerr << "Warning: Performance bottleneck condition triggered due to sparse beacon positions!" << endl;
        abort();
    }
}

void check_power_invariant(const vector<int>& powers) {
    for (const auto& power : powers) {
        if (power > 100000) { // Threshold assuming a large power level
            cerr << "Warning: Performance bottleneck condition triggered due to large power level!" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases = 1, tt = 1;
    while (test_cases--) {
        int n, mx = 0;
        cin >> n;

        memset(p, 0, sizeof(p)), memset(pf, 0, sizeof(pf));
        int power[1000005];
        memset(power, 0, sizeof(power));

        vector<int> powers;
        for (int i = 0; i <= n - 1; i++) {
            int a, b;
            cin >> a >> b;
            power[a] = b;
            p[a] = 1;
            mx = max(mx, a);
            powers.push_back(b);
        }

        // Insert checks based on performance-characterizing invariants
        check_mx_invariant(mx);
        check_array_invariant(n, mx);
        check_power_invariant(powers);

        for (int i = 0; i <= mx; i++) {
            pf[i] = (i - 1 >= 0 ? pf[i - 1] : 0) + p[i];
        }
        memset(dp, 0, sizeof(dp));
        int ans = 1e7;
        for (int i = 0; i <= mx; i++) {
            if (p[i]) {
                if (i - power[i] < 0)
                    dp[i] = pf[i] - 1;
                else {
                    if (i - power[i] == 0) {
                        if (p[0] == 0)
                            dp[i] = dp[i - power[i]] + pf[i] - pf[i - power[i]] - 1;
                        else
                            dp[i] = dp[i - power[i]] + pf[i] - (pf[i - power[i]] - 1) - 1;
                    } else
                        dp[i] = dp[i - power[i] - 1] + pf[i] - pf[i - power[i] - 1] - 1;
                }
                ans = min(ans, dp[i] + pf[mx] - pf[i]);
            } else {
                dp[i] = (i - 1 >= 0 ? dp[i - 1] : 0);
            }
        }
        cout << ans << endl;
    }
    return 0;
}