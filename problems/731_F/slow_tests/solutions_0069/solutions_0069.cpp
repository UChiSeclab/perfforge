#include <bits/stdc++.h>
using namespace std;
long long n, a[((long long)201 * 1000)], res;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    long long ans = 0;
    if (i && a[i] == a[i - 1]) continue;
    for (long long j = a[i]; j < ((long long)201 * 1000); j += a[i]) {
      long long x = (lower_bound(a, a + n, j) - a) -
                    (lower_bound(a, a + n, j + a[i]) - a);
      ans += (-x) * j;
    }
    res = max(ans, res);
  }
  cout << res;
}
