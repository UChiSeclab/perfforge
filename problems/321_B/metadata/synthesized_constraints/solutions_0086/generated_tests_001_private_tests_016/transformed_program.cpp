#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
const int INF = (int)(1e9);
struct Edge {
  int u, v, cap, flow, cost;
  Edge() {}
  Edge(int _u, int _v, int _cap, int _flow, int _cost) {
    u = _u, v = _v, cap = _cap, flow = _flow, cost = _cost;
  }
};
struct MCMF {
  int n;
  vector<Edge> eg;
  vector<int> G[N];
  int inq[N], d[N], p[N], a[N];
  void init() {
    for (int i = 0; i < N; ++i) G[i].clear();
    eg.clear();
  }
  void addedge(int u, int v, int cap, int cost) {
    eg.push_back(Edge(u, v, cap, 0, cost));
    eg.push_back(Edge(v, u, 0, 0, -cost));
    int m = eg.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
  }
  bool BellmanFord(int s, int t, int &flow, int &cost) {
    for (int i = 0; i < N; ++i) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0;
    inq[s] = 1;
    p[s] = 0;
    a[s] = INF;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      inq[u] = 0;
      for (int i = 0; i < G[u].size(); ++i) {
        Edge &e = eg[G[u][i]];
        if (e.cap > e.flow && d[e.v] > d[u] + e.cost) {
          d[e.v] = d[u] + e.cost;
          p[e.v] = G[u][i];
          a[e.v] = min(a[u], e.cap - e.flow);
          if (!inq[e.v]) {
            Q.push(e.v);
            inq[e.v] = 1;
          }
        }
      }
    }
    if (d[t] == INF) return false;
    flow += a[t];
    cost += d[t] * a[t];
    int u = t;
    while (u != s) {
      eg[p[u]].flow += a[t];
      eg[p[u] ^ 1].flow -= a[t];
      u = eg[p[u]].u;
    }
    return true;
  }
  int flow, cost;
  int Mincost(int s, int t, int v) {
    flow = 0, cost = 0;
    while (BellmanFord(s, t, flow, cost))
      ;
    if (flow < v) cost = 0;
    return cost;
  }
} sol;
int n, m;
int sta[N], stb[N];
bool ak[N];
vector<int> a, b;

void check_graph_density_invariant(int n, int m) {
    int edgeCount = (n + m) * m; // Maximum potential edges, considering attacks and defenses
    if (edgeCount > 10000) { // Hypothetical threshold for high density
        cerr << "Warning: Performance bottleneck condition triggered due to high graph density!" << endl;
        abort();
    }
}

void check_edge_processing_invariant(int nodeCount, int edgeCount) {
    if (nodeCount > 150 && edgeCount > 3000) { // Hypothetical thresholds for excessive edge processing
        cerr << "Warning: Performance bottleneck condition triggered due to excessive edge processing!" << endl;
        abort();
    }
}

void check_flow_adjustment_invariant(const vector<int>& cielStrengths, const vector<int>& jiroStrengths) {
    int closeStrengthPairs = 0;
    for (int cs : cielStrengths) {
        for (int js : jiroStrengths) {
            if (abs(cs - js) < 50) { // Threshold for close strength values
                closeStrengthPairs++;
            }
        }
    }
    if (closeStrengthPairs > 500) { // Hypothetical threshold for flow adjustments
        cerr << "Warning: Performance bottleneck condition triggered due to frequent flow adjustments!" << endl;
        abort();
    }
}

void work() {
  int ans = 0;
  for (int i = 0; i < m; ++i) a.push_back(sta[i]);
  for (int j = 0; j < n; ++j)
    if (ak[j]) b.push_back(stb[j]);
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end());
  
  // Check graph density invariant before processing
  check_graph_density_invariant(n, m);

  int idx = 0;
  for (int i = 0; i < a.size(); ++i) {
    while (idx < b.size()) {
      if (a[i] >= b[idx]) {
        ans += a[i] - b[idx];
        ++idx;
        break;
      }
      ++idx;
    }
  }
  int s, t;
  
  // Check edge processing invariant before graph operations
  check_edge_processing_invariant(n + m, (n + m) * m);

  if (m >= n) {
    sol.init();
    s = 0;
    t = m + m + 1;
    while (n < m) {
      ak[n] = true;
      stb[n] = 0;
      n++;
    }
    for (int i = 1; i <= m; ++i) {
      sol.addedge(s, i, 1, 0);
      sol.addedge(i + m, t, 1, 0);
    }
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (ak[j] && sta[i] >= stb[j]) {
          sol.addedge(i + 1, j + 1 + m, 1, stb[j] - sta[i]);
        } else if (!ak[j] && sta[i] > stb[j]) {
          sol.addedge(i + 1, j + 1 + m, 1, 0);
        }
      }
    
    // Check flow adjustment invariant before final flow calculations
    check_flow_adjustment_invariant(a, b);

    int get = -sol.Mincost(s, t, m);
    if (get > ans) ans = get;
  }
  printf("%d\n", ans);
}

int main() {
  char s[10];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d", s, &stb[i]);
    if (*s == 'A')
      ak[i] = true;
    else
      ak[i] = false;
  }
  for (int i = 0; i < m; ++i) scanf("%d", &sta[i]);
  work();
  return 0;
}