#include <bits/stdc++.h>
using namespace std;
int a0, a1, n, ans, table[500];
int getans(int);
int main() {
  scanf("%d%d%d", &a0, &a1, &n);
  printf("%d\n", getans(n));
  return 0;
}
int getans(int an) {
  if (an == 0) return a0;
  if (an == 1) return a1;
  return getans(an - 1) + getans(an - 2);
}
