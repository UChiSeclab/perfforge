#include <bits/stdc++.h>
using namespace std;
int a[400];
int can[1000];
int main() {
  int n;
  scanf("%d", &n);
  int s = 0;
  can[0] = 1;
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    k /= 100;
    s += k;
    for (int t = 1000 - 1; t >= 0; t--)
      if (can[t]) can[t + k] = 1;
  }
  if (s % 2)
    puts("NO");
  else {
    int p = s / 2;
    if (can[p])
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
