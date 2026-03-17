#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
int x[2][10], y[2][10], mxx1 = -111, mxy1 = -111, mnx1 = 111, mny1 = 111;
double dis(double x1, double y1, double x2, double y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
int main() {
  for (int i = 1; i <= 4; i++) scanf("%d %d", &x[0][i], &y[0][i]);
  for (int i = 1; i <= 4; i++) scanf("%d %d", &x[1][i], &y[1][i]);
  double midx = (x[1][1] + x[1][3]) / 2.0, midy = (y[1][1] + y[1][3]) / 2.0;
  for (int i = 1; i <= 4; i++) {
    mxx1 = max(mxx1, x[0][i]);
    mxy1 = max(mxy1, y[0][i]);
    mnx1 = min(mnx1, x[0][i]);
    mny1 = min(mny1, y[0][i]);
  }
  int mxx = -111, mxy = -111, mnx = 111, mny = 111;
  for (int i = 1; i <= 4; i++) {
    mxx = max(mxx, x[1][i]);
    mxy = max(mxy, y[1][i]);
    mnx = min(mnx, x[1][i]);
    mny = min(mny, y[1][i]);
  }
  for (double xx = -100; xx <= 100; xx += 0.1)
    for (double yy = -100; yy <= 100; yy += 0.1) {
      double d = dis(xx, yy, midx, midy);
      bool f1 = false, f2 = false;
      if (d < dis(xx, yy, mxx, mxy) + eps && d < dis(xx, yy, mxx, mny) + eps &&
          d < dis(xx, yy, mnx, mxy) + eps && d < dis(xx, yy, mnx, mny) + eps)
        f2 = true;
      if (xx < mxx1 + eps && xx > mnx1 - eps && yy < mxy1 + eps &&
          yy > mny1 - eps)
        f1 = true;
      if (f1 && f2) return puts("YES"), 0;
    }
  puts("NO");
  return 0;
}
