#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int b[N], a[N], n;
int ans = 0;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int bound(int x) {
  int l = 1, r = n, ret = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (b[mid] >= x) {
      ret = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (ret == -1)
    return n + 1;
  else
    return ret;
}
int solve(int lim) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int q = bound(lim - b[i]);
    res += (n - bound(lim - b[i]) + 1);
    if (q <= i && q <= n) --res;
  }
  return res / 2;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int k = 0; k < 26; k++) {
    for (int i = 1; i <= n; i++) b[i] = a[i] % (1 << (k + 1));
    sort(b + 1, b + n + 1);
    int now =
        solve(1 << k) - solve(1 << (k + 1)) + solve((1 << (k + 1)) + (1 << k));
    if (now & 1) ans = ans + (1 << k);
  }
  printf("%d\n", ans);
  return 0;
}
