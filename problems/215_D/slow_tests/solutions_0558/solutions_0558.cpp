#include <bits/stdc++.h>
int n, m, i, j, k;
long long t, T, x, cost;
int main() {
  scanf("%d%d", &n, &m);
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    scanf("%I64d%I64d%I64d%I64d", &t, &T, &x, &cost);
    if (t >= T) {
      ans += cost + m * x;
      continue;
    }
    long long cap = T - t, car = (long long)ceil(m / double(cap)),
              cap2 = cap - car * cap + m, tmp = car * cost;
    if (car > 1) {
      if (car > cap2 && (cap2 + cap) * x < cost)
        tmp = (car - 1) * cost + (cap2 + cap) * x;
      if (car <= cap2 && m * x < cost) tmp = (car - 1) * cost + m * x;
    }
    if (tmp > cost + m * x) tmp = cost + m * x;
    ans += tmp;
  }
  printf("%I64d\n", ans);
  return 0;
}
