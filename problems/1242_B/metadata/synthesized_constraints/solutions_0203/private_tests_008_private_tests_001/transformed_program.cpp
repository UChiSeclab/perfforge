#include <bits/stdc++.h>
using namespace std;

vector<int> p, s;
set<int> par;

int get(int v) {
    return (p[v] == v) ? v : (p[v] = get(p[v]));
}

void unite(int a, int b, int& successfulUnites) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (s[a] < s[b]) swap(a, b);
    p[b] = a;
    s[a] += s[b];
    par.erase(b);
    par.insert(a);
    successfulUnites++;  // Track successful unifications
}

// Performance Checker Functions
void check_high_vertex_low_edge(int n, int m) {
    if (n > 90000 && m == 0) {
        cerr << "Warning: Performance bottleneck condition - high vertex count with no edges." << endl;
        abort();
    }
}

void check_large_disjoint_sets(int disjointSetCount, int n) {
    if (disjointSetCount == n) {
        cerr << "Warning: Performance bottleneck condition - many disjoint sets remaining." << endl;
        abort();
    }
}

void check_inefficient_union_find(int uniteAttempts, int successfulUnites) {
    if (uniteAttempts > 100000 && successfulUnites < uniteAttempts / 10) {
        cerr << "Warning: Performance bottleneck condition - inefficient union-find merging." << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    // Add performance checker for high vertex count and low edge density
    check_high_vertex_low_edge(n, m);

    p.resize(n);
    s.resize(n);
    vector<vector<int>> g(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a < b) swap(a, b);
        g[a].push_back(b);
    }

    int uniteAttempts = 0;
    int successfulUnites = 0;

    for (int v = 0; v < n; ++v) {
        p[v] = v, s[v] = 1;
        par.insert(v);
        map<int, int> cnt;
        for (int u : g[v]) ++cnt[get(u)];
        set<int> bb(par.begin(), par.end());
        for (int u : bb) {
            uniteAttempts++;
            if (u != v && cnt[u] < s[u]) unite(u, v, successfulUnites);
        }
    }

    // Check performance conditions after main processing
    check_large_disjoint_sets(par.size(), n);
    check_inefficient_union_find(uniteAttempts, successfulUnites);

    cout << par.size() - 1;
}