#include <bits/stdc++.h>
using namespace std;
long long n, r1, r2, r3, tim;
long long a[1000010], d[1000010];
int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &n, &r1, &r2, &r3, &tim);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  d[0] = 0;
  for (int i = 1; i <= n; i++) {
    d[i] = d[i - 1] + (i == 1 ? 0 : tim) + r1 * a[i] + r3;
    d[i] = min(d[i], d[i - 1] + (i == 1 ? 0 : tim) + min(r2, r1 * a[i] + r1) +
                         2 * tim + r1);
    if (i >= 2) {
      d[i] = min(d[i], d[i - 2] + (i - 1 == 1 ? 0 : tim) +
                           min(r2, r1 * a[i - 1] + r1) + tim +
                           min(r2, r1 * a[i] + r1) + tim + 2 * r1 + tim);
      d[i] = min(d[i], d[i - 2] + (i - 1 == 1 ? 0 : tim) +
                           min(r2, r1 * a[i - 1] + r1) + tim + r1 * a[i] + r3 +
                           tim + r1 + tim);
    }
  }
  long long res = d[n];
  res =
      min(res, d[n - 2] + (n - 1 == 1 ? 0 : tim) + min(r2, r1 * a[n - 1] + r1) +
                   tim + min(r2, r1 * a[n] + r1) + 2 * tim + 2 * r1);
  res =
      min(res, d[n - 2] + (n - 1 == 1 ? 0 : tim) + min(r2, r1 * a[n - 1] + r1) +
                   tim + r1 * a[n] + r3 + tim + r1);
  printf("%I64d", res);
  return 0;
}
