#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

int dp[1001][1001];

void check_large_n_invariant(int n) {
    if (n > 90) {
        cerr << "Warning: Performance bottleneck condition triggered! - Large n causing deep recursion" << endl;
        abort();
    }
}

void check_high_k_invariant(int k) {
    if (k > 90) {
        cerr << "Warning: Performance bottleneck condition triggered! - High branching factor" << endl;
        abort();
    }
}

void check_memoization_invariant(int n, int k) {
    if (n > 90 && k > 90) {
        cerr << "Warning: Performance bottleneck condition triggered! - Memoization inefficiency" << endl;
        abort();
    }
}

void check_weight_constraint_invariant(int d, int k) {
    if (d < k / 2) {
        cerr << "Warning: Performance bottleneck condition triggered! - Path validity constraint" << endl;
        abort();
    }
}

int getval(int n, int k, int d, int m) {
    if (n < 0) {
        return 0;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    if (n == 0) {
        if (m >= d) {
            return 1;
        }
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += getval(n - i, k, d, max(m, i));
        ans %= 1000000007;
    }
    ans %= 1000000007;
    return dp[n][m] = ans;
}

void solve() {
    memset((dp), (-1), sizeof(dp));
    int n, k, d;
    cin >> n >> k >> d;

    // Insert checks after reading inputs
    check_large_n_invariant(n);
    check_high_k_invariant(k);
    check_memoization_invariant(n, k);
    check_weight_constraint_invariant(d, k);

    cout << getval(n, k, d, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    solve();
}