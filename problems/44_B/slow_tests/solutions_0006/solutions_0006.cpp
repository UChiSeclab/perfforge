#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const double PI = (double)acos(-1.0);
const double EPS = (double)1e-9;
const int MOD = (int)1e9 + 7;
int dat[20005];
inline void display(int n) {
  for (int i = 0; i <= n; i += 1) printf("%d ", dat[i]);
  puts("");
}
int main() {
  for (int i = 0; i <= 20003 - 1; i += 1) dat[i] = 0;
  dat[0] = 1;
  int n, a, b, c;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  n *= 2;
  for (int i = n; i >= 1; i -= 1)
    for (int j = 1; j <= c; j += 1) {
      if (i - (j << 2) < 0) break;
      dat[i] += dat[i - (j << 2)];
    }
  for (int i = n; i >= 1; i -= 1)
    for (int j = 1; j <= b; j += 1) {
      if (i - (j << 1) < 0) break;
      dat[i] += dat[i - (j << 1)];
    }
  for (int i = n; i >= 1; i -= 1)
    for (int j = 1; j <= a; j += 1) {
      if (i - (j << 0) < 0) break;
      dat[i] += dat[i - (j << 0)];
    }
  printf("%d\n", dat[n]);
  return 0;
}
