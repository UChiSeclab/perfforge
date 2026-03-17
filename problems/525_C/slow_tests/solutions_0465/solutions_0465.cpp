#include <bits/stdc++.h>
int a[1000002] = {0};
int main() {
  int m, n;
  int mm, nn;
  long long int w, ww, x, xx, y, yy, z, zz;
  scanf("%d", &nn);
  mm = 0;
  y = 0;
  while (mm < nn) {
    scanf("%lld", &x);
    if (x > y) {
      y = x;
    }
    a[x - 1]++;
    mm++;
  }
  z = 0;
  w = 0;
  ww = 0;
  xx = y;
  while (xx >= 0) {
    if (w != 0 && ww != 0) {
      z = z + w * ww;
      w = 0;
      ww = 0;
    }
    if (a[xx] >= 2) {
      if (w == 0) {
        w = xx + 1;
        a[xx] = a[xx] - 2;
      } else if (ww == 0) {
        ww = xx + 1;
        a[xx] = a[xx] - 2;
      }
      continue;
    } else if (a[xx] == 1 && a[xx - 1] >= 1) {
      if (w == 0) {
        w = xx;
      } else if (ww == 0) {
        ww = xx;
      }
      a[xx] = a[xx] - 1;
      a[xx - 1] = a[xx - 1] - 1;
    }
    xx--;
  }
  printf("%lld\n", z);
  return 0;
}
