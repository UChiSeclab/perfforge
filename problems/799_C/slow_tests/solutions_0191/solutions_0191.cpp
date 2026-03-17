#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int n, c, d;
int tree[(N + 10) << 2][2];
vector<int> v[N + 10][2];
void update(int x, int l, int r, int pos, int valu, int idx) {
  if (l == r) {
    if (valu)
      tree[x][idx] = max(tree[x][idx], valu);
    else
      tree[x][idx] = 0;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    update(x << 1, l, mid, pos, valu, idx);
  else
    update(x << 1 | 1, mid + 1, r, pos, valu, idx);
  tree[x][idx] = max(tree[x << 1][idx], tree[x << 1 | 1][idx]);
}
int query(int x, int l, int r, int L, int R, int idx) {
  if (L <= l && r <= R) return tree[x][idx];
  int mid = (l + r) / 2, c = 0;
  if (L <= mid) c = max(c, query(x << 1, l, mid, L, R, idx));
  if (R > mid) c = max(c, query(x << 1 | 1, mid + 1, r, L, R, idx));
  return c;
}
bool cmp(int x, int y) { return x > y; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> c >> d;
  int maxc = 0, maxd = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    int b, p;
    char ch[2];
    cin >> b >> p >> ch;
    if (ch[0] == 'C') {
      v[p][0].push_back(b);
      update(1, 1, N, p, b, 0);
      if (p <= c) maxc = max(maxc, b);
    } else {
      v[p][1].push_back(b);
      update(1, 1, N, p, b, 1);
      if (p <= d) maxd = max(maxd, b);
    }
  }
  for (int i = 1; i <= N; i++) {
    sort(v[i][0].begin(), v[i][0].end(), cmp);
    sort(v[i][1].begin(), v[i][1].end(), cmp);
  }
  if (maxc && maxd) ans = maxc + maxd;
  for (int i = 1; i < c; i++) {
    if (v[i][0].empty()) continue;
    int x = v[i][0][0];
    update(1, 1, N, i, 0, 0);
    if (v[i][0].size() > 1) update(1, 1, N, i, v[i][0][1], 0);
    int y = query(1, 1, N, 1, c - i, 0);
    if (y) ans = max(ans, x + y);
    update(1, 1, N, i, v[i][0][0], 0);
  }
  for (int i = 1; i < d; i++) {
    if (v[i][1].empty()) continue;
    int x = v[i][1][0];
    update(1, 1, N, i, 0, 1);
    if (v[i][1].size() > 1) update(1, 1, N, i, v[i][1][1], 1);
    int y = query(1, 1, N, 1, d - i, 1);
    if (y) ans = max(ans, x + y);
    update(1, 1, N, i, v[i][1][0], 1);
  }
  cout << ans;
  return 0;
}
