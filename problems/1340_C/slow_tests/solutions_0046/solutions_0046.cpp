#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, d[N], g, r, dd[N][1005];
long long f[N][1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    h;
void add(int i, int j, int val) {
  if (f[i][j] > val) {
    f[i][j] = val;
    if (!dd[i][j]) {
      dd[i][j] = 1;
      h.push(make_pair(i, j));
    }
  }
}
void dijkstra() {
  f[1][0] = 0;
  dd[0][1] = 1;
  h.push(make_pair(1, 0));
  while (h.size()) {
    int u, i;
    tie(u, i) = h.top();
    h.pop();
    long long w = f[u][i];
    dd[u][i] = 0;
    if (i == g) add(u, 0, r + w);
    if (u > 1) {
      int j = i + d[u] - d[u - 1];
      if (j <= g) add(u - 1, j, w + d[u] - d[u - 1]);
    }
    if (u < m) {
      int j = i + d[u + 1] - d[u];
      if (j <= g) add(u + 1, j, w + d[u + 1] - d[u]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> d[i];
  cin >> g >> r;
  sort(d + 1, d + m + 1);
  memset(f, 127, sizeof(f));
  dijkstra();
  long long ans = f[0][0];
  for (int i = 0; i <= 1000; ++i) ans = min(ans, f[m][i]);
  if (ans >= f[0][0]) ans = -1;
  cout << ans;
}
