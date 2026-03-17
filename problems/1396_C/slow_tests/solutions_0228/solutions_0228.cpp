#include <bits/stdc++.h>
using namespace std;
long long n, d, r1, r2, r3, i, w[1000008], x[1000008], y[1000008], z[1000008];
int main() {
  for (scanf("%I64d%I64d%I64d%I64d%I64d", &n, &r1, &r2, &r3, &d),
       r3 < r1 ? r1 = r3 : 0;
       i++ < n; scanf("%I64d", w + i), z[i] = w[i] * r1 + r3,
                 z[i] =
                     min(z[i],
                         (d << 1) + (w[i] = min(r2 + min(r2, r1),
                                                w[i] * r1 + min(r1 << 1, r3)))))
    ;
  for (x[i--] = -d, x[i] = y[i] = z[i]; --i;
       (y[i] = w[i] + d + d + y[i + 1]) <
               (x[i] = min(z[i] + d + x[i + 1],
                           w[i] + w[i + 1] + (d << 2) + x[i + 2]))
           ? x[i] = y[i]
           : 0)
    ;
  printf("%I64d\n", x[1]), exit(0);
}
