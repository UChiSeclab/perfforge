#include <bits/stdc++.h>
using namespace std;
int a[1000001], n, i, t, w, l, r;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  t = 1;
  w = n;
  l = 1;
  r = 1000000;
  for (i = 1; i <= 1000000; i++) {
    l++;
    r--;
    if (a[t] == l) t++;
    if (a[w] == r) w--;
    if (t > w) break;
  }
  printf("%d\n", i);
}
