#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main() {
  long long n, bnd, tmp, ans, mx;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    bnd = a[0] * 2;
    mx = 0;
    for (int i = 0; i < n; ++i) {
      if (i != 0 && a[i] == a[i - 1]) continue;
      tmp = 2;
      ans = 0;
      while (1) {
        if (a[i] * (tmp - 1) > 200010) {
          break;
        }
        ans += (long long)((upper_bound(a, a + n, a[i] * tmp - 1) - a) -
                           (upper_bound(a, a + n, a[i] * (tmp - 1) - 1) - a)) *
               a[i] * (tmp - 1);
        ++tmp;
      }
      mx = max(mx, ans);
    }
    cout << mx << endl;
  }
  return 0;
}
