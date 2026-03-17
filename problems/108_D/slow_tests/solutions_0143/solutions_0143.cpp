#include <bits/stdc++.h>
using namespace std;
int main() {
  double n;
  int m;
  int h;
  cin >> n;
  cin >> m;
  cin >> h;
  double a[m];
  double s = 0;
  n--;
  h--;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    s += a[i];
  }
  a[h]--;
  s--;
  if (s < n) {
    cout << -1.0 << endl;
    return 0;
  }
  if (s == n && a[h] != 0) {
    cout << 1.0 << endl;
    return 0;
  }
  if (a[h] == 0) {
    cout << 0.0 << endl;
    return 0;
  }
  if (s - a[h] < n) {
    cout << 1.0 << endl;
    return 0;
  }
  s = s - a[h];
  double res = 0;
  double r;
  int f = 0;
  while (n) {
    if (f == 0) {
      res = (double)(a[h] / (s + a[h]));
    } else {
      r = (a[h] / ((s - f) + a[h]));
      for (int i = 0; i < f; i++) r *= (s - i) / (s + a[h] - i);
      res += r;
    }
    n--;
    f++;
  }
  cout << res << endl;
  return 0;
}
