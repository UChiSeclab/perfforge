#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, c, d1, d2, d3, d4, l, r, u, d, i = 0, c1, c2, c3, c4;
  cin >> n >> x >> y >> c;
  d1 = min(n - y, x - 1);
  c1 = max(n - y, x - 1) - d1;
  d2 = min(n - y, n - x);
  c2 = max(n - y, n - x) - d2;
  d3 = min(y - 1, x - 1);
  c3 = max(y - 1, x - 1) - d3;
  d4 = min(y - 1, n - x);
  c4 = max(y - 1, n - x) - d4;
  long sum = 1;
  u = x, d = x, l = y, r = y;
  while (sum < c) {
    if (i) {
      if (i > d1 && i <= c1 + d1)
        sum += d1;
      else if (i <= d1)
        sum += i;
      else
        sum += max(0, --d1);
      if (i > d2 && i <= c2 + d2)
        sum += d2;
      else if (i <= d2)
        sum += i;
      else
        sum += max(0, --d2);
      if (i > d3 && i <= c3 + d3)
        sum += d3;
      else if (i <= d3)
        sum += i;
      else
        sum += max(0, --d3);
      if (i > d4 && i <= c4 + d4)
        sum += d4;
      else if (i <= d4)
        sum += i;
      else
        sum += max(0, --d4);
    }
    if (u > 1) sum++;
    if (d < n) sum++;
    if (l > 1) sum++;
    if (r < n) sum++;
    u--, d++, l--, r++;
    i++;
  }
  cout << i;
  return 0;
}
