#include <bits/stdc++.h>
using namespace std;
int n, m, ans, i, j;
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1 || m == 1)
    printf("%d", max(n, m));
  else if (n == 2 || m == 2) {
    ans = max(n, m) / 4;
    ans = ans * 2;
    if (max(n, m) % 4 == 3)
      ans += 2;
    else
      ans += max(n, m) % 4;
    ans *= 2;
    printf("%d", ans);
  } else {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++)
        if ((i % 2 == 1 && j % 2 == 1) || (i % 2 == 0 && j % 2 == 0)) ans++;
    printf("%d", ans);
  }
  return 0;
}
