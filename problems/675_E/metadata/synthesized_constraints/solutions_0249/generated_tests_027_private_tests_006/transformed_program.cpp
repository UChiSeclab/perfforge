#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 20;
int a[MAXN];
long long dp[MAXN];
pair<long long, int> spt[MAXN][LOG];
int lg[MAXN];
int n;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

pair<long long, int> RMQ(int lx, int rx) {
    int j = lg[rx - lx + 1];
    return max(spt[lx][j], spt[rx - (1 << j) + 1][j]);
}

void check_sparse_table_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Sparse Table construction or querying is potentially expensive!" << endl;
        abort();
    }
}

void check_dp_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Dynamic programming updates are extensive for large ranges!" << endl;
        abort();
    }
}

void check_rmq_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: RMQ function is called with large and overlapping ranges!" << endl;
        abort();
    }
}

int main() {
    fast_io();
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    
    // Check for sparse table construction potential bottleneck
    check_sparse_table_invariant(n > 1000 && all_of(a + 1, a + n, [n](int ai) { return ai >= n - 1; }));

    for (int i = 2; i < MAXN; i++) {
        lg[i] = 1 + lg[i >> 1];
    }
    for (int i = 1; i <= n; i++) {
        spt[i][0] = make_pair(a[i], -i);
    }
    for (int j = 1; j <= lg[n]; j++) {
        for (int i = 1; i + (1 << j) < MAXN; i++)
            spt[i][j] = max(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
    }

    long long ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        pair<long long, int> q = RMQ(i + 1, a[i]);
        q.second *= -1;
        
        // Check for dynamic programming updates bottleneck
        check_dp_invariant(a[i] >= n - 1);

        dp[i] = (n + q.second) - (a[i] + i) + dp[q.second];
        ans += dp[i];
    }

    // Check for RMQ function being a bottleneck
    check_rmq_invariant(n > 1000 && any_of(a + 1, a + n, [n](int ai) { return ai >= n - 1; }));

    printf("%lld\n", ans);
    return 0;
}