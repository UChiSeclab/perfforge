#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int a[N];
int sea(int x, int l, int r) {
  while (l < r) {
    int mid = (l + r) >> 1;
    if (a[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for (int i = 24; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      a[j] %= (int)pow(2, i + 1);
    }
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for (int j = 1; j < n; j++) {
      cnt += max(0, sea((int)pow(2, i + 1) - a[j], j + 1, n + 1) - 1 -
                        sea((int)pow(2, i) - a[j], j + 1, n + 1) + 1);
      cnt += max(
          0, sea((int)pow(2, i + 2) - 1 - a[j], j + 1, n + 1) - 1 -
                 sea((int)pow(2, i) + (int)pow(2, i + 1) - a[j], j + 1, n + 1) +
                 1);
    }
    if (cnt % 2 == 1) ans += (int)pow(2, i);
  }
  printf("%d\n", ans);
  return 0;
}
