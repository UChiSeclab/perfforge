#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int N, a[maxn];
int solve(int x) {
  int ret = 0, p = x;
  while (p < maxn) {
    p += x;
    int k = lower_bound(a, a + N, p) - a;
    if (k == 0)
      continue;
    else
      k--;
    if (a[k] <= x) continue;
    ret = max(ret, a[k] % x);
  }
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  sort(a, a + N);
  int ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (ans >= a[i] - 1) break;
    if (i < N - 1 && a[i] == a[i + 1]) continue;
    ans = max(ans, solve(a[i]));
  }
  printf("%d\n", ans);
  return 0;
}
