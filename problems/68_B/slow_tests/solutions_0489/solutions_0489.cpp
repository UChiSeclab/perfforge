#include <bits/stdc++.h>
using namespace std;
int n, k, a[10001];
double f;
bool can(double x) {
  int L = 0, R = n - 1;
  double surplus = 0;
  while (L <= R) {
    double deficit = x - a[L++];
    if (deficit < 1e-9) return true;
    if (surplus > 0) {
      double transfer = min(surplus, deficit / f);
      deficit -= transfer * f;
      surplus -= transfer;
    }
    if (deficit < 1e-9) continue;
    while (L <= R) {
      surplus += a[R--] - x;
      if (surplus < 0) return false;
      double transfer = min(surplus, deficit / f);
      deficit -= transfer * f;
      surplus -= transfer;
      if (deficit < 1e-9) break;
    }
    if (deficit > 1e-9) return false;
  }
  return surplus >= -1e-9;
}
int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    for (int i = 0, _n = n; i < _n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    f = 1.0 - k / 100.0;
    double lo = 0, hi = 1e9;
    for (int i = 0, _n = 1000; i < _n; i++) {
      double mid = (lo + hi) / 2.0;
      if (can(mid))
        lo = mid;
      else
        hi = mid;
    }
    printf("%.12lf\n", (lo + hi) / 2.0);
  }
}
