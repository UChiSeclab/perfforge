#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
int seg[maxn * 4], dp[maxn];
int n, m, x, y;
vector<pair<int, int> > v[maxn];

// Checker functions
void check_dense_overlap_invariant(int overlapCount) {
    if (overlapCount > 10) {
        cerr << "Warning: Dense Overlapping Antennas detected - potential slowdown!" << endl;
        abort();
    }
}

void check_long_range_query_invariant(int range) {
    if (range > 10000) {
        cerr << "Warning: Long Range Queries detected - potential slowdown!" << endl;
        abort();
    }
}

void check_sparse_initial_coverage_invariant(int uncoveredPositions) {
    if (uncoveredPositions > 50000) {
        cerr << "Warning: Sparse Initial Coverage detected - potential slowdown!" << endl;
        abort();
    }
}

void modify(int now, int l, int r, int x, int v) {
    if (l == r) {
        seg[now] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
        modify(now * 2, l, m, x, v);
    else
        modify(now * 2 + 1, m + 1, r, x, v);
    seg[now] = min(seg[now * 2], seg[now * 2 + 1]);
}

int query(int now, int l, int r, int ql, int qr) {
    if (r < ql || l > qr)
        return inf;
    else if (l >= ql && r <= qr)
        return seg[now];
    int m = (l + r) >> 1;
    
    // Check for long range query
    check_long_range_query_invariant(qr - ql);
    
    return min(query(now * 2, l, m, ql, qr),
               query(now * 2 + 1, m + 1, r, ql, qr));
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    // Calculate initial uncovered positions
    int uncoveredPositions = m - n; // Rough estimate for initial check
    check_sparse_initial_coverage_invariant(uncoveredPositions);

    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        
        int overlapCount = 0; // To track dense overlaps

        for (int j = 0; j <= m; j++) {
            v[min(m, x + j)].push_back(make_pair(max(1, x - j), max(0, j - y)));
            
            // Increment overlap counter if antennas are close and small
            if (j <= 10 && y <= 5) { // Example: Thresholds for closeness
                overlapCount++;
            }
        }
        
        // Check for dense overlap
        check_dense_overlap_invariant(overlapCount);
    }
    
    for (int i = 1; i <= m; i++) modify(1, 1, m, i, inf);
    for (int i = 1; i <= m; i++) {
        dp[i] = inf;
        for (pair<int, int> j : v[i]) {
            if (j.first == 1)
                dp[i] = min(dp[i], j.second);
            else {
                int tmp = query(1, 1, m, j.first - 1, i - 1);
                if (tmp != inf) dp[i] = min(dp[i], tmp + j.second);
            }
        }
        modify(1, 1, m, i, dp[i]);
    }
    cout << dp[m] << '\n';
}