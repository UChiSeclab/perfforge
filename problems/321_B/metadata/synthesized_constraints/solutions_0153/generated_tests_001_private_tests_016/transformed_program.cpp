#include <bits/stdc++.h>
using namespace std;

struct MinCostFlow {
  struct Edge {
    int t;
    int f;
    int c;
    Edge *next, *rev;
    Edge(int _t, int _f, int _c, Edge* _next)
        : t(_t), f(_f), c(_c), next(_next) {}
  };
  vector<Edge*> E;
  int addV() {
    E.push_back((Edge*)0);
    return E.size() - 1;
  }
  Edge* makeEdge(int s, int t, int f, int c) {
    return E[s] = new Edge(t, f, c, E[s]);
  }
  void addEdge(int s, int t, int f, int c) {
    Edge *e1 = makeEdge(s, t, f, c), *e2 = makeEdge(t, s, 0, -c);
    e1->rev = e2, e2->rev = e1;
  }
  pair<int, int> minCostFlow(int vs, int vt, bool maxFlow) {
    int n = E.size();
    int flow = 0;
    int cost = 0;
    const int MAX_COST = ~0U >> 1;
    const int MAX_FLOW = ~0U >> 1;
    for (;;) {
      vector<int> dist(n, MAX_COST);
      vector<int> am(n, 0);
      vector<Edge*> prev(n);
      vector<bool> inQ(n, false);
      queue<int> que;
      dist[vs] = 0;
      am[vs] = MAX_FLOW;
      que.push(vs);
      inQ[vs] = true;
      while (!que.empty()) {
        int u = que.front();
        int c = dist[u];
        que.pop();
        inQ[u] = false;
        for (Edge* e = E[u]; e; e = e->next)
          if (e->f > 0) {
            int nc = c + e->c;
            if (nc < dist[e->t]) {
              dist[e->t] = nc;
              prev[e->t] = e;
              am[e->t] = min(am[u], e->f);
              if (!inQ[e->t]) {
                que.push(e->t);
                inQ[e->t] = true;
              }
            }
          }
      }
      if (maxFlow) {
        if (dist[vt] == MAX_COST) break;
      } else {
        if (dist[vt] >= 0) break;
      }
      int by = am[vt];
      int u = vt;
      flow += by;
      cost += by * dist[vt];
      while (u != vs) {
        Edge* e = prev[u];
        e->f -= by;
        e->rev->f += by;
        u = e->rev->t;
      }
    }
    return make_pair(flow, cost);
  }
};

const int MAX_N = 100 + 10;
int n, m;
string how[MAX_N];
int A[MAX_N], B[MAX_N];
int ia[MAX_N], ib[MAX_N];

void check_high_connectivity_invariant(int n, int m) {
    if (n * m > 8000) {
        cerr << "Warning: High graph connectivity triggered - too many potential connections" << endl;
        abort();
    }
}

void check_complex_pathfinding_invariant(int edgeCount) {
    if (edgeCount > 5000) {
        cerr << "Warning: Complex pathfinding triggered - excessive edges in flow graph" << endl;
        abort();
    }
}

void check_dense_edge_expansion_invariant(int edgeAdditions) {
    if (edgeAdditions > 7000) {
        cerr << "Warning: Dense edge expansion triggered - too many edges added" << endl;
        abort();
    }
}

int notKillAll() {
  MinCostFlow net;
  int vs = net.addV(), vt = net.addV();

  // Check for high graph connectivity
  check_high_connectivity_invariant(n, m);

  for (int i = 0; i < n; ++i) {
    ia[i] = net.addV();
    net.addEdge(vs, ia[i], 1, 0);
  }
  for (int i = 0; i < m; ++i) {
    ib[i] = net.addV();
    net.addEdge(ib[i], vt, 1, 0);
  }
  int edgeAdditions = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (B[j] > A[i] && how[i] == "ATK") {
        net.addEdge(ia[i], ib[j], 1, -(B[j] - A[i]));
        edgeAdditions++;
      }
    }
  }

  // Check for dense edge expansion
  check_dense_edge_expansion_invariant(edgeAdditions);

  return -net.minCostFlow(vs, vt, false).second;
}

int killAll() {
  MinCostFlow net;
  int vs = net.addV(), vt = net.addV();

  for (int i = 0; i < m; ++i) {
    ia[i] = net.addV();
    net.addEdge(vs, ia[i], 1, 0);
  }
  for (int i = 0; i < m; ++i) {
    ib[i] = net.addV();
    net.addEdge(ib[i], vt, 1, 0);
  }
  int edgeAdditions = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i < n) {
        if (how[i] == "ATK") {
          if (B[j] >= A[i]) net.addEdge(ia[i], ib[j], 1, -(B[j] - A[i]));
          edgeAdditions++;
        } else {
          if (B[j] > A[i]) net.addEdge(ia[i], ib[j], 1, 0);
        }
      } else {
        net.addEdge(ia[i], ib[j], 1, -B[j]);
        edgeAdditions++;
      }
    }
  }

  // Check for dense edge expansion
  check_dense_edge_expansion_invariant(edgeAdditions);

  pair<int, int> ret = net.minCostFlow(vs, vt, true);

  // Check for complex pathfinding
  check_complex_pathfinding_invariant(edgeAdditions);

  if (ret.first == m) return -ret.second;
  return 0;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> how[i] >> A[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> B[i];
  }
  int ans = notKillAll();
  if (m > n) ans = max(ans, killAll());
  cout << ans << endl;
  return 0;
}