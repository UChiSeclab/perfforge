#include <bits/stdc++.h>
int a[100000];
int main() {
  int y, k, n, i;
  while (scanf("%d %d %d", &y, &k, &n) != EOF) {
    int flag = 0;
    int l = n / k;
    for (i = 1; i <= l; i++) {
      a[i] = i * k;
      if (a[i] > y) {
        printf("%d ", a[i] - y);
        flag = 1;
      }
    }
    if (flag == 0) printf("-1");
    printf("\n");
  }
}
