#include <bits/stdc++.h>
using namespace std;
int a[1010];
int n;
bool check(int v) {
  n++;
  a[n - 1] = v;
  double l = 10, r = 100000000;
  for (int it = (0); it < (200); ++it) {
    double m = (l + r) / 2;
    int v = 0;
    int st = 0;
    double have = m;
    for (int i = (0); i < (n); ++i) {
      int c = (int)(have / 10);
      if (c > a[i] - st) {
        v = 1;
        break;
      }
      if (c < a[i] - st) {
        v = -1;
        break;
      }
      have -= (a[i] - st) * 10;
      have += m;
      st = a[i];
    }
    if (v == -1)
      l = m;
    else if (v == 1)
      r = m;
    else {
      n--;
      return true;
    }
  }
  n--;
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  bool f1 = check(a[n - 1] + a[0]);
  bool f2 = check(a[n - 1] + a[0] + 1);
  if ((f1) && (f2)) {
    printf("not unique\n");
  } else if (f1)
    printf("unique\n%d\n", a[n - 1] + a[0]);
  else
    printf("unique\n%d\n", a[n - 1] + a[0] + 1);
  return 0;
}
