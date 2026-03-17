#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;
const int N = 100000 + 5;
int n, m;
int par[N];
vector<pair<int, pair<int, int> > > e;
map<int, int> M[N];
int finds(int u) { return par[u] <= 0 ? u : finds(par[u]); }
bool job(int u, int v) {
  u = finds(u);
  v = finds(v);
  if (u == v) return false;
  if (par[u] > par[v]) swap(u, v);
  par[u] += par[v];
  par[v] = u;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int u, v;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    M[u][v] = 1;
    M[v][u] = 1;
    e.push_back(make_pair(1, make_pair(u, v)));
  }
  for (int i = 1; i <= n; i++) {
    int d = 15;
    for (int j = i + 1; j <= n && d; j++) {
      if (M[i][j]) continue;
      M[i][j] = 1;
      M[j][i] = 1;
      d -= 1;
      e.push_back(make_pair(0, make_pair(i, j)));
    }
  }
  sort(e.begin(), e.end());
  for (int i = 1; i <= n; i++) par[i] = -1;
  int res = 0;
  for (int i = 0; i < e.size(); i++) {
    if (job(e[i].second.first, e[i].second.second)) res += e[i].first;
  }
  cout << res;
}
