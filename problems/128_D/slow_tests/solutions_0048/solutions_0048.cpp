#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
int n, a[N], buc[N], mi = inf;
int main() {
  scanf("%d", &n);
  if (n & 1) return puts("NO"), 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mi = min(mi, a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= n; i++)
    if (a[i] - a[i - 1] > 1) return puts("NO"), 0;
  for (int i = 1; i <= n; i++) ++buc[a[i] - mi + 1];
  int u = 1;
  --buc[1];
  while (true) {
    if (buc[u + 1])
      --buc[++u];
    else if (buc[u - 1])
      --buc[--u];
    else
      break;
  }
  if (u != 2) return puts("NO"), 0;
  for (int i = 0; i <= N - 1; i++)
    if (buc[i]) return puts("NO"), 0;
  return puts("YES"), 0;
}
