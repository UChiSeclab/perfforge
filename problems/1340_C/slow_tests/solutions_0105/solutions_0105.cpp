#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 1e6 + 1, M = 1e4 + 1, G = 1e3 + 1, inf = 1e9 + 1;
int n, m, g, r;
int d[M];
bool used[M][G];
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) cin >> d[i];
  sort(d, d + m);
  cin >> g >> r;
  deque<pair<int, int>> q;
  used[0][0] = true;
  q.emplace_front(0, 0);
  q.emplace_back(-1, -1);
  bool found = false;
  int rw = 0;
  while (rw < M) {
    int w = q.front().first, v = q.front().second;
    q.pop_front();
    if (w == -1) {
      if (found) break;
      ++rw;
      q.emplace_back(-1, -1);
      continue;
    }
    if (w == g) {
      used[v][0];
      q.emplace_back(0, v);
      continue;
    }
    if (v != 0) {
      int new_w = w + d[v] - d[v - 1];
      if (new_w <= g && !used[v - 1][new_w]) {
        used[v - 1][new_w] = true;
        q.emplace_front(new_w, v - 1);
      }
    }
    if (v != m - 1) {
      int new_w = w + d[v + 1] - d[v];
      if (new_w <= g && !used[v + 1][new_w]) {
        used[v + 1][new_w] = true;
        if (v + 1 == m - 1) found = true;
        q.emplace_front(new_w, v + 1);
      }
    }
  }
  if (rw == M) {
    cout << "-1\n";
    return 0;
  }
  int ans = inf;
  for (int i = 0; i <= g; ++i)
    if (used[m - 1][i]) ans = min(ans, rw * (r + g) + i);
  cout << ans << '\n';
}
