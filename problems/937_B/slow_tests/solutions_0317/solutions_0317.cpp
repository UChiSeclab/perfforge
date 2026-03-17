#include <bits/stdc++.h>
int prime[32001], p, y, lim, m;
int main() {
  int i, j;
  scanf("%d %d", &p, &y);
  lim = ((32000) < (p) ? (32000) : (p));
  prime[m++] = 2;
  for (i = 3; i <= lim; i += 2) {
    for (j = 1; j < m; j++) {
      if (prime[j] * prime[j] > i || i % prime[j] == 0) break;
    }
    if (prime[j] * prime[j] > i || j == m) {
      prime[m++] = i;
    }
  }
  for (; y > p; y--) {
    for (j = 0; j < m; j++) {
      if (prime[j] * prime[j] > y || y % prime[j] == 0) break;
    }
    if (prime[j] * prime[j] > y || j == m) {
      printf("%d\n", y);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
