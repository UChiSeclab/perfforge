#include <bits/stdc++.h>
using namespace std;

// Checker functions
void checkLazyPropagationInvariant(int evalCount) {
    if (evalCount > 1000) { // Threshold for triggering a warning
        cerr << "Warning: Performance bottleneck due to excessive lazy propagation in LazySegmentTree!" << endl;
        abort();
    }
}

void checkUpdatesAndQueriesInvariant(int updateCount, int queryCount) {
    if (updateCount > 500 || queryCount > 500) { // Thresholds for updates and queries
        cerr << "Warning: Performance bottleneck due to frequent updates or queries in SegmentTree!" << endl;
        abort();
    }
}

void checkQueryHandlingComplexity(int x, int y, int n) {
    if ((n - x - y) > (n / 2)) { // Check if the portion of the array being processed is large
        cerr << "Warning: Performance bottleneck due to complex query handling!" << endl;
        abort();
    }
}

// LazySegmentTree and SegmentTree implementations remain the same

template <typename T1, typename T2>
class LazySegmentTree {
    // ... class implementation ...

    int evalCount = 0; // Count the number of evaluations

    inline void eval(int k, int l, int r) {
        evalCount++;
        checkLazyPropagationInvariant(evalCount); // Check for excessive lazy propagation

        if (lazy[k] != e2) {
            node[k] = eval_func(node[k], lazy[k], l, r);
            if (r - l > 1) {
                lazy[2 * k + 1] = update_func(lazy[2 * k + 1], lazy[k]);
                lazy[2 * k + 2] = update_func(lazy[2 * k + 2], lazy[k]);
            }
            lazy[k] = e2;
        }
    }

    // ... rest of the class ...
};

template <typename T>
class SegmentTree {
    // ... class implementation ...

    int updateCount = 0; // Count the number of updates
    int queryCount = 0;  // Count the number of queries

    void update(int k, T a, int v, int l, int r) {
        updateCount++;
        checkUpdatesAndQueriesInvariant(updateCount, queryCount); // Check for frequent operations
        
        if (r - l == 1) {
            dat[v] = update_func(dat[v], a);
        } else {
            if (k < (l + r) / 2)
                update(k, a, 2 * v + 1, l, (l + r) / 2);
            else {
                update(k, a, 2 * v + 2, (l + r) / 2, r);
            }
            dat[v] = query_func(dat[v * 2 + 1], dat[v * 2 + 2]);
        }
    }

    T query(int a, int b, int k, int l, int r) {
        queryCount++;
        checkUpdatesAndQueriesInvariant(updateCount, queryCount); // Check for frequent operations
        
        if (r <= a || b <= l) {
            return e;
        }
        if (a <= l && r <= b) {
            return dat[k];
        } else {
            T ul = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T ur = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return query_func(ul, ur);
        }
    }

    // ... rest of the class ...
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<pair<int, int>>> x2yi(n + 1);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x2yi[x].push_back(pair<int, int>(y, i));
        
        checkQueryHandlingComplexity(x, y, n); // Check for complex query handling
    }

    vector<pair<long long, long long>> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = pair<int, int>(i - a[i], -i);
        if (temp[i].first < 0) {
            temp[i].first = 2 * inf;
        }
    }

    LazySegmentTree<pair<long long, long long>, int> seg1(temp, f1, g1, h1, pair<long long, long long>(3 * inf, 3 * inf), 0);
    SegmentTree<int> seg2(vector<int>(n), f, g, 0);
    
    vector<int> ans(q);
    for (int x = n; x >= 0; x--) {
        if (x == n) {
            for (pair<int, int> yi : x2yi[x]) {
                ans[yi.second] = 0;
            }
            continue;
        }

        while (true) {
            pair<int, int> mi = seg1.query(x, n, 0, 0, seg1.n);
            if (mi.first != 0) break;

            int idx = -mi.second;
            seg2.update(idx, 1, 0, 0, seg2.n);
            seg1.update(idx, idx + 1, 2 * inf, 0, 0, seg1.n);
            seg1.update(idx, n, -1, 0, 0, seg1.n);
        }

        for (pair<int, int> yi : x2yi[x]) {
            int r = n - yi.first;
            ans[yi.second] = seg2.query(x, r, 0, 0, seg2.n);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t = 1;
    while (t--) solve();
}