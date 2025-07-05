#include <bits/stdc++.h>
using namespace std;
const long long int inf = (long long int)1e18 + 10;
map<pair<long long int, long long int>, long long int> m;
vector<pair<long long int, long long int> > v;
long long int ans = 0;
long long int val[10];
void dfs(long long int x) {
    static int mapOperationCount = 0;

    for (long long int i = 1; i <= 6; i++) {
        val[x] = i;
        if (x != 1)
            dfs(x - 1);
        else {
            long long int cnt = 0;
            for (long long int j = 0; j < v.size(); j++) {
                long long int f = v[j].first, t = v[j].second;
                if (m.find({val[f], val[t]}) == m.end()) {
                    m[{val[f], val[t]}] = 1, m[{val[t], val[f]}] = 1, cnt++;
                    mapOperationCount++;
                }
            }
            ans = max(ans, cnt);
            m.clear();
        }
        check_map_operation_invariant(mapOperationCount);  // Check map operation frequency
    }
}

void check_edge_count_invariant(int vertices, int edges) {
    if (edges > vertices * (vertices - 1) / 4) {
        cerr << "Warning: edge_count_invariant triggered - high edge count!" << endl;
        abort();
    }
}

void check_dfs_invariant(int vertices) {
    if (vertices >= 7) {
        cerr << "Warning: dfs_invariant triggered - high DFS depth!" << endl;
        abort();
    }
}

void check_map_operation_invariant(int operationCount) {
    if (operationCount > 1000000) {
        cerr << "Warning: map_operation_invariant triggered - excessive map operations!" << endl;
        abort();
    }
}

void check_graph_connectivity_invariant(int vertices, int edges) {
    if (edges == vertices * (vertices - 1) / 2) {
        cerr << "Warning: graph_connectivity_invariant triggered - high connectivity!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int n, me, x, y;
    cin >> n >> me;
    
    check_dfs_invariant(n);  // Check DFS depth based on vertices
    check_edge_count_invariant(n, me);  // Check edge count against vertices
    check_graph_connectivity_invariant(n, me);  // Check graph connectivity
    
    for (long long int i = 1; i <= me; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    dfs(n);
    cout << ans << endl;
}