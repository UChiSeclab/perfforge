#include <bits/stdc++.h>
using namespace std;
int n, k;
int cnt[111];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x = 0;
    for (int j = 0; j < k; j++) {
      int t;
      scanf("%d", &t);
      x = x * 2 + t;
    }
    cnt[x]++;
  }
  bool ans = false;
  if (cnt[0]) ans = true;
  int m = 1 << k;
  for (int S = 1; S < (1 << m); S++) {
    int tmp[4], all = 0;
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < m; i++)
      if ((S >> i & 1) && cnt[i]) {
        all++;
        for (int j = 0; j < k; j++)
          if (i >> j & 1) tmp[j]++;
      }
    if (*max_element(tmp, tmp + k) * 2 <= all && all) {
      ans = true;
    }
  }
  puts(ans ? "YES" : "NO");
  return 0;
}
