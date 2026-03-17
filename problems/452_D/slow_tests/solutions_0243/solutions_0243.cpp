#include <bits/stdc++.h>
using namespace std;
int n, i, j, n1, n2, n3, t1, t2, t3, next1, next2, next3, v[10005];
int maxx(int a, int b, int c) {
  if (a >= b && a >= c) return a;
  if (b >= a && b >= c) return b;
  return c;
}
int main() {
  scanf("%d", &n);
  scanf("%d%d%d", &n1, &n2, &n3);
  scanf("%d%d%d", &t1, &t2, &t3);
  next1 = 0;
  next2 = 0;
  next3 = 0;
  for (i = 1; i <= n; i++) {
    v[i] = maxx(next1, next2 - t1, next3 - t1 - t2);
    next1 = 9999999;
    next2 = 9999999;
    next3 = 9999999;
    for (j = 0; j < n1; j++) {
      if (i - j < 0) break;
      if (v[i - j] + t1 < next1) next1 = v[i - j] + t1;
      if (i - j == 0) next1 = 0;
    }
    for (j = 0; j < n2; j++) {
      if (i - j < 0) break;
      if (v[i - j] + t1 + t2 < next2) next2 = v[i - j] + t1 + t2;
      if (i - j == 0) next2 = 0;
    }
    for (j = 0; j < n3; j++) {
      if (i - j < 0) break;
      if (v[i - j] + t1 + t2 + t3 < next3) next3 = v[i - j] + t1 + t2 + t3;
      if (i - j == 0) next3 = 0;
    }
  }
  printf("%d", v[n] + t1 + t2 + t3);
  return 0;
}
