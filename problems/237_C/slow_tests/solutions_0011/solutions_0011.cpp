#include <bits/stdc++.h>
int A[2000009], B[2000009], C[2000009];
int a, b, k, i, j, max, last, res, cnt;
int main() {
  while (scanf("%d %d %d", &a, &b, &k) == 3) {
    A[0] = 1;
    A[1] = 1;
    for (i = 3;; i = i + 2) {
      if (i * i > 2 * b) break;
      if (A[i] == 0)
        for (j = i * i; j <= 2 * b; j = j + i + i) A[j] = 1;
    }
    for (i = 2 * b; i >= 0; i--) B[i] = 0;
    cnt = 0;
    last = 2 * b;
    for (i = 2 * b; i >= 0; i--) {
      if ((i % 2 != 0 && A[i] == 0) || i == 2) {
        if (cnt == 0) last = i;
        cnt++;
      }
      if (cnt > k) {
        cnt--;
        for (j = last - 1;; j--)
          if ((j % 2 != 0 && A[j] == 0) || j == 2) {
            last = j;
            break;
          }
      }
      if (cnt >= k) B[i] = last;
    }
    for (i = a; i <= b; i++) C[i] = 0;
    max = -1;
    for (i = a; i <= b; i++) {
      if (B[i] != 0) {
        if (max == -1 || B[i] - i > max) max = B[i] - i;
      }
      C[i] = max;
    }
    res = -1;
    for (i = 1; i <= b - a + 1; i++) {
      if (b - i + 1 >= a) {
        if (C[b - i + 1] != -1 && C[b - i + 1] < i) {
          res = i;
          break;
        }
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
