#include <bits/stdc++.h>
using namespace std;
const int N = (2 << 18);
const long long INF = 2e18;
long long seg[N << 2];
void build(int rt, int l, int r) {
  seg[rt] = INF;
  if (l == r) {
    return;
  }
  int mid = l + r >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
}
void update(int rt, int l, int r, int x, long long w) {
  if (l == r) {
    seg[rt] = w;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    update(rt << 1, l, mid, x, w);
  else
    update(rt << 1 | 1, mid + 1, r, x, w);
  seg[rt] = min(seg[rt << 1 | 1], seg[rt << 1]);
}
long long query(int rt, int l, int r, int x, int y) {
  if (x <= l && y >= r) {
    return seg[rt];
  }
  int mid = l + r >> 1;
  long long res = INF;
  if (x <= mid) res = min(res, query(rt << 1, l, mid, x, y));
  if (y > mid) res = min(res, query(rt << 1 | 1, mid + 1, r, x, y));
  return res;
}
long long a[N], dp[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  int cnt = 0, m = n;
  while (m) {
    m >>= 1;
    cnt++;
  }
  build(1, 1, n);
  dp[n] = a[n];
  if (a[n] == -1) {
    printf("0\n");
    return 0;
  }
  update(1, 1, n, n, dp[n]);
  long long ans = -1;
  cnt--;
  m = 1;
  for (int i = 1; i <= cnt; i++) {
    if (ans != -1) break;
    for (int j = (1 << (cnt - i)); j <= n; j++) {
      if (j > n - i) {
        dp[j] = INF;
        update(1, 1, n, j, dp[j]);
        continue;
      }
      long long res = query(1, 1, n, j + 1, n);
      dp[j] = res + a[j];
      if (a[j] == -1) {
        ans = res;
        break;
      }
      update(1, 1, n, j, dp[j]);
    }
    m++;
  }
  printf("%lld\n", ans);
  return 0;
}
