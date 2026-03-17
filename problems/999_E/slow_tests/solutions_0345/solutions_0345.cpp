#include <bits/stdc++.h>
using namespace std;
int V, E, g[5003][5003];
int cnt, Stack[5003], top;
char vis[5003], ins[5003], ans[5003];
int dfn[5003], low[5003];
int uf[5003];
int used[5003];
struct Edge {
  int u, v;
  Edge(void) {}
  Edge(int uu, int vv) : u(uu), v(vv) {}
} Es[5003];
int find(int x) {
  if (uf[x] >= 0) return uf[x] = find(uf[x]);
  return x;
}
void merge(int x, int y) {
  int r1 = find(x);
  int r2 = find(y);
  if (r1 < r2) {
    uf[r1] += uf[r2];
    uf[r2] = r1;
  } else if (r2 < r1) {
    uf[r2] += uf[r1];
    uf[r1] = r2;
  }
}
void Tarjian(int u) {
  vis[u] = ins[u] = 1;
  dfn[u] = low[u] = ++cnt;
  Stack[top++] = u;
  for (int v = 1; v <= V; ++v) {
    if (g[u][v]) {
      if (!vis[v]) {
        Tarjian(v);
        if (low[u] > low[v]) low[u] = low[v];
      } else if (ins[v]) {
        if (low[u] > dfn[v]) low[u] = dfn[v];
      }
    }
  }
  if (dfn[u] == low[u]) {
    int now, sum = 0;
    while (1) {
      now = Stack[--top];
      ins[now] = 0;
      if (now == u) break;
      merge(now, u);
    }
  }
}
int main() {
  int u, v, e, ccnt = 0, tp, src;
  memset(uf, -1, sizeof(uf));
  scanf("%d %d %d", &V, &E, &src);
  for (e = 0; e < E; ++e) {
    scanf("%d %d", &u, &v);
    g[u][v] = 1;
    Es[e] = Edge(u, v);
  }
  for (u = 1; u <= V; ++u)
    if (!vis[u]) Tarjian(u);
  for (u = 1; u <= V; ++u) tp = find(u), used[tp] = tp;
  for (e = 0; e < E; ++e) {
    tp = find(Es[e].v);
    if (find(Es[e].u) != tp) ans[tp] = 1;
  }
  ans[0] = 1;
  for (u = 1; u <= V; ++u)
    if (!ans[used[u]]) ccnt++;
  if (!ans[find(src)]) ccnt--;
  printf("%d\n", ccnt);
}
