#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long h[maxn];
long long n, a, b, m;
long long ck(long long x) {
  long long d1 = 0, d2 = 0;
  for (int i = 1; i <= n; i++) {
    long long p = x - h[i];
    if (p < 0)
      d2 += h[i] - x;
    else
      d1 += x - h[i];
  }
  long long mi = min(d1, d2);
  long long fir = m * mi + (d1 - mi) * a + (d2 - mi) * b;
  long long sec = d1 * a + d2 * b;
  return min(fir, sec);
}
int main() {
  cin >> n >> a >> b >> m;
  long long mi = 0x7f7f7f7f7f7f7f, mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    if (mi > h[i]) mi = h[i];
    if (mx < h[i]) mx = h[i];
  }
  sort(h + 1, h + 1 + n);
  long long c1 = 0, c2 = 0;
  for (int i = 1; i <= n; i++) {
    c2 += (mx - h[i]) * a;
    c1 += (h[i] - mi) * b;
  }
  long long ans = min(c1, c2);
  long long l = mi, r = mx;
  while (r - l > 10) {
    long long lmid = l + (r - l) / 3;
    long long rmid = r - (r - l) / 3;
    if (ck(lmid) < ck(rmid))
      r = rmid;
    else
      l = lmid;
  }
  for (int i = l; i <= r; i++) {
    ans = min(ck(i), ans);
  }
  cout << ans << '\n';
}
