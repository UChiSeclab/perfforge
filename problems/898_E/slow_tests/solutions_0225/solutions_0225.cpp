#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[200010], b[200010];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(&a[1], &a[n + 1]);
  int min, max, l = 1;
  min = (int)sqrt(a[1]);
  max = (int)sqrt(a[n]);
  for (int i = min; i <= max + 1; i++) {
    int x = i * i;
    while (a[l] <= x) {
      b[l] = x - a[l];
      l++;
      if (l == n + 1) break;
    }
    if (l == n + 1) break;
  }
  l = n;
  for (int i = max; i >= min; i--) {
    int x = i * i, y;
    while (a[l] >= x) {
      y = a[l] - x;
      if (y < b[l]) b[l] = y;
      l--;
      if (!l) break;
    }
    if (!l) break;
  }
  sort(&b[1], &b[n + 1]);
  long long ans = 0;
  int st = n / 2 + 1;
  for (; st <= n; st++) {
    if (b[st])
      break;
    else {
      if (!a[st])
        ans += 2;
      else
        ans += 1;
    }
  }
  n /= 2;
  for (int i = 1; i <= n; i++) ans += b[i];
  printf("%lld\n", ans);
  return 0;
}
