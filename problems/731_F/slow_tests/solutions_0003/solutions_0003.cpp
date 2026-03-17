#include <bits/stdc++.h>
using namespace std;
using LLI = long long int;
int n;
int as[214514];
LLI ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &as[i]);
  }
  sort(as, as + n);
  int prev = -1;
  for (int i = 0; i < n; i++) {
    if (prev == as[i]) continue;
    int t = as[i];
    LLI k = 0;
    while (t <= 200000) {
      k += n - (lower_bound(as, as + n, t) - as);
      t += as[i];
    }
    LLI cand = k * as[i];
    ans = max(ans, cand);
    prev = as[i];
  }
  printf("%I64d\n", ans);
}
