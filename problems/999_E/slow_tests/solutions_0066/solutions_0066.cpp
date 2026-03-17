#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m, c;
vector<int> adj[N], temp, b[N];
bool vis[N], mk[N];
vector<pair<int, int> > v, ans;
void dfs(int nd) {
  vis[nd] = 1;
  for (auto u : adj[nd]) {
    if (!vis[u]) dfs(u);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, c;
  cin >> n >> m >> c;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  dfs(c);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) temp.push_back(i);
  }
  for (auto u : temp) {
    for (int i = 0; i <= n; i++) vis[i] = 0;
    dfs(u);
    mk[u] = 1;
    for (int i = 1; i <= n; i++) {
      if (!vis[i])
        ;
      else
        b[u].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!mk[i]) continue;
    ans.push_back({b[i].size(), i});
  }
  sort(ans.begin(), ans.end(), greater<pair<int, int> >());
  for (int i = 0; i <= n; i++) vis[i] = 0;
  dfs(c);
  int cnt = 0;
  for (auto u : ans) {
    if (vis[u.second]) continue;
    cnt++;
    for (auto nd : b[u.second]) {
      vis[nd] = 1;
    }
  }
  cout << cnt << endl;
  return 0;
}
