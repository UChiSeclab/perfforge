#include <bits/stdc++.h>
const int inf = 1000000007;
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
struct edge {
  int t;
  edge *next;
} e[20005], *h[400005], *o = e;
void add(int x, int y) {
  o->t = y;
  o->next = h[x];
  h[x] = o++;
}
int n, m, _x, _y, S, ans, _v[400005];
bool v[400005];
queue<int> q;
void bfs(int S) {
  q.push(S);
  v[S]++;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (edge *j = h[t]; j; j = j->next)
      if (!v[j->t]) v[j->t]++, q.push(j->t);
  }
}
int bfs1(int S) {
  int s = 0;
  q.push(S);
  _v[S] = _x;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    s++;
    for (edge *j = h[t]; j; j = j->next)
      if (!v[j->t] && _v[j->t] != _x) _v[j->t] = _x, q.push(j->t);
  }
  return s;
}
int main() {
  n = read();
  m = read();
  S = read();
  for (int i = 1; i <= m; i++) {
    _x = read();
    _y = read();
    add(_x, _y);
  }
  bfs(S);
  _x = 0;
  while (1) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (!v[i]) {
        _x++;
        int t = bfs1(i);
        if (t > cnt) S = i, cnt = t;
      }
    if (!cnt) break;
    bfs(S);
    ans++;
  }
  return 0 * printf("%d\n", ans);
}
