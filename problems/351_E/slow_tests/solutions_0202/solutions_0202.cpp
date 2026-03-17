#include <bits/stdc++.h>
using namespace std;
int cmp_double(const double a, const double b, const double eps) {
  if (a + eps < b) return -1;
  if (a > b + eps) return 1;
  return 0;
}
int n, a[2048];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j < i && a[j] > a[i])
        ++ans;
      else if (j > i && a[j] < a[i])
        ++ans;
    }
  }
  for (int i = 0; i < 10; ++i) {
    for (int i = 0; i < n; ++i) {
      int k = 0;
      for (int j = 0; j < n; ++j) {
        if (j < i && a[j] > a[i] && a[j] <= -a[i])
          --k;
        else if (j < i && a[j] <= a[i] && a[j] > -a[i])
          ++k;
        else if (i < j && a[i] <= a[j] && -a[i] > a[j])
          ++k;
        else if (i < j && a[i] > a[j] && -a[i] <= a[j])
          --k;
      }
      if (k <= 0) {
        a[i] = -a[i];
        ans += 2 * k;
      }
    }
  }
  printf("%d\n", ans / 2);
  return 0;
}
