#include <bits/stdc++.h>
using namespace std;

map<pair<long long, long long>, bool> is_edge;
set<long long> unvisited;
map<long long, long long> visited;

void dfs(long long cur) {
    vector<long long> to_remove;
    for (auto it = unvisited.begin(); it != unvisited.end(); it++) {
        long long nbr = *it;
        if (is_edge[{min(cur, nbr), max(cur, nbr)}]) {
        } else {
            to_remove.push_back(nbr);
        }
    }
    for (long long a : to_remove) {
        unvisited.erase(a);
    }
    for (long long a : to_remove) {
        dfs(a);
    }
}

void check_large_nodes_few_edges(long long n, long long m) {
    if (n > 1000 && m < n / 10) { // Arbitrary thresholds chosen for demonstration
        cerr << "Warning: Potential slowdown due to large number of nodes with few edges!" << endl;
        abort();
    }
}

void check_recursive_exploration_without_edges(long long m) {
    if (m == 0) {
        cerr << "Warning: Potential slowdown due to recursive exploration without edge connections!" << endl;
        abort();
    }
}

void check_high_recursion_depth_low_edge_count(long long n, long long m) {
    if (n > 1000 && m < n / 20) { // Arbitrary thresholds chosen for demonstration
        cerr << "Warning: Potential slowdown due to high recursion depth with low edge count!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;

    // Insert checks after reading input and before processing
    check_large_nodes_few_edges(n, m);
    check_recursive_exploration_without_edges(m);
    check_high_recursion_depth_low_edge_count(n, m);

    for (long long i = 1; i <= n; i++) {
        unvisited.insert(i);
    }
    for (long long i = 1; i <= m; i++) {
        long long a, b;
        cin >> a >> b;
        is_edge[{min(a, b), max(a, b)}] = 1;
    }
    long long cc = 0;
    while (!unvisited.empty()) {
        long long cur = *unvisited.begin();
        unvisited.erase(unvisited.begin());
        dfs(cur);
        cc++;
    }
    cout << cc - 1 << endl;
    return 0;
}