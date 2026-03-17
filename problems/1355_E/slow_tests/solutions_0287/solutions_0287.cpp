#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n, a, R, m, l, r, lmid, rmid, ans;
long long h[N];
long long calc(long long H) {
  long long less = 0, more = 0;
  for (long long i = 1; i <= n; i++) {
    if (h[i] > H) more += (h[i] - H);
    if (h[i] < H) less += (H - h[i]);
  }
  if (more > less)
    return (more - less) * R + less * m;
  else
    return (less - more) * a + more * m;
}
long long bin3() {
  l = 0, r = 1e9;
  ans = min(calc(l), calc(r));
  while (l <= r) {
    lmid = (l + r) / 2, rmid = (lmid + r) / 2;
    if (calc(lmid) > calc(rmid))
      l = lmid + 1;
    else
      r = rmid - 1;
    ans = min(ans, min(calc(lmid), calc(rmid)));
  }
  return ans;
}
signed main() {
  cin >> n >> a >> R >> m;
  m = min(m, a + R);
  for (long long i = 1; i <= n; i++) cin >> h[i];
  cout << bin3();
  return 0;
}
