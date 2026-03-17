#include <bits/stdc++.h>
int main() {
  int a, b, c, x, y;
  int p, flag = 0;
  scanf("%d %d %d", &a, &b, &c);
  for (x = 0; x <= 10000; x++) {
    for (y = 0; y <= 10000; y++) {
      p = x * a + y * b;
      if (p == c) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
  }
  if (flag == 1)
    printf("Yes");
  else
    printf("No");
  return 0;
}
