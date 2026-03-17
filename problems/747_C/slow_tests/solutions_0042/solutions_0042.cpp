#include <bits/stdc++.h>
using namespace std;
int n, q;
set<int> a;
vector<int> t, k, d;
vector<set<int> > s;
set<pair<int, int> > task;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) a.insert(i + 1);
  k.resize(q);
  t = d = k;
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d", &t[i], &k[i], &d[i]);
    task.insert(pair<int, int>(t[i], i));
  }
  s.resize(q);
  while (((int)task.size())) {
    int u = task.begin()->second;
    task.erase(task.begin());
    if (u >= 0) {
      if (((int)a.size()) < k[u]) {
        printf("-1\n");
        continue;
      }
      int sum = 0;
      for (int i = 0; i < k[u]; ++i) {
        sum += *a.begin();
        s[u].insert(*a.begin());
        a.erase(a.begin());
      }
      printf("%d\n", sum);
      task.insert(pair<int, int>(t[u] + d[u], -u - 1));
    } else {
      u = -u - 1;
      a.insert(s[u].begin(), s[u].end());
      s[u].clear();
    }
  }
  return 0;
}
