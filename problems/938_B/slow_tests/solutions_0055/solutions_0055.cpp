#include <bits/stdc++.h>
int main() {
  int n, i, t = 0, b, j;
  scanf("%d", &n);
  int a[n], x, y;
  x = 1;
  y = 1000000;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  b = n;
  i = 0;
  j = n - 1;
  while (b >= 1) {
    if (x == a[i]) {
      a[i] = 0;
      i++;
      b--;
    }
    if (y == a[j]) {
      a[j] = 0;
      j--;
      b--;
    }
    x = x + 1;
    y = y - 1;
    t++;
  }
  printf("%d", t - 1);
  return 0;
}
