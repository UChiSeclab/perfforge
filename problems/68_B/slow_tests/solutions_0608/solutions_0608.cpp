#include <bits/stdc++.h>
using namespace std;
int n, k;
int ok(double x, double a[]) {
  double z1 = 0, z2 = 0;
  for (int i = 0; i < n; i++) {
    if (x - a[i] > 0) {
      z1 += x - a[i];
    }
    if (x - a[i] < 0) {
      double ans = 1 - (k * (double)1) / 100;
      z2 += (a[i] - x) * ans;
    }
  }
  if (z1 <= z2) {
    return 1;
  }
  return 0;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  double a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  double ans = 0, low = 0, high = 10000;
  int z = 0;
  while (low < high) {
    z++;
    double mid = (low + high) / 2;
    if (ok(mid, a) == 1) {
      low = mid;
      ans = mid;
    } else {
      high = mid;
    }
    if (z == 999) {
      break;
    }
  }
  cout << setprecision(12) << ans;
}
