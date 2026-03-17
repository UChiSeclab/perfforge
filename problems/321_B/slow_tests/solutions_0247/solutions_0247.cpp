#include <bits/stdc++.h>
using namespace std;
int output, d;
struct node {
  int from;
  int to;
  int w;
  int f;
  int num;
  int next;
} e[2000000];
int head[150000];
int vis[150000];
int dis[150000];
int pre[150000];
int path[150000];
struct node2 {
  char op[150];
  int val;
} a[15000];
int n, ss, tt, cont, nn, mm;
void add(int from, int to, int f, int w) {
  e[cont].from = from;
  e[cont].to = to;
  e[cont].f = f;
  e[cont].w = w;
  e[cont].num = cont;
  e[cont].next = head[from];
  head[from] = cont++;
}
int SPFA() {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= tt; i++) dis[i] = -0x3f3f3f3f;
  dis[ss] = 0;
  queue<int> s;
  s.push(ss);
  while (!s.empty()) {
    int u = s.front();
    s.pop();
    vis[u] = 0;
    for (int i = head[u]; i != -1; i = e[i].next) {
      int v = e[i].to;
      int w = e[i].w;
      int f = e[i].f;
      if (f && dis[v] < dis[u] + w) {
        dis[v] = dis[u] + w;
        pre[v] = u;
        path[v] = e[i].num;
        if (vis[v] == 0) {
          vis[v] = 1;
          s.push(v);
        }
      }
    }
  }
  if (d == 1) {
    if (dis[tt] >= 0)
      return 1;
    else
      return 0;
  } else {
    if (dis[tt] != -0x3f3f3f3f)
      return 1;
    else
      return 0;
  }
}
void Slove() {
  d++;
  int ans = 0;
  int maxflow = 0;
  while (SPFA() == 1) {
    int minn = 0x3f3f3f3f;
    for (int i = tt; i != ss; i = pre[i]) {
      minn = min(minn, e[path[i]].f);
    }
    for (int i = tt; i != ss; i = pre[i]) {
      e[path[i]].f -= minn;
      e[path[i] ^ 1].f += minn;
    }
    maxflow += minn;
    ans += dis[tt] * minn;
  }
  output = max(output, ans);
}
int xx[150000];
int main() {
  while (~scanf("%d%d", &nn, &mm)) {
    output = 0, d = 0;
    ss = nn + mm + 1;
    tt = nn + mm + 2;
    cont = 0;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= nn; i++) {
      scanf("%s%d", a[i].op, &a[i].val);
    }
    for (int i = 1; i <= mm; i++) scanf("%d", &xx[i]);
    for (int i = 1; i <= mm; i++) add(ss, i, 1, 0), add(i, ss, 0, 0);
    for (int i = 1; i <= nn; i++) add(i + mm, tt, 1, 0), add(tt, i + mm, 0, 0);
    for (int i = 1; i <= mm; i++) {
      int x = xx[i];
      for (int j = 1; j <= nn; j++) {
        if (a[j].op[0] == 'A' && x >= a[j].val) {
          add(i, j + mm, 1, x - a[j].val);
          add(j + mm, i, 0, -(x - a[j].val));
        }
      }
    }
    Slove();
    if (nn < mm) {
      ss = mm * 2 + 1;
      tt = ss + 1;
      cont = 0;
      memset(head, -1, sizeof(head));
      for (int i = 1; i <= mm; i++) add(ss, i, 1, 0), add(i, ss, 0, 0);
      for (int i = 1; i <= nn; i++)
        add(i + mm, tt, 1, 0), add(tt, i + mm, 0, 0);
      for (int i = nn + 1; i <= mm; i++)
        add(i + mm, tt, 1, 0), add(tt, i + mm, 0, 0);
      for (int i = 1; i <= mm; i++) {
        int x = xx[i];
        for (int j = 1; j <= nn; j++) {
          if (a[j].op[0] == 'A') {
            if (x >= a[j].val) {
              add(i, j + mm, 1, x - a[j].val);
              add(j + mm, i, 0, -(x - a[j].val));
            } else {
              add(i, j + mm, 1, -10000000);
              add(j + mm, i, 0, 10000000);
            }
          } else {
            if (x > a[j].val) {
              add(i, j + mm, 1, 0);
              add(j + mm, i, 0, 0);
            } else {
              add(i, j + mm, 1, -10000000);
              add(j + mm, i, 0, 10000000);
            }
          }
        }
        for (int j = nn + 1; j <= mm; j++) {
          add(i, j + mm, 1, xx[i]);
          add(j + mm, i, 0, -xx[i]);
        }
      }
      Slove();
    }
    printf("%d\n", output);
  }
}
