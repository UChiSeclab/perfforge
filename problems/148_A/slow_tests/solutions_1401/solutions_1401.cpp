#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e, i;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
  int arr[e];
  if (a == 1 || b == 1 || c == 1 || d == 1)
    printf("%d\n", e);
  else {
    for (i = 1; i <= e; i++) {
      if (i % a == 0)
        arr[i - 1] = 1;
      else if (i % b == 0)
        arr[i - 1] = 1;
      else if (i % c == 0)
        arr[i - 1] = 1;
      else if (i % d == 0)
        arr[i - 1] = 1;
      else
        arr[i - 1] = 0;
    }
    int count = 0;
    for (i = 0; i < e; i++) {
      if (arr[i] == 1) count++;
    }
    printf("%d\n", count);
  }
  return 0;
}
