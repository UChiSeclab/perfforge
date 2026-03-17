#include <bits/stdc++.h>
int main() {
  int a, m, mod, j = 0;
  scanf("%d%d", &a, &m);
  int b[m];
  while (a % m != 0) {
    mod = a % m;
    for (int i = 0; i < j; ++i) {
      if (b[i] == mod) {
        printf("No");
        return 0;
      }
    }
    b[j] = mod;
    j++;
    a += mod;
  }
  printf("Yes");
}
