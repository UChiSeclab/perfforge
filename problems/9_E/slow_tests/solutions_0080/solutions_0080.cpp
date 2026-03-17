#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int deg[N], f[N], n, m;
int find(int x) {
  if (x != f[x]) return f[x] = find(f[x]);
  return x;
}
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1) {
    if (m == 0) {
      puts("YES\n1\n1 1");
      return 0;
    }
    if (m == 1) {
      puts("YES\n0");
      return 0;
    }
    return puts("NO");
  }
  for (int i = 1; i <= n; i++) f[i] = i;
  bool circle = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (find(x) != find(y))
      f[find(x)] = find(y);
    else
      circle = 1;
    deg[x]++;
    deg[y]++;
  }
  for (int i = 1; i <= n; i++)
    if (deg[i] > 2) return puts("NO");
  if (circle && m != n) return puts("NO");
  if (circle) {
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (find(i) != find(j)) return puts("NO");
  }
  puts("YES");
  vector<pair<int, int> > ans;
  while (m != n) {
    m++;
    bool ok = 0;
    for (int i = 1; i <= n && !ok; i++) {
      for (int j = i + 1; j <= n && !ok; j++) {
        if (find(i) != find(j) && deg[i] < 2 && deg[j] < 2) {
          f[find(i)] = find(j);
          deg[i]++;
          deg[j]++;
          ans.push_back(make_pair(i, j));
          ok = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (deg[i] == 1 && deg[j] == 1) {
        ans.push_back(make_pair(i, j));
        deg[i]++;
        deg[j]++;
      }
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
}
