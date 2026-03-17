#include <bits/stdc++.h>
using namespace std;
bool arr[5005][5005];
int main() {
  int i, a, n, m, x, ret = 0;
  scanf("%d %d %d", &n, &m, &x);
  n -= 2 * (x - 1);
  m -= 2 * (x - 1);
  if (n <= 0 && m <= 0)
    printf("0\n");
  else {
    for (i = 0; i < n; i++) {
      if (i % 2 == 0)
        arr[i][0] = 1;
      else
        arr[i][0] = 0;
      for (a = 1; a < m; a++) arr[i][a] = !arr[i][a - 1];
    }
    for (i = 0; i < n; i++)
      for (a = 0; a < m; a++)
        if (i == 0 || i == n - 1 || a == 0 || a == m - 1) ret += arr[i][a];
    printf("%d\n", ret);
  }
  return 0;
}
