#include <bits/stdc++.h>
int main() {
  int n, m, i, j, k, sum;
  int a[5] = {1, 2, 4}, b;
  int c1[20005], c2[20005];
  while (scanf("%d", &n) != EOF) {
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    c1[0] = 1;
    for (i = 0; i < 3; i++) {
      scanf("%d", &b);
      for (j = 0; j <= 2 * n; j++) {
        for (k = 0; k <= b && j + a[i] * k <= 2 * n; k++) {
          c2[j + a[i] * k] += c1[j];
        }
      }
      for (j = 0; j <= 2 * n; j++) {
        c1[j] = c2[j];
        c2[j] = 0;
      }
    }
    printf("%d\n", c1[2 * n]);
  }
  return 0;
}
