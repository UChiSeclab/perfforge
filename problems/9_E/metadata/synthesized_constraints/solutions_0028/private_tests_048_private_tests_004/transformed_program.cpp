#include <bits/stdc++.h>

// Performance checks
void check_dfs_invariant(int cc, int n) {
    if (cc > n / 2) {
        cerr << "Warning: dfs_invariant triggered - too many connected components!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int m, int n) {
    if (m < n / 4) {
        cerr << "Warning: nested_loop_invariant triggered - initial graph too sparse!" << endl;
        abort();
    }
}

void check_edge_count_invariant(int m, int n) {
    if (m == 1 && n > 10) {
        cerr << "Warning: edge_count_invariant triggered - low initial edge count!" << endl;
        abort();
    }
}

// Original program
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

  // Insert performance check after reading inputs
  check_edge_count_invariant(m, n);
  check_nested_loop_invariant(m, n);

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

  // Insert performance check after DFS and component counting
  check_dfs_invariant(cc, n);
  
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