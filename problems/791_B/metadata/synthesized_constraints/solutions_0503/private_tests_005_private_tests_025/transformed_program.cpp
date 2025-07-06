#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

class graph {
 public:
  vector<long long> *g;
  long long n;
  graph(long long v) {
    n = v;
    g = new vector<long long>[n];
  }
  void addedge(long long u, long long v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bool BFS(long long u, long long vis[]) {
    queue<long long> q;
    q.push(u);
    vector<long long> v;
    while (!q.empty()) {
      long long x = q.front();
      q.pop();
      if (vis[x] == 0) {
        vis[x] = 1;
        v.push_back(x);
        for (long long i = 0; i < g[x].size(); i++) q.push(g[x][i]);
      }
    }
    long long x = v.size();
    for (long long i = 0; i < x; i++) {
      if (g[v[i]].size() != x - 1) return false;
    }
    return true;
  }
};

void check_graph_initialization_invariant(long long n, long long m) {
    if (n > 100000 && m < n / 10) { // Arbitrary threshold: large graph with very few edges
        cerr << "Warning: Performance bottleneck due to large graph with few edges!" << endl;
        abort();
    }
}

void check_bfs_invariant(long long n, long long m) {
    if (n > 100000 && m == 0) { // Specific case: large number of nodes, no edges
        cerr << "Warning: Performance bottleneck due to redundant BFS calls!" << endl;
        abort();
    }
}

void solve() {
  long long n, m;
  cin >> n >> m;

  // Insert invariant checks after reading inputs
  check_graph_initialization_invariant(n, m);
  check_bfs_invariant(n, m);

  graph G(n + 1);
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    G.addedge(u, v);
  }
  long long vis[n + 1];
  memset(vis, 0, sizeof(vis));
  for (long long i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      if (!G.BFS(i, vis)) {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  cout << "YES" << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}