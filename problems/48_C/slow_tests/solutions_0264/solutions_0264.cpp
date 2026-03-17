#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
inline bool lt(double a, double b) { return a + eps < b; }
inline bool eq(double a, double b) { return !lt(a, b) && !lt(b, a); }
int n, s[1002];
double A, B, lo, hi, mid;
int next(double mid) {
  double x = mid;
  int nxt = 0;
  for (int i = 0; i < n; ++i) {
    nxt += int(x / 10);
    x = fmod(x, 10) + mid;
  }
  nxt += int(x / 10);
  return nxt;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
  lo = 10;
  hi = 10000000;
  for (int iter = 0; iter < 200; ++iter) {
    mid = (lo + hi) / 2;
    bool ok = true;
    double x = mid;
    int nxt = 0;
    for (int i = 0; i < n; ++i) {
      nxt += int(x / 10);
      if (nxt < s[i]) {
        ok = false;
        break;
      }
      if (nxt > s[i]) break;
      x = fmod(x, 10) + mid;
    }
    if (!ok)
      lo = mid + eps;
    else
      hi = mid;
  }
  A = mid;
  lo = 10;
  hi = 10000000;
  for (int iter = 0; iter < 200; ++iter) {
    mid = (lo + hi) / 2;
    bool ok = true;
    double x = mid;
    int nxt = 0;
    for (int i = 0; i < n; ++i) {
      nxt += int(x / 10);
      if (nxt > s[i]) {
        ok = false;
        break;
      }
      if (nxt < s[i]) break;
      x = fmod(x, 10) + mid;
    }
    if (!ok)
      hi = mid - eps;
    else
      lo = mid;
  }
  B = mid;
  int na = next(A);
  int nb = next(B);
  if (na == nb)
    printf("unique\n%d\n", na);
  else
    printf("not unique\n");
  return 0;
}
