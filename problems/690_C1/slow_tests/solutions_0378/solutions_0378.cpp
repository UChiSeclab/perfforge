#include <bits/stdc++.h>
int pre[10010], ran[10010];
int m, n, p, q;
void init() {
  for (int i = 0; i < 10010; i++) {
    pre[i] = i;
    ran[i] = 1;
  }
}
int findd(int a) {
  while (a != pre[a]) {
    a = pre[a];
  }
  return a;
}
void unite(int a, int b) {
  int a1 = findd(a);
  int b1 = findd(b);
  if (a1 < b1) {
    pre[b1] = a1;
    ran[a1] += ran[b1];
  } else if (a1 > b1) {
    pre[a1] = b1;
    ran[b1] += ran[a1];
  }
}
int mapp[1010][1010], in[1010];
int main() {
  int m, n, p, q;
  while (scanf("%d%d", &m, &n) == 2) {
    init();
    memset(mapp, 0, sizeof(mapp));
    memset(in, 0, sizeof(in));
    while (n--) {
      scanf("%d%d", &p, &q);
      mapp[p][q] = 1;
      unite(p, q);
    }
    int sum = 0, flag = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++) {
        if (mapp[i][j]) {
          sum++;
        }
      }
    for (int i = 1; i <= m; i++)
      if (ran[i] == m) flag = 1;
    if (sum == m - 1 && flag == 1)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
