#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
const int INF = 1000 * 1000 * 1000;
const int NMAX = 1000 * 1000;
long ans, i, j, k, l, n, m, x, y;
double mx, cur, c;
bool first = true;
;
long a[1000];
long long mn;
int main() {
  freopen("out.deb", "w", stderr);
  scanf("%d", &n);
  for ((i) = (0); (i) < (n); (i)++) scanf("%d", &a[i]);
  mx = 10 + (a[1] - a[0]) * 10;
  for (cur = a[0] * 10; cur <= a[0] * 10 + 10; cur += 0.000001) {
    c = cur - a[0] * 10;
    if (c > 10) break;
    for ((i) = (1); (i) < (n); (i)++) {
      c += cur;
      c -= (a[i] - a[i - 1]) * 10;
      if (c > 10) {
        printf("unique\n%d", x);
        return 0;
      }
      if (c < 0) {
        break;
      }
    }
    if (c + cur > 0 && i == n) {
      y = (c + cur) / 10 + a[n - 1];
      if (first) {
        x = y;
        first = false;
      }
      if (x != y) {
        printf("not unique");
        return 0;
      }
    }
  }
  printf("unique\n%d", x);
  return 0;
}
