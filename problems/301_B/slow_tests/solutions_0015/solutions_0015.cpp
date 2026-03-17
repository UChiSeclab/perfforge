#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(1e9);
const int DI[] = {0, 1, 0, -1};
const int DJ[] = {1, 0, -1, 0};
const int N_MAX = 100;
const int X_MAX = 100;
const int Y_MAX = 100;
int n, d;
int a[N_MAX - 2];
int x[N_MAX];
int y[N_MAX];
int dp[2 * Y_MAX + 1][2 * X_MAX + 1];
void solve() {
  for (int i = 0; i < (n); ++i) x[i] += X_MAX;
  for (int i = 0; i < (n); ++i) y[i] += Y_MAX;
  fill(dp[0], dp[0] + (2 * Y_MAX + 1) * (2 * X_MAX + 1), INF);
  queue<pair<int, int> > q;
  q.push(pair<int, int>(x[0], y[0]));
  dp[y[0]][x[0]] = 0;
  while (!q.empty()) {
    pair<int, int> e = q.front();
    q.pop();
    int j = e.first;
    int i = e.second;
    int t = 0;
    for (int k = 0; k < (n - 2); ++k)
      if (x[k + 1] == j && y[k + 1] == i) t = a[k];
    for (int k = 0; k < 4; ++k) {
      int u = j + DJ[k];
      int v = i + DI[k];
      if (u < 0 || u > 2 * X_MAX || v < 0 || v > 2 * Y_MAX) continue;
      if (dp[i][j] + d - t < dp[v][u]) {
        dp[v][u] = dp[i][j] + d - t;
        q.push(pair<int, int>(u, v));
      }
    }
  }
  int ans = dp[y[n - 1]][x[n - 1]];
  cout << ans << endl;
}
int main() {
  cin >> n >> d;
  for (int i = 0; i < (n - 2); ++i) cin >> a[i];
  for (int i = 0; i < (n); ++i) cin >> x[i] >> y[i];
  solve();
  return 0;
}
