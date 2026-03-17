#include <bits/stdc++.h>
using namespace std;
struct CostFlow {
  static const int MXN = 205;
  static const long long INF = 102938475610293847LL;
  struct Edge {
    int v, r;
    long long f, c;
  };
  int n, s, t, prv[MXN], prvL[MXN], inq[MXN];
  long long dis[MXN], fl, cost;
  vector<Edge> E[MXN];
  void init(int _n, int _s, int _t) {
    n = _n;
    s = _s;
    t = _t;
    for (int i = 0; i < n; i++) E[i].clear();
    fl = cost = 0;
  }
  void AddEdge(int u, int v, long long f, long long c) {
    E[u].push_back({v, (int)E[v].size(), f, c});
    E[v].push_back({u, (int)E[u].size() - 1, 0, -c});
  }
  pair<long long, long long> flow() {
    while (true) {
      for (int i = 0; i < n; i++) {
        dis[i] = INF, inq[i] = 0;
      }
      dis[s] = 0;
      queue<int> q({s});
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = 0; i < E[u].size(); i++) {
          int v = E[u][i].v;
          long long w = E[u][i].c;
          if (E[u][i].f > 0 && dis[v] > dis[u] + w) {
            prv[v] = u;
            prvL[v] = i;
            dis[v] = dis[u] + w;
            if (!inq[v]) {
              inq[v] = 1;
              q.push(v);
            }
          }
        }
      }
      if (dis[t] == INF) break;
      long long tf = INF;
      for (int v = t, u, l; v != s; v = u) {
        u = prv[v];
        l = prvL[v];
        tf = min(tf, E[u][l].f);
      }
      for (int v = t, u, l; v != s; v = u) {
        u = prv[v];
        l = prvL[v];
        E[u][l].f -= tf;
        E[v][E[u][l].r].f += tf;
      }
      cost += tf * dis[t];
      fl += tf;
    }
    return {fl, cost};
  }
};
const int N = 105;
int n, m;
string str[N];
int jiro[N], ciel[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> str[i] >> jiro[i];
  for (int i = 1; i <= m; i++) cin >> ciel[i];
  long long ans = 0;
  CostFlow flow1;
  flow1.init(n + m + 2, 0, n + m + 1);
  for (int i = 1; i <= m; i++) flow1.AddEdge(0, i, 1, 0);
  for (int i = 1; i <= n; i++) flow1.AddEdge(m + i, n + m + 1, 1, 0);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (str[j] == "ATK") {
        if (ciel[i] >= jiro[j])
          flow1.AddEdge(i, m + j, 1, -(ciel[i] - jiro[j]));
        else
          flow1.AddEdge(i, m + j, 1, 0);
      }
    }
  }
  pair<long long, long long> p = flow1.flow();
  ans = max(ans, -p.second);
  if (m > n) {
    CostFlow flow2;
    flow2.init(m + m + 2, 0, m + m + 1);
    for (int i = 1; i <= m; i++) flow2.AddEdge(0, i, 1, 0);
    for (int i = 1; i <= m; i++) flow2.AddEdge(m + i, m + m + 1, 1, 0);
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (str[j] == "ATK" and ciel[i] >= jiro[j])
          flow2.AddEdge(i, m + j, 1, -(ciel[i] - jiro[j]));
        if (str[j] == "DEF" and ciel[i] > jiro[j])
          flow2.AddEdge(i, m + j, 1, 0);
      }
      for (int j = n + 1; j <= m; j++) {
        flow2.AddEdge(i, m + j, 1, -ciel[i]);
      }
    }
    pair<long long, long long> p = flow2.flow();
    if (p.first == m) ans = max(ans, -p.second);
  }
  cout << ans << "\n";
}
