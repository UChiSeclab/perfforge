#include <bits/stdc++.h>
int k, n[3], t[3];
int c[3];
int d[3];
int a[10000];
int b[10000];
int inf = 100000000;
int main() {
  while (scanf("%d%d%d%d%d%d%d", &k, n, n + 1, n + 2, t, t + 1, t + 2) != EOF) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int now = 0;
    int temp = t[0];
    int temp2;
    while (1) {
      now += temp;
      temp2 = inf;
      for (int i = 0; i < k; i++)
        if (a[i] < 3) {
          if (temp + b[i] >= t[a[i]]) {
            if (!b[i] && c[a[i]] == n[a[i]]) {
              temp2 = (t[a[i]] - b[i] < temp2 ? t[a[i]] - b[i] : temp2);
              continue;
            }
            if (!b[i]) c[a[i]]++;
            d[a[i]]++;
            b[i] += temp - t[a[i]];
            a[i]++;
            if (b[i]) {
              if (c[a[i]] < n[a[i]])
                c[a[i]]++;
              else
                b[i] = 0;
            }
          } else if (b[i])
            b[i] += temp;
          else if (c[a[i]] < n[a[i]]) {
            c[a[i]]++;
            b[i] = temp;
          }
          if (a[i] < 3)
            temp2 = (t[a[i]] - b[i] < temp2 ? t[a[i]] - b[i] : temp2);
        }
      if (temp2 == inf) break;
      for (int i = 0; i < 3; i++) {
        c[i] -= d[i];
        d[i] = 0;
      }
      temp = temp2;
    }
    printf("%d\n", now);
  }
}
