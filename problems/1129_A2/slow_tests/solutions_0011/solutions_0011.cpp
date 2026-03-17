#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool t = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') t = true, ch = getchar();
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
  return t ? -x : x;
}
int n, m, cnt[5050], d[5050];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) d[i] = n + 1;
  for (int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    if (r < l) r += n;
    cnt[l] += 1;
    d[l] = min(d[l], r - l);
  }
  int mx = 0;
  for (int i = 1; i <= n; ++i) mx = max(mx, cnt[i]);
  for (int i = 1; i <= n; ++i)
    if (cnt[i] < max(1, mx - 1)) d[i] = 0;
  for (int i = 1; i <= n; ++i) {
    int ans = (mx - 1) * n, mxx = 0;
    for (int j = 1; j <= n; ++j)
      if (cnt[j] == mx) {
        int dis = i <= j ? j - i : j - i + n;
        dis += d[j];
        mxx = max(mxx, dis);
      } else if (cnt[j] == mx - 1) {
        int dis = j < i ? i - j : i - j + n;
        mxx = max(mxx, d[j] - dis);
      }
    printf("%d ", ans + mxx);
  }
  puts("");
  return 0;
}
