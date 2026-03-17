#include <bits/stdc++.h>
using namespace std;
int Ha[30];
int N, K;
int main() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; i++) {
    int s = 0;
    for (int j = 1; j <= K; j++) {
      int x;
      scanf("%d", &x);
      s = (s << 1) + x;
    }
    Ha[s]++;
  }
  for (int s = 1; s < (1 << (1 << K)); s++) {
    int sum[4] = {0}, cnt = 0;
    bool can = true;
    for (int i = 0; i < (1 << K); i++) {
      if ((s >> i) & 1) {
        cnt++;
        if (!Ha[i]) can = false;
        for (int t = 0; t < 4; t++) sum[t] += (i >> t) & 1;
      }
    }
    if (!can) continue;
    bool ok = true;
    for (int i = 0; i < 4; i++) {
      if (sum[i] <= cnt / 2)
        ;
      else
        ok = false;
    }
    if (ok) return puts("YES"), 0;
  }
  puts("NO");
  return 0;
}
