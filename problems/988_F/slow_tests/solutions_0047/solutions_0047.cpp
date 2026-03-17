#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const int maxn = 2 * 1e3 + 5;
int a, n, m;
bool rain[maxn];
int um[maxn];
int f[maxn][maxn];
int Main() {
  cin >> a >> n >> m;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    for (int k = l; k < r; ++k) {
      rain[k] = true;
    }
  }
  for (int i = 0; i <= a; ++i) {
    um[i] = inf;
    for (int j = 0; j <= a; ++j) f[i][j] = inf;
  }
  for (int i = 0; i < m; ++i) {
    pair<int, int> u;
    cin >> u.first >> u.second;
    if (u.first < a) um[u.first] = min(um[u.first], u.second);
  }
  f[0][a] = 0;
  for (int position = 0; position < a; ++position) {
    for (int i = 0; i <= a; ++i) {
      if (f[position][i] == inf) continue;
      if (rain[position]) {
        if (i != a)
          f[position + 1][i] = min(f[position + 1][i], f[position][i] + um[i]);
        if (um[position] != inf)
          f[position + 1][position] =
              min(f[position + 1][position], f[position][i] + um[position]);
      } else {
        f[position + 1][i] = min(f[position + 1][i], f[position][i] + um[i]);
        if (um[position] != inf)
          f[position + 1][position] =
              min(f[position + 1][position], f[position][i] + um[position]);
        f[position + 1][a] = min(f[position + 1][a], f[position][i]);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i <= a; ++i) {
    ans = min(f[a][i], ans);
  }
  if (ans == inf)
    cout << "-1" << endl;
  else
    cout << ans << endl;
  return 0;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  Main();
  return 0;
}
