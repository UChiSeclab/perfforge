#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MN = 55;
int lab[MN], n, m, qu[MN];
pair<int, int> e[MN * MN];
vector<int> ke[MN];
bool mark[MN];
vector<pair<int, int> > ls;
vector<int> zero;
bool check() {
  for (int i = (1), _b = (n); i <= _b; i++) ke[i].clear();
  for (int i = (1), _b = (m); i <= _b; i++) {
    ke[e[i].first].push_back(e[i].second);
    ke[e[i].second].push_back(e[i].first);
  }
  if (m != n) return false;
  memset(mark, false, sizeof mark);
  int first = 1, last = 1;
  qu[1] = 1;
  mark[1] = true;
  while (first <= last) {
    int u = qu[first++];
    for (int i = 0, _a = (ke[u].size()); i < _a; i++) {
      int v = ke[u][i];
      if (mark[v]) continue;
      qu[++last] = v;
      mark[v] = true;
    }
  }
  if (last != n) return false;
  for (int i = (1), _b = (n); i <= _b; i++)
    if (ke[i].size() != 2) return false;
  return true;
}
int getRoot(int u) {
  if (lab[u] < 0)
    return u;
  else
    return lab[u] = getRoot(lab[u]);
}
void merge(int u, int v) {
  int x = lab[u] + lab[v];
  if (lab[u] < lab[v]) {
    lab[u] = x;
    lab[v] = u;
  } else {
    lab[v] = x;
    lab[u] = v;
  }
}
vector<pair<int, int> > res;
int deg[MN];
bool can() {
  if (check()) return true;
  bool ok = true;
  memset(deg, 0, sizeof deg);
  memset(lab, -1, sizeof lab);
  for (int i = (1), _b = (m); i <= _b; i++) {
    int u = e[i].first, v = e[i].second;
    ++deg[u];
    ++deg[v];
    u = getRoot(u);
    v = getRoot(v);
    if (u == v) {
      ok = false;
      break;
    }
    merge(u, v);
  }
  for (int i = (1), _b = (n); i <= _b; i++)
    if (deg[i] > 2) {
      ok = false;
      break;
    }
  return ok;
}
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    if (n == 1 && m == 0) {
      puts("YES");
      puts("1");
      puts("1 1");
      continue;
    }
    res.clear();
    for (int i = (1), _b = (n); i <= _b; i++) {
      ke[i].clear();
    }
    for (int i = (1), _b = (m); i <= _b; i++) {
      scanf("%d%d", &e[i].first, &e[i].second);
    }
    if (check()) {
      puts("YES");
      puts("0");
      continue;
    }
    if (!can()) {
      puts("NO");
      continue;
    }
    puts("YES");
    printf("%d\n", n - m);
    int need = n - m;
    for (int turn = (1), _b = (need); turn <= _b; turn++) {
      bool ok = false;
      for (int u = (1), _b = (n); u <= _b; u++) {
        for (int v = (u + 1), _b = (n); v <= _b; v++) {
          ++m;
          e[m] = make_pair(u, v);
          if (can()) {
            ok = true;
            break;
          } else
            --m;
        }
        if (ok) break;
      }
      printf("%d %d\n", e[m].first, e[m].second);
    }
  }
  return 0;
}
