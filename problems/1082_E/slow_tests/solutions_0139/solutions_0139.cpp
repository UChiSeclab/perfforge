#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, c, prec[maxn], x, cnt[maxn];
vector<int> posi[maxn];
int main() {
  int mma = -1;
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    mma = max(mma, x);
    prec[i] = prec[i - 1];
    if (x == c)
      prec[i]++;
    else
      posi[x].push_back(i);
  }
  int ans = prec[n];
  for (int i = 1; i <= mma; i++) {
    if (!posi[i].size()) continue;
    int tmp = 0;
    for (int j = 0; j < posi[i].size(); j++) {
      int nowpos = posi[i][j];
      tmp = max(tmp, prec[nowpos - 1] - cnt[i]);
      cnt[i]++;
      ans = max(ans, prec[n] - prec[nowpos] + tmp + cnt[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
