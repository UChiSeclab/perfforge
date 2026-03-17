#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
const int N = 2e5 + 10;
int n, m;
struct uzi {
  int x, y;
} p[N], q[N];
int x[N * 20];
pair<int, int> s[N * 20];
int cnt;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
  for (int i = 1; i <= m; i++) cin >> q[i].x >> q[i].y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (q[j].y >= p[i].y && q[j].x >= p[i].x) {
        s[++cnt] = {q[j].y - p[i].y + 1, q[j].x - p[i].x + 1};
      }
    }
  }
  sort(s + 1, s + 1 + cnt);
  for (int i = cnt; i >= 1; i--) x[i] = max(x[i + 1], s[i].second);
  int ans = 1000005, pos = 1;
  for (int i = 0; i <= 1000000 && i < ans; i++) {
    while (pos <= cnt && s[pos].first <= i) pos++;
    ans = min(ans, i + x[pos]);
  }
  cout << ans << '\n';
  return 0;
}
