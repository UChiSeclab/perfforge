#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
struct MCF {
  int n;
  vector<long long> prio, curflow, prevedge, prevnode, pot;
  priority_queue<long long, vector<long long>, greater<long long>> q;
  struct edge {
    int to, rev;
    long long f, cap, cost;
  };
  vector<vector<edge>> g;
  MCF(int n)
      : n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n) {}
  void add_edge(int s, int t, long long cap, long long cost) {
    g[s].push_back((edge){t, int(g[t].size()), 0, cap, cost});
    g[t].push_back((edge){s, int(g[s].size()) - 1, 0, 0, -cost});
  }
  pair<long long, long long> get_flow(int s, int t) {
    long long flow = 0, flowcost = 0;
    while (1) {
      q.push(s);
      fill(prio.begin(), prio.end(), INF);
      prio[s] = 0;
      curflow[s] = INF;
      while (!q.empty()) {
        long long cur = q.top();
        int d = cur >> 32, u = cur;
        q.pop();
        if (d != prio[u]) continue;
        for (int i = 0; i < int(g[u].size()); ++i) {
          edge &e = g[u][i];
          int v = e.to;
          if (e.cap <= e.f) continue;
          long long nprio = prio[u] + e.cost + pot[u] - pot[v];
          if (prio[v] > nprio) {
            prio[v] = nprio;
            q.push(((long long)nprio << 32) + v);
            prevnode[v] = u;
            prevedge[v] = i;
            curflow[v] = min(curflow[u], e.cap - e.f);
          }
        }
      }
      if (prio[t] == INF) break;
      for (int i = 0, ThxDem = n; i < ThxDem; ++i) pot[i] += prio[i];
      long long df = min(curflow[t], INF - flow);
      flow += df;
      for (int v = t; v != s; v = prevnode[v]) {
        edge &e = g[prevnode[v]][prevedge[v]];
        e.f += df;
        g[v][e.rev].f -= df;
        flowcost += df * e.cost;
      }
    }
    return {flow, flowcost};
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> he;
  vector<int> v(m);
  for (int i = 0, ThxDem = n; i < ThxDem; ++i) {
    string s;
    int x;
    cin >> s >> x;
    he.push_back({x, s == "ATK"});
  }
  for (int i = 0, ThxDem = m; i < ThxDem; ++i) cin >> v[i];
  long long ans = 0;
  for (int x = 1, ThxDem = m + 1; x < ThxDem; ++x) {
    MCF nt(m + n + 3);
    int s = m + n, t = s + 1, wh = t + 1;
    for (int i = 0, ThxDem = m; i < ThxDem; ++i)
      for (int j = 0, ThxDem = n; j < ThxDem; ++j) {
        if (v[i] >= he[j].first && he[j].second)
          nt.add_edge(i, m + j, 1, -(v[i] - he[j].first));
      }
    nt.add_edge(s, wh, x, 0);
    for (int i = 0, ThxDem = m; i < ThxDem; ++i) nt.add_edge(wh, i, 1, 0);
    for (int i = 0, ThxDem = n; i < ThxDem; ++i) nt.add_edge(m + i, t, 1, 0);
    ans = max(ans, -nt.get_flow(s, t).second);
  }
  if (m >= n) {
    MCF nt(n + m + 3);
    int s = m + n, t = s + 1, wh = t + 1;
    for (int i = 0, ThxDem = m; i < ThxDem; ++i) nt.add_edge(s, i, 1, 0);
    for (int i = 0, ThxDem = n; i < ThxDem; ++i) nt.add_edge(m + i, t, 1, 0);
    nt.add_edge(wh, t, m - n, 0);
    for (int i = 0, ThxDem = m; i < ThxDem; ++i) {
      for (int j = 0, ThxDem = n; j < ThxDem; ++j) {
        if (v[i] >= he[j].first && he[j].second)
          nt.add_edge(i, m + j, 1, -(v[i] - he[j].first));
        if (v[i] > he[j].first && !he[j].second) nt.add_edge(i, m + j, 1, 0);
      }
      nt.add_edge(i, wh, 1, -v[i]);
    }
    auto g = nt.get_flow(s, t);
    if (g.first == m) ans = max(ans, -g.second);
  }
  cout << ans << "\n";
}
