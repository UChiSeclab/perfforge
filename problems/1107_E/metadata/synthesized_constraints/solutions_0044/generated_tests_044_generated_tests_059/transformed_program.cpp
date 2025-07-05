#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1ll << 50, N = 101;
ll dp[2][N][N][N], ans[N][N];
ll n;
string s;
ll a[N];
ll solve_cnt(ll, ll, ll, ll);
ll solveCalls = 0, solveCntCalls = 0; // Counters for recursive calls

void check_recursive_calls(long long solveCalls, long long solveCntCalls) {
    if (solveCalls > 10000 || solveCntCalls > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive calls!" << endl;
        abort();
    }
}

void check_branching_factor(long long branchingOperations) {
    if (branchingOperations > 50000) {
        cerr << "Warning: Branching factor condition triggered - too many operations!" << endl;
        abort();
    }
}

void check_structure_complexity(int n, const std::string& s) {
    int transitions = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            transitions++;
        }
    }
    if (transitions > n / 2) {
        cerr << "Warning: Input structure condition triggered - complex interleaving detected!" << endl;
        abort();
    }
}

ll solve(ll l, ll r) {
    solveCalls++;
    if (l >= r) return 0;
    if (ans[l][r] != -1) return ans[l][r];
    ll ret = 0;
    for (ll cnt = 1; cnt <= r - l; cnt++) {
        ret = max(ret, solve_cnt(0, l, r, cnt) + a[cnt]);
        ret = max(ret, solve_cnt(1, l, r, cnt) + a[cnt]);
    }
    ans[l][r] = ret;
    return ret;
}

ll solve_cnt(ll c, ll l, ll r, ll cnt) {
    solveCntCalls++;
    if (cnt == 0) return solve(l, r);
    if (dp[c][l][r][cnt] != -1) return dp[c][l][r][cnt];
    ll ret = -INF;
    for (ll i = l; i < r; i++) {
        if (c == s[i] - '0')
            ret = max(ret, solve(l, i) + solve_cnt(c, i + 1, r, cnt - 1));
    }
    dp[c][l][r][cnt] = ret;
    return ret;
}

int main() {
    cin >> n >> s;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    check_structure_complexity(n, s); // Check input structure complexity
    memset(dp, -1, sizeof dp);
    memset(ans, -1, sizeof ans);
    ll result = solve(0, n);
    check_recursive_calls(solveCalls, solveCntCalls); // Check recursive calls
    check_branching_factor(solveCalls + solveCntCalls); // Check branching factor
    cout << result << endl;
    return 0;
}