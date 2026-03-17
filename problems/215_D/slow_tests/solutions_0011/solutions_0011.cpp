#include <bits/stdc++.h>
using namespace std;
long long t[100001], T[100001], x[100001], cost[1000001], n, m, k, j, i, ans;
int main() {
  scanf("%I64d%I64d", &m, &n);
  for (i = 1; i <= m; i++)
    scanf("%I64d%I64d%I64d%I64d", &t[i], &T[i], &x[i], &cost[i]);
  ans = 0;
  for (i = 1; i <= m; i++) {
    long long mi;
    if (t[i] >= T[i]) {
      ans += x[i] * n + cost[i];
      continue;
    }
    long long tmp = x[i] * n + cost[i], tmp2 = 0, tmp1 = 0;
    long long d = T[i] - t[i];
    k = n / d;
    tmp1 += k * cost[i];
    if (n % d != 0) tmp1 += cost[i];
    mi = min(tmp, tmp1);
    ans += mi;
  }
  printf("%I64d", ans);
}
