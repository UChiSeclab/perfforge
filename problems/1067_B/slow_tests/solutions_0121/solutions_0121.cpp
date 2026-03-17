#include <bits/stdc++.h>
using namespace std;
bool is_khog(vector<int> vertices, vector<vector<int>> edges, int K);
int main() {
  int N, K;
  cin >> N >> K;
  int ms = 4;
  for (int i = 2; i <= K; ++i) {
    ms *= 3;
    if (ms > N) {
      cout << "No" << endl;
      return 0;
    }
  }
  vector<int> vertices;
  for (int i = 1; i <= N; ++i) {
    vertices.push_back(i);
  }
  vector<vector<int>> E(N + 1);
  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  if (is_khog(vertices, E, K)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
bool is_khog(vector<int> vertices, vector<vector<int>> edges, int K) {
  map<int, int> deg;
  vector<int> rem;
  for (auto &v : vertices) {
    if (edges[v].size() == 1) {
      int u = edges[v][0];
      deg[u]++;
    } else {
      rem.push_back(v);
    }
  }
  for (auto &v : deg) {
    if (v.second < 3) {
      return false;
    }
  }
  if (K == 1) {
    return (deg.size() == 1);
  }
  for (auto &v : deg) {
    vector<int> &adj = edges[v.first];
    bool f = false;
    while (adj.size() > 1) {
      int u = adj.back();
      if (edges[u].size() > 1) {
        if (f) {
          return false;
        }
        f = true;
        swap(adj[adj.size() - 1], adj[0]);
      } else {
        adj.pop_back();
      }
    }
  }
  return is_khog(rem, edges, K - 1);
}
