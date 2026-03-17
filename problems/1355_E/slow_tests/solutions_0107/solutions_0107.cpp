#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long inf = 1e18;
int va[N], x, y, z, n;
long long getans(long long h) {
  long long ans = 0, a = 0, b = 0;
  for (int i = 1; i <= n; i++) {
    if (va[i] > h)
      a += va[i] - h;
    else
      b += h - va[i];
  }
  ans += 1ll * z * min(a, b);
  if (a > b)
    ans += 1ll * y * (a - b);
  else
    ans += 1ll * x * (b - a);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  cin >> x >> y >> z;
  z = min(z, x + y);
  for (int i = 1; i <= n; i++) cin >> va[i];
  int l = 0, r = 1e9 + 7;
  while (r - l > 5) {
    int midl = l + (r - l + 1) / 3 - 1, midr = r - (r - l + 1) / 3 + 1;
    if (getans(midl) < getans(midr))
      r = midr;
    else
      l = midl;
  }
  long long ans = inf;
  for (int i = l; i <= r; i++) ans = min(getans(i), ans);
  cout << ans << endl;
}
