#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(const T niz[], const int siz) {
    for (int i = 0; i < siz; i++) cout << niz[i] << " ";
    cout << endl;
}

int n, m;
vector<int> graf[100005];
int dsu[100005];
int sajz[100005];

int findpar(int x) {
    if (x == dsu[x]) return x;
    return dsu[x] = findpar(dsu[x]);
}

void unite(int x, int y) {
    int a = findpar(x);
    int b = findpar(y);
    if (a == b) return;
    if (sajz[a] > sajz[b]) {
        dsu[a] = b;
        sajz[b] += sajz[a];
    } else {
        dsu[b] = a;
        sajz[a] += sajz[b];
    }
}

void init() {
    for (int(i) = (1); (i) <= (n); ++(i)) {
        dsu[i] = i;
        sajz[i] = 1;
    }
}

int deg[100005];
vector<pair<int, int> > v;
map<pair<int, int>, bool> poj;
bool bad[100005];

// Checker functions for performance bottlenecks
void check_large_vertices_few_edges(int n, int m) {
    if (n > 10000 && m < n / 10) {  // Condition: Large number of vertices with few edges
        cerr << "Warning: Large vertex set with minimal edges - potential inefficiency!" << endl;
        abort();
    }
}

void check_extensive_union_find_operations(int ops, int n) {
    if (ops > 20 * n) {  // Condition: Many DSU operations relative to the number of vertices
        cerr << "Warning: Excessive union-find operations - potential inefficiency!" << endl;
        abort();
    }
}

void check_redundant_checks_in_sparse_graphs(int n, int m) {
    if (n > 5000 && m < n / 5) {  // Condition: Sparse graph with large `n`
        cerr << "Warning: Redundant checks in sparse graphs - potential inefficiency!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    // Performance checks based on input size
    check_large_vertices_few_edges(n, m);
    check_redundant_checks_in_sparse_graphs(n, m);

    init();
    for (int(i) = (0); (i) <= (m - 1); ++(i)) {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    for (int(i) = (1); (i) <= (n); ++(i)) v.push_back({-deg[i], i});
    sort(v.begin(), v.end());

    int ops = 0;
    int sol = 0;

    for (auto c : v) {
        for (int i = 1; i <= n; i++) bad[i] = 0;
        for (auto k : graf[c.second]) bad[k] = 1;
        for (int i = 1; i <= n; i++) {
            if (i == c.second || bad[i]) continue;
            unite(i, c.second);
        }
        ops += n;
        check_extensive_union_find_operations(ops, n);  // Check excessive DSU operations
        if (ops > 20000000) break;
    }

    for (int(i) = (1); (i) <= (n); ++(i))
        if (findpar(i) == i) sol++;

    cout << sol - 1 << endl;
    return 0;
}