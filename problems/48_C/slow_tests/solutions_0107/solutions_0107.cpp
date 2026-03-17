#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1010;
const double Inf = 100010;
int main() {
  int N;
  int a[MaxN];
  int i, j, t;
  int ans, tmp;
  double m, v;
  bool ill, uni;
  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &a[i + 1]);
  a[0] = 0;
  ans = -1;
  uni = 0;
  m = a[1] * 10;
  for (t = 0; t < 1000000; t++) {
    v = m;
    ill = 0;
    for (i = 1; i <= N; i++) {
      v -= (double)(a[i] - a[i - 1]) * 10;
      if (v < 0 || v > 10) {
        ill = 1;
        break;
      }
      v += m;
    }
    m += 0.00001;
    if (ill) continue;
    tmp = a[N] + (int)(v / 10);
    if (ans == -1)
      ans = tmp;
    else if (ans != tmp) {
      uni = 1;
      break;
    }
  }
  if (uni)
    printf("not unique");
  else
    printf("unique\n%d", ans);
  return 0;
}
