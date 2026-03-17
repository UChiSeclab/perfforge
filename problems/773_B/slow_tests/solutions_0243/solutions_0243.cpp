#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[200][10];
int p[10];
struct Node {
  double l, r;
  int w;
} c[10];
struct Point {
  int S, T;
} u[10], v[10];
void Op() {
  c[1].l = -(1e-7);
  c[1].r = 1.00 / 32.00;
  c[1].w = 3000;
  c[2].l = 1.00 / 32.00;
  c[2].r = 1.00 / 16.00;
  c[2].w = 2500;
  c[3].l = 1.00 / 16.00;
  c[3].r = 1.00 / 8.00;
  c[3].w = 2000;
  c[4].l = 1.00 / 8.00;
  c[4].r = 1.00 / 4.00;
  c[4].w = 1500;
  c[5].l = 1.00 / 4.00;
  c[5].r = 1.00 / 2.00;
  c[5].w = 1000;
  c[6].l = 1.00 / 2.00;
  c[6].r = 1.00 / 1.00;
  c[6].w = 500;
}
bool Judge(Point R, int t) {
  double p = (double)R.T / (double)R.S;
  if (p <= c[t].l) return 0;
  if (p > c[t].r) return 0;
  return 1;
}
void Check() {
  int ans1 = 0, ans2 = 0;
  for (int i = 1; i <= 5; i++) {
    if (a[1][i] != -1) ans1 += c[p[i]].w / 250 * (250 - a[1][i]);
    if (a[2][i] != -1) ans2 += c[p[i]].w / 250 * (250 - a[2][i]);
    v[i] = u[i];
  }
  if (ans1 <= ans2) return;
  bool ok = 1;
  for (int i = 1; i <= 5; i++)
    if (!Judge(v[i], p[i])) ok = 0;
  if (ok) {
    ans = 0;
    return;
  }
  for (int i = 1; i <= 5000; i++) {
    for (int j = 1; j <= 5; j++) {
      v[j].S++;
      if ((double)v[j].T / (double)v[j].S <= c[p[j]].l && a[1][j] != -1)
        v[j].T++;
    }
    bool ok = 1;
    for (int j = 1; j <= 5; j++)
      if (!Judge(v[j], p[j])) ok = 0;
    if (ok) {
      ans = min(ans, i);
      return;
    }
  }
}
void Solve(int x) {
  if (x > 5) {
    Check();
    return;
  }
  for (int i = 1; i <= 6; i++) {
    p[x] = i;
    Solve(x + 1);
  }
}
int main() {
  Op();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 5; j++) scanf("%d", &a[i][j]);
  for (int j = 1; j <= 5; j++) {
    u[j].S = u[j].T = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i][j] != -1) u[j].T++;
      u[j].S++;
    }
  }
  ans = 1 << 30;
  Solve(1);
  if (ans == 1 << 30)
    printf("-1\n");
  else
    printf("%d\n", ans);
}
