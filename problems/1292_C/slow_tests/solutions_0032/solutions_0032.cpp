#include <bits/stdc++.h>
using namespace std;
const int N = 3001;
int n, p[N][N], sz[N][N];
long long dp[N][N];
vector<int> v[N];
vector<pair<int, pair<int, int> > > all;
void dfs(int node, int pnode, int dep, int root) {
  p[root][node] = pnode;
  sz[root][node] = 1;
  if (dep) all.push_back({dep, {root, node}});
  for (auto &i : v[node]) {
    if (i == pnode) continue;
    dfs(i, node, dep + 1, root);
    sz[root][node] += sz[root][i];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, 0, 0, i);
  }
  sort(all.begin(), all.end());
  long long ans = 0;
  for (auto &i : all) {
    int x = i.second.first;
    int y = i.second.second;
    dp[x][y] = sz[x][y] * sz[y][x] + max(dp[p[y][x]][y], dp[p[x][y]][x]);
    ans = max(ans, dp[x][y]);
  }
  cout << ans << endl;
}
