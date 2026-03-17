#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 1e9;
int n, m, dis[N], vis[N], ans;
vector<set<int> > g;
set<int> e;
set<pair<int, int> > q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].insert(v);
    g[v].insert(u);
  }
  for (int i = 0; i < n; i++) {
    dis[i] = INF;
    e.insert(i);
  }
  dis[0] = 0;
  q.insert({0, 0});
  e.erase(0);
  while (!q.empty()) {
    int w = (*q.begin()).first;
    int u = (*q.begin()).second;
    q.erase(q.begin());
    if (vis[u] == 1) {
      continue;
    }
    vis[u] = 1;
    e.erase(u);
    ans += w;
    set<int> t = e;
    for (auto x : t) {
      if (g[u].find(x) == g[u].end()) {
        e.erase(x);
        q.insert({0, x});
      }
    }
    for (auto v : g[u]) {
      if (!vis[v] && e.find(v) != e.end()) {
        q.insert({1, v});
      }
    }
  }
  cout << ans << "\n";
}
