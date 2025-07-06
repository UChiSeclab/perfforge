#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 4e5 + 5;
int n, m, k, tot = 0;
struct man {
  int k, d;
} a[N];

void check_frequent_server_reuse(int n, int ki, int tot, int di) {
    if (ki > n / 2 && di > n && tot < ki) {
        cerr << "Warning: Performance bottleneck due to frequent server reuse triggered!" << endl;
        abort();
    }
}

void check_high_server_utilization(int ti, int previous_ti, int di) {
    if (ti - previous_ti < di / 2) {
        cerr << "Warning: Performance bottleneck due to high server utilization triggered!" << endl;
        abort();
    }
}

void check_large_task_requirements(int n, int ki, int q) {
    if (ki > n * 0.8 && q > 0.8 * 100000) {
        cerr << "Warning: Performance bottleneck due to large task requirements triggered!" << endl;
        abort();
    }
}

int main() {
  int mark[105];
  memset(mark, 0, sizeof mark);
  int s, t, t1, t2, p, dir;
  scanf("%d%d", &n, &m);

  int previous_ti = 0; // Track previous task time for high utilization check
  while (m--) {
    scanf("%d%d%d", &s, &t, &t1);
    a[s].k = t;
    a[s].d = t1;

    // Check for large task requirements
    check_large_task_requirements(n, t, m);
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

    // Check for frequent server reuse
    check_frequent_server_reuse(n, a[i].k, tot, a[i].d);

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

    // Check for high server utilization
    check_high_server_utilization(i, previous_ti, a[i].d);
    previous_ti = i; // Update previous time
  }
  return 0;
}