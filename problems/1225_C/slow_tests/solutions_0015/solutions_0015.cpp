#include <bits/stdc++.h>
using namespace std;
long long n, p, x, an, ans, MAXN = 1e9;
int main() {
  scanf("%lld%lld", &n, &p);
  ans = MAXN;
  for (int i = 1; i <= 1000000; i++) {
    n = n - p;
    if (n <= 0ll) break;
    x = n;
    an = 0;
    while (x) {
      an += x & 1;
      x >>= 1;
    }
    if (i >= an && n >= i) ans = min(ans, (long long)i);
  }
  if (ans == MAXN)
    printf("-1");
  else
    printf("%lld", ans);
}
