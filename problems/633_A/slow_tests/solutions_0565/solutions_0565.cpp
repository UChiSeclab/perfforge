#include <bits/stdc++.h>
int main() {
  int a, b, c, i, j, count = 0;
  scanf("%d %d %d", &a, &b, &c);
  for (i = 0; i < 10000; i++) {
    for (j = 0; j < 10000; j++) {
      if ((a * i + j * b) == c) {
        count++;
        printf("Yes");
        break;
      }
    }
    if (count > 0) break;
  }
  if (count == 0) printf("No");
  return 0;
}
