#include <bits/stdc++.h>
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int i;
  int cnt = 0;
  for (i = 1; i <= n; i++) {
    int y = x / i;
    if ((x % i == 0) && (y <= n)) {
      cnt = cnt + 1;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
