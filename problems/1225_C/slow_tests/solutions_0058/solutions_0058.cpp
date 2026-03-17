#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  for (int i = 0; i <= 1000000; i++) {
    int tmp = n - p * i;
    int cnt = 0;
    while (tmp) {
      cnt += tmp % 2;
      tmp /= 2;
    }
    if (cnt <= i && i <= n - p * i) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
