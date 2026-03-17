#include <bits/stdc++.h>
int i, k, n, m, j;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i <= 10000; ++i) {
    for (j = 0; j <= 10000; ++j) {
      if (n * i + m * j == k) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
