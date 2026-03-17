#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 4e5 + 5;
int n, m, k, tot = 0;
struct man {
  int k, d;
} a[N];
int main() {
  int mark[105];
  memset(mark, 0, sizeof mark);
  int s, t, t1, t2, p, dir;
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d%d", &s, &t, &t1);
    a[s].k = t;
    a[s].d = t1;
  }
  tot = n;
  for (int i = 1; i <= 1000000; i++) {
    if (!a[i].k) {
      tot = 0;
      for (int j = 1; j <= n; j++) {
        if (mark[j]) mark[j]--;
        if (mark[j] < 1) tot++;
      }
      continue;
    }
    if (tot < a[i].k) {
      printf("-1\n");
      tot = 0;
      for (int j = 1; j <= n; j++) {
        if (mark[j]) mark[j]--;
        if (mark[j] < 1) tot++;
      }
      continue;
    } else {
      tot = 0;
      p = a[i].k;
      int sum = 0;
      for (int j = 1; j <= n; j++) {
        if (mark[j] == 0 && p != 0) {
          mark[j] = a[i].d;
          sum += j;
          p--;
        }
        if (mark[j]) mark[j]--;
        if (mark[j] < 1) tot++;
      }
      printf("%d\n", sum);
    }
  }
  return 0;
}
