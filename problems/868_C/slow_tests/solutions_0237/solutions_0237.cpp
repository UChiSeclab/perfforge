#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, k;
int cnt[(1 << 4) + 5];
int now[4];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int st = 0;
    for (int j = 0; j < k; j++) {
      int x;
      scanf("%d", &x);
      st <<= 1;
      st += x;
    }
    cnt[st]++;
  }
  int m = 1 << k;
  int tot = 1 << m;
  bool ok = false;
  for (int s = 0; s < tot; s++) {
    int C = 0;
    memset(now, 0, sizeof now);
    for (int st = 0; st < m; st++)
      if (s & (1 << st)) {
        C += (cnt[st] ? 1 : 0);
        for (int i = 0; i < k; i++)
          if ((st & (1 << i))) now[i] += (cnt[st] ? 1 : 0);
      }
    bool tmp = true;
    for (int i = 0; i < k; i++) {
      if (now[i] * 2 > C) tmp = false;
    }
    if (tmp && C) ok = true;
  }
  puts(ok ? "YES" : "NO");
  return 0;
}
