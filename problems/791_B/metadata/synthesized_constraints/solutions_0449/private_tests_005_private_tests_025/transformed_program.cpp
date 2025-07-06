#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;

struct dsu {
    int *parent;
    int *size;
    void init(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int p(int x) {
        if (parent[x] == x) return x;
        return parent[x] = p(parent[x]);
    }
    void unite(int x, int y) {
        int supx = p(x);
        int supy = p(y);
        if (supx != supy) {
            if (size[x] > size[y]) {
                parent[supy] = supx;
                size[supx] += size[supy];
            } else {
                parent[supx] = supy;
                size[supy] += size[supx];
            }
        }
    }
};

// Checkers for performance bottlenecks
void check_component_size_invariant(int n, int m) {
    if (m == 0 && n > 100000) {
        cerr << "Warning: component_size_invariant triggered - excessive isolated nodes" << endl;
        abort();
    }
}

void check_union_find_invariant(int n, int m) {
    if (m == 0 && n > 100000) {
        cerr << "Warning: union_find_invariant triggered - many isolated nodes in union-find" << endl;
        abort();
    }
}

void check_initialization_overhead_invariant(int n, int m) {
    if (m == 0 && n > 100000) {
        cerr << "Warning: initialization_overhead_invariant triggered - excessive initialization for disconnected nodes" << endl;
        abort();
    }
}

unordered_map<int, vector<int>> o, l;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x, y;
    cin >> n >> m;

    // Insert invariant checks after reading input
    check_component_size_invariant(n, m);
    check_union_find_invariant(n, m);
    check_initialization_overhead_invariant(n, m);

    dsu d;
    d.init(n);

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--;
        y--;
        o[x].push_back(y);
        o[y].push_back(x);
        d.unite(x, y);
    }

    for (int i = 0; i < n; ++i) {
        x = d.p(i);
        l[x].push_back(i);
    }

    for (auto i : l) {
        vector<int> v = i.second;
        for (auto j : i.second) {
            for (auto k : i.second) {
                if (k != j) {
                    auto it = find(o[k].begin(), o[k].end(), j);
                    if (it == o[k].end()) {
                        cout << "NO";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES";
    return 0;
}