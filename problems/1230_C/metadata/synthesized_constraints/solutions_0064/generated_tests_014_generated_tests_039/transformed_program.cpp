#include <bits/stdc++.h>
using namespace std;

void check_edge_invariant(int n, int m) {
    if (m > n * 3) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of edges relative to vertices!" << endl;
        abort();
    }
}

void check_recursive_invariant(int maxDepth, int branchingFactor) {
    if (maxDepth > 5 && branchingFactor > 1) {
        cerr << "Warning: Performance bottleneck condition triggered due to high recursion depth and branching factor!" << endl;
        abort();
    }
}

void check_symmetry_invariant(int m, vector<pair<int, int>>& edges) {
    set<pair<int, int>> uniqueEdges;
    for (const auto& edge : edges) {
        int u = min(edge.first, edge.second);
        int v = max(edge.first, edge.second);
        uniqueEdges.insert({u, v});
    }
    if (uniqueEdges.size() < m) {
        cerr << "Warning: Performance bottleneck condition triggered due to duplicate or symmetrical edge evaluations!" << endl;
        abort();
    }
}

const double eps = 1e-5;
const long long base = 1000000007LL;
const int N = 105;
int n, m, a[8], res = 0;
pair<int, int> edge[30];

void Try(int x, int depth) {
  if (x > n) {
    set<pair<int, int> > S;
    for (int i = 1; i <= m; ++i) {
      int u, v;
      u = a[edge[i].first];
      v = a[edge[i].second];
      if (u > v) swap(u, v);
      S.insert(make_pair(u, v));
    }
    res = max(res, (int)S.size());
    return;
  }
  for (int i = 1; i <= 6; ++i) {
    a[x] = i;
    Try(x + 1, depth + 1);

    // Check recursive invariants
    check_recursive_invariant(depth + 1, 6);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;

  vector<pair<int, int>> edges(m);
  for (int i = 1; i <= m; ++i) {
    cin >> edge[i].first >> edge[i].second;
    edges[i - 1] = {edge[i].first, edge[i].second};
  }

  // Check edge invariant
  check_edge_invariant(n, m);

  // Check symmetry invariant
  check_symmetry_invariant(m, edges);

  Try(1, 0);
  cout << res;
  return 0;
}