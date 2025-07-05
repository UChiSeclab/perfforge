#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;

void check_initialization_invariant(int n) {
    if (n > 140000) { 
        cerr << "Warning: Initialization invariant triggered - large n value for initialization." << endl;
        abort();
    }
}

void check_dsu_invariant(int n, int m) {
    if (n > 100000 && m < 500) { 
        cerr << "Warning: DSU invariant triggered - inefficient component identification due to sparse connections." << endl;
        abort();
    }
}

void check_iteration_invariant(int n, int isolated_components) {
    if (isolated_components > n / 2) { 
        cerr << "Warning: Iteration invariant triggered - excessive iteration over isolated components." << endl;
        abort();
    }
}

int o[150000];

struct dsu {
    int *parent;
    int *size;
    void init(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
            o[i] = 0;
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

unordered_map<int, vector<int>> l;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x, y;
    cin >> n >> m;

    check_initialization_invariant(n); // Check before initialization
    check_dsu_invariant(n, m); // Check DSU conditions

    dsu d;
    d.init(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--;
        y--;
        o[x]++;
        d.unite(x, y);
    }
    int isolated_components = 0; // Count isolated components
    for (int i = 0; i < n; ++i) {
        x = d.p(i);
        l[x].push_back(i);
    }
    check_iteration_invariant(n, isolated_components); // Check iteration conditions

    for (auto i : l) {
        long long int vertices = i.second.size();
        long long int edges = 0;
        for (int j : i.second) {
            edges += o[j];
        }
        if (edges != ((vertices) * (vertices - 1)) / 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}