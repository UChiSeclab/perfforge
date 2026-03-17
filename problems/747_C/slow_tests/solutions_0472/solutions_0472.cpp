#include <bits/stdc++.h>
using namespace std;
struct unit {
  int t, k, d;
  int id;
  int ans;
} task[100010];
int server[111];
int n, q;
void init() { memset(server, 0, sizeof(server)); }
int cmp1(unit a, unit b) { return a.t < b.t; }
int cmp2(unit a, unit b) { return a.id < b.id; }
int main() {
  ios::sync_with_stdio(false);
  while (cin >> n >> q) {
    init();
    for (int i = 1; i <= q; i++)
      task[i].id = i, cin >> task[i].t >> task[i].k >> task[i].d;
    sort(task, task + q, cmp1);
    int x = 1;
    for (int i = 1; i <= 1010000; i++) {
      for (int j = 1; j <= n; j++)
        if (server[j]) server[j]--;
      if (x > q) continue;
      if (task[x].t != i) continue;
      int rest = 0;
      for (int j = 1; j <= n; j++)
        if (!server[j]) rest++;
      if (rest < task[x].k) {
        task[x].ans = -1;
      } else {
        task[x].ans = 0;
        for (int j = 1; j <= n; j++)
          if (!server[j] && task[x].k) {
            task[x].ans += j;
            server[j] = task[x].d;
            task[x].k--;
          }
      }
      x++;
    }
    sort(task, task + q, cmp2);
    for (int i = 1; i <= q; i++) cout << task[i].ans << endl;
  };
  return 0;
}
