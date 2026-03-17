#include <bits/stdc++.h>
using namespace std;
const long long MN = 1100000;
long long d[MN];
long long a[MN], b[MN], c[MN];
signed main() {
  long long n;
  cin >> n;
  long long s = 0;
  for (long long i = 0; i < n; i++) {
    cin >> d[i];
    s += d[i];
  }
  sort(d, d + n, greater<long long>());
  a[0] = b[0] = c[0] = 0;
  for (long long i = 0; i <= n; i++) {
    a[i + 1] = a[i], b[i + 1] = b[i], c[i + 1] = c[i];
    a[i + 1] += 4 - d[i];
    if (d[i] == 4) {
      c[i + 1]++;
    } else {
      b[i + 1] += 3 - d[i];
    }
    assert(a[i + 1] >= a[i]);
    assert(b[i + 1] >= b[i]);
    assert(c[i + 1] >= c[i]);
  }
  long long r = s * 2;
  for (long long i = 0; i <= n; i++) {
    long long u = s - 4 * i;
    if (u < 0) break;
    if (u % 3) continue;
    u /= 3;
    if (n < i + u) continue;
    long long bb = b[i + u] - b[i], cc = c[i + u] - c[i];
    r = min(r, a[i] + bb);
  }
  if (r == s * 2) {
    cout << -1 << endl;
  } else {
    cout << r << endl;
  }
  return 0;
}
