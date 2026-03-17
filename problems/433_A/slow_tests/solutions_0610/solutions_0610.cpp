#include <bits/stdc++.h>
using namespace std;
int n, sum, f[10005], a[105];
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sum /= 2;
  for (register int i = 1; i <= n; i++)
    for (register int j = sum; j >= a[i]; j--)
      f[j] = max(f[j], f[j - a[i]] + a[i]);
  if (f[sum] == sum)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
