#include <bits/stdc++.h>
using namespace std;
int n, root;
vector<vector<int>> tree, par, sub;
vector<vector<long long>> dp;
void dfs(int u) {
  sub[root][u] = 1;
  for (int v : tree[u]) {
    if (v == par[root][u]) continue;
    par[root][v] = u;
    dfs(v);
    sub[root][u] += sub[root][v];
  }
}
long long getDP(int u, int v) {
  if (u == v) return 0;
  if (dp[u][v] != -1) return dp[u][v];
  long long res =
      sub[u][v] * sub[v][u] + max(getDP(par[v][u], v), getDP(u, par[u][v]));
  return dp[u][v] = res;
}
void input() {
  scanf("%d", &n);
  tree.assign(n, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
}
void solve() {
  par.assign(n, vector<int>(n, -1));
  sub.assign(n, vector<int>(n, -1));
  for (int u = 0; u < n; ++u) {
    root = u;
    dfs(u);
  }
  dp.assign(n, vector<long long>(n, -1LL));
  long long ans = 0;
  for (int u = 0; u < n; ++u)
    for (int v = 0; v < n; ++v) ans = max(ans, getDP(u, v));
  cout << ans << endl;
}
int main() {
  input();
  solve();
  return 0;
}
