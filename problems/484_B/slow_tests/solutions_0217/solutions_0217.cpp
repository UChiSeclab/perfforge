#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000 + 10;
int Q[MAX_N];
int N;
int judge(int x) {
  int p = x, res = 0;
  while (p < 1000000 + 10) {
    p += x;
    int k = lower_bound(Q, Q + N, p) - Q;
    if (k == 0)
      continue;
    else
      k--;
    if (Q[k] <= x) continue;
    res = max(res, Q[k] % x);
  }
  return res;
}
int main() {
  scanf("%d", &N);
  int ans = 0;
  for (int i = 0; i < N; i++) scanf("%d", Q + i);
  sort(Q, Q + N);
  for (int i = N - 1; i >= 0; i--) {
    if (ans > Q[i] - 1) break;
    if (i < N - 1 && Q[i] == Q[i - 1]) continue;
    ans = max(ans, judge(Q[i]));
  }
  printf("%d\n", ans);
  return 0;
}
