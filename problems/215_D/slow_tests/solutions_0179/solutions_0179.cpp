#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 100006;
long long t, T, x, cst;
int main() {
  scanf("%d%d", &n, &m);
  long long ans = 0;
  for (int i = 0; i != n; i++) {
    scanf("%I64d%I64d%I64d%I64d", &t, &T, &x, &cst);
    long long ta1 = 0, ta2 = 0;
    ta1 += cst;
    if (t + m > T) ta1 += x * m;
    if (T - t > 0)
      if (m % (T - t))
        ta2 = cst * (m / (T - t) + 1);
      else
        ta2 = cst * (m / (T - t));
    else
      ta2 = ta1 + 1;
    ans += min(ta1, ta2);
  }
  printf("%I64d\n", ans);
}
