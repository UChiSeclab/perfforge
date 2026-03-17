#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} a[2005], c[2005], d[4000010];
bool cmp(node a, node b) {
  if (a.x == b.x) {
    return a.y < b.y;
  }
  return a.x > b.x;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].x, &a[i].y);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &c[i].x, &c[i].y);
  }
  int tot = 0;
  for (int i = 1; i <= m; ++i) {
    int x = c[i].x, y = c[i].y;
    for (int j = 1; j <= n; ++j) {
      int xx = a[j].x, yy = a[j].y;
      if (xx <= x && yy <= y) {
        d[++tot].x = x - xx + 1;
        d[tot].y = y - yy + 1;
      }
    }
  }
  sort(d + 1, d + tot + 1, cmp);
  int ans, w, k = 2, my = d[1].y;
  while (d[k].x == d[1].x) {
    my = max(d[k].y, my);
    ++k;
  }
  w = d[k - 1].x;
  ans = d[k - 1].x;
  for (int i = k; i <= tot; ++i) {
    if (d[i].x != w) {
      w = d[i].x;
      ans = min(ans, d[i].x + my);
    }
    my = max(d[i].y, my);
  }
  ans = min(ans, my);
  printf("%d\n", ans);
  return 0;
}
