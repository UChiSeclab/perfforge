#include <bits/stdc++.h>
int n;
typedef struct {
  int c, cc, d, a[50];
} vertex;
vertex vs[50];
int dfs(int i, int k, int cc) {
  fprintf(stderr, "i = %d\n", i + 1);
  vertex *v = &vs[i];
  v->c = 1;
  v->cc = cc;
  for (int j = 0; j < n; j++) {
    fprintf(stderr, "j = %d\n", j + 1);
    if (v->a[j] && j != k) {
      int c = vs[j].c;
      if (c == 0) {
        if (dfs(j, i, cc)) return 1;
      } else if (c == 1) {
        return 1;
      }
    }
  }
  v->c = 2;
  return 0;
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  if (n == 1) {
    if (m == 0)
      puts("YES\n1\n1 1");
    else if (m == 1)
      puts("YES\n0");
    else
      puts("NO");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    vs[u].d++;
    vs[v].d++;
    if (n != 2 && vs[u].a[v]) {
      puts("NO");
      return 0;
    }
    vs[u].a[v] = vs[v].a[u] = 1;
  }
  if (n == 2 && m == 2) {
    if (vs[0].a[1] == 1 && !vs[0].a[0] && !vs[1].a[1])
      puts("YES\n0");
    else
      puts("NO");
    return 0;
  }
  int f = 1;
  for (int i = 0; i < n; i++) {
    fprintf(stderr, "i = %d d = %d\n", i + 1, vs[i].d);
    if (vs[i].d > 2) {
      puts("NO");
      return 0;
    }
    if (vs[i].d != 2) f = 0;
  }
  if (m == n && f) {
    puts("YES\n0");
    return 0;
  }
  int cc = 0;
  for (int i = 0; i < n; i++) {
    if (vs[i].c == 0) {
      fprintf(stderr, "i = %d cc = %d\n", i + 1, cc);
      if (dfs(i, -1, cc)) {
        puts("NO");
        return 0;
      }
      cc++;
    }
  }
  puts("YES");
  printf("%d\n", n - m);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (vs[i].cc != vs[j].cc && vs[i].d < 2 && vs[j].d < 2) {
        int cc = vs[j].cc;
        for (int k = 0; k < n; k++)
          if (vs[k].cc == cc) vs[k].cc = vs[i].cc;
        vs[i].d++;
        vs[j].d++;
        printf("%d %d\n", i + 1, j + 1);
      }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (vs[i].d == 1 && vs[j].d == 1) {
        vs[i].d++;
        vs[j].d++;
        printf("%d %d\n", i + 1, j + 1);
      }
  return 0;
}
