#include <bits/stdc++.h>
using namespace std;
int v[500010], st[500010], dr[500010], d[500010];
vector<int> poz[500010];
int main() {
  int n, c, maxx = 0;
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    poz[v[i]].push_back(i);
    st[i] = st[i - 1];
    if (v[i] == c) st[i]++;
    maxx = max(maxx, v[i]);
  }
  for (int i = n; i >= 1; i--) {
    dr[i] = dr[i + 1];
    if (v[i] == c) dr[i]++;
  }
  int sol = dr[1];
  for (int i = 1; i <= maxx; i++) {
    if (i == c) continue;
    if (poz[i].size() == 0) continue;
    d[poz[i][0]] = st[poz[i][0]] + 1;
    sol = max(sol, d[poz[i][0]] + dr[poz[i][0] + 1]);
    for (int j = 1; j < poz[i].size(); j++) {
      int pozz = poz[i][j];
      d[pozz] = max(st[pozz] + 1, d[poz[i][j - 1]] + 1);
      sol = max(sol, d[pozz] + dr[pozz + 1]);
    }
  }
  printf("%d", sol);
  return 0;
}
