#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;

// Function to check for high number of vertices with no edges
void check_high_vertices_no_edges(int n, int m) {
    if (n > 10000 && m == 0) {
        cerr << "Warning: High number of vertices with no edges can lead to performance bottleneck!" << endl;
        abort();
    }
}

// Function to check for large number of disjoint sets
void check_disjoint_sets(int n, int m) {
    if (n > 10000 && m < n / 2) {
        cerr << "Warning: Large number of disjoint sets with few connections detected!" << endl;
        abort();
    }
}

// Function to check for initialization overhead
void check_initialization_overhead(int n) {
    if (n > 10000) {
        cerr << "Warning: Initialization overhead is high due to large number of members!" << endl;
        abort();
    }
}

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

unordered_map<int, vector<int>> o, l;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x, y;
    cin >> n >> m;

    // Perform checks before proceeding with the main logic
    check_high_vertices_no_edges(n, m);
    check_disjoint_sets(n, m);
    check_initialization_overhead(n);

    dsu d;
    d.init(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--;
        y--;
        o[x].push_back(y);
        d.unite(x, y);
    }
    for (int i = 0; i < n; ++i) {
        x = d.p(i);
        l[x].push_back(i);
    }
    for (auto i : l) {
        long long int vertices = i.second.size();
        long long int edges = 0;
        for (int j : i.second) {
            edges += o[j].size();
        }
        if (edges != ((vertices) * (vertices - 1)) / 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}