#include <bits/stdc++.h>
long n;
long long f[4][20005] = {0}, a[4] = {0}, b[4] = {0, 1, 2, 4};
int main() {
  long i, j, k;
  scanf("%I64d%I64d%I64d%I64d", &n, &a[1], &a[2], &a[3]);
  n = n * 2;
  f[0][0] = 1;
  for (i = 1; i <= 3; i++)
    for (k = n; k >= 0; k--)
      for (j = 0; j * b[i] <= k && j <= a[i]; j++)
        f[i][k] += f[i - 1][k - j * b[i]];
  printf("%I64d\n", f[3][n]);
  return (0);
}
