#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T t) {
  return t < 0 ? -t : t;
}
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
const int MAXN = 3123;
int n, m, k;
int s[MAXN];
long long dp[MAXN][MAXN];
vector<int> adj[MAXN];
vector<int> sz[MAXN];
int dfs(int u, int p) {
  int size = 1;
  ;
  for (int nxt : adj[u]) {
    if (nxt == p) continue;
    size += dfs(nxt, u);
  };
  return size;
}
long long go(int u, int v, int bu, int bv) {
  long long &r = dp[u][v];
  if (r != -1) return r;
  r = 0;
  long long totu = 0, totv = 0;
  for (int i = 0; i < adj[u].size(); i++) {
    int nxt = adj[u][i];
    int tam = sz[u][i];
    if (bu == nxt || v == nxt) continue;
    totu += tam;
  }
  for (int i = 0; i < adj[v].size(); i++) {
    int nxt = adj[v][i];
    int tam = sz[v][i];
    if (bv == nxt || u == nxt) continue;
    totv += tam;
  }
  for (int i = 0; i < adj[u].size(); i++) {
    int nxt = adj[u][i];
    int tam = sz[u][i];
    if (bu == nxt || v == nxt) continue;
    r = max(r, go(nxt, v, u, bv) + ((long long)tam) * (1ll + totv));
  }
  for (int i = 0; i < adj[v].size(); i++) {
    int nxt = adj[v][i];
    int tam = sz[v][i];
    if (bv == nxt || u == nxt) continue;
    r = max(r, go(u, nxt, bu, v) + ((long long)tam) * (1ll + totu));
  }
  return r;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int a = 1; a < n; a++) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  for (int a = 1; a <= n; a++) {
    for (int i = 0; i < adj[a].size(); i++) {
      int nxt = adj[a][i];
      sz[a].push_back(dfs(nxt, a));
    }
  }
  long long ans = 0;
  for (int a = 1; a <= n; a++) {
    long long tot = 0;
    for (int i = 0; i < adj[a].size(); i++) tot += sz[a][i];
    for (int i = 0; i < adj[a].size(); i++) {
      int nxt = adj[a][i];
      ans = max(ans, go(a, nxt, nxt, a) +
                         (1ll + tot - sz[a][i]) * ((long long)sz[a][i]));
    }
  }
  printf("%lld\n", ans);
}
