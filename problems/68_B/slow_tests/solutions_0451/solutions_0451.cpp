#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
double a[10111], k;
int n;
bool pos(double x) {
  double s = 0.0;
  for (int i = 0; i < n; i++) {
    if (a[i] > x) {
      s -= (a[i] - x) * (100 - k) * 0.01;
    } else
      s += (x - a[i]);
  }
  if (s < 0)
    return true;
  else
    return false;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int cnt = 5000;
  double lo = 0, hi = 1000.0, mid;
  while (cnt--) {
    mid = (lo + hi) / 2.0;
    if (pos(mid))
      lo = mid;
    else
      hi = mid;
  }
  printf("%.10f\n", hi);
  return 0;
}
