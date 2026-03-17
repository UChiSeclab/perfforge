#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
int seg[maxn * 4], dp[maxn];
int n, m, x, y;
vector<pair<int, int> > v[maxn];
void modify(int now, int l, int r, int x, int v) {
  if (l == r) {
    seg[now] = v;
    return;
  }
  int m = (l + r) >> 1;
  if (x <= m)
    modify(now * 2, l, m, x, v);
  else
    modify(now * 2 + 1, m + 1, r, x, v);
  seg[now] = min(seg[now * 2], seg[now * 2 + 1]);
}
int query(int now, int l, int r, int ql, int qr) {
  if (r < ql || l > qr)
    return inf;
  else if (l >= ql && r <= qr)
    return seg[now];
  int m = (l + r) >> 1;
  return min(query(now * 2, l, m, ql, qr),
             query(now * 2 + 1, m + 1, r, ql, qr));
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    for (int j = 0; j <= m; j++)
      v[min(m, x + j)].push_back(make_pair(max(1, x - j), max(0, j - y)));
  }
  for (int i = 1; i <= m; i++) modify(1, 1, m, i, inf);
  for (int i = 1; i <= m; i++) {
    dp[i] = inf;
    for (pair<int, int> j : v[i]) {
      if (j.first == 1)
        dp[i] = min(dp[i], j.second);
      else {
        int tmp = query(1, 1, m, j.first - 1, i - 1);
        if (tmp != inf) dp[i] = min(dp[i], tmp + j.second);
      }
    }
    modify(1, 1, m, i, dp[i]);
  }
  cout << dp[m] << '\n';
}
