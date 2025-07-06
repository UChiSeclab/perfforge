#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
set<int> notvis;
set<int>::iterator it;

void dfs(int a) {
    set<int>::iterator it1;
    int i, b, l;
    vector<int> vis;
    for (it1 = notvis.begin(); it1 != notvis.end(); it1++) {
        b = *it1;
        if (mp[{a, b}] == 0) {
            vis.push_back(b);
        }
    }
    l = vis.size();
    for (i = 0; i < l; i++) {
        notvis.erase(vis[i]);
    }
    for (i = 0; i < l; i++) {
        dfs(vis[i]);
    }
}

// Checkers implementation
void check_large_graph_invariant(int n, int m) {
    if (n > 10000 && m == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - large graph with no weighted edges" << endl;
        abort();
    }
}

void check_recursion_invariant(int n, int m) {
    if (n > 10000 && m < n / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth with minimal edges" << endl;
        abort();
    }
}

void check_set_operations_invariant(int n, int m) {
    if (n > 10000 && m == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient set operations" << endl;
        abort();
    }
}

int main() {
    int a, b, c, d, e, i, j, k, l, n, m, x, y, t, p;
    scanf("%d%d", &n, &m);

    // Insert checks after reading inputs
    check_large_graph_invariant(n, m);
    check_recursion_invariant(n, m);
    check_set_operations_invariant(n, m);

    for (i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        mp[{a, b}] = mp[{b, a}] = 1;
    }
    for (i = 1; i <= n; i++) {
        notvis.insert(i);
    }
    x = 0;
    while (!notvis.empty()) {
        x++;
        it = notvis.begin();
        a = *it;
        notvis.erase(a);
        dfs(a);
    }
    x--;
    printf("%d\n", x);
}