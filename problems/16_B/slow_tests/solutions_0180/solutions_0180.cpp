#include <bits/stdc++.h>
using namespace std;
int main() {
  long int p, a[20][2];
  int n, m, i, j, k, l, t, u, pos, s = 0;
  cin >> p >> n;
  for (i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  for (i = 0; i < n - 1; i++) {
    t = a[i][1];
    for (j = i + 1; j < n; j++) {
      if (t < a[j][1]) {
        t = a[j][1];
        u = a[j][0];
        pos = j;
      }
      l = a[i][1];
      m = a[i][0];
      if (t != l) {
        a[i][1] = t;
        a[i][0] = u;
        a[pos][1] = l;
        a[pos][0] = m;
      }
    }
  }
  for (i = 0; i < n; i++) l = 1;
  m = 0;
  k = 0;
  for (i = 0; i < n; i++) {
    for (j = 1; j <= a[i][0]; j++) {
      m += a[i][1] * l;
      s += l;
      if (s == p) {
        k++;
        break;
      }
    }
    if (k > 0) break;
  }
  cout << m;
  return 0;
}
