#include <bits/stdc++.h>
using namespace std;
int n, m, h;
int sum;
int s;
int main() {
  scanf("%d%d%d", &n, &m, &h);
  sum = 0;
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    sum += x;
    if (i == h) s = x;
  }
  if (sum < n) {
    printf("-1\n");
  } else {
    if (sum - s + 1 < n) {
      printf("1.0\n");
    } else {
      if (s == 1) {
        printf("0.0\n");
        return 0;
      }
      double ans = 0.0;
      for (int i = 1; i <= sum - s; i++) {
        ans += log((double)i);
      }
      for (int i = 1; i <= sum - n; i++) {
        ans += log((double)i);
      }
      for (int i = 1; i <= sum - 1; i++) {
        ans -= log((double)i);
      }
      for (int i = 1; i <= sum - s - n + 1; i++) {
        ans -= log((double)i);
      }
      printf("%.8lf\n", 1.0 - exp(ans));
    }
  }
  return 0;
}
