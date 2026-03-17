#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 11;
const int MAXN = maxn;
const long long oo = 0x3f3f3f3f3f3f3f3f;
const long long ooo = 0x3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int to[maxn << 1], nxt[maxn << 1];
long long cost[maxn << 1], cap[maxn << 1], flow[maxn << 1];
int head[maxn], tot;
void init() {
  memset(head, -1, sizeof head);
  tot = 0;
}
void add(int u, int v, long long c, long long w) {
  to[tot] = v;
  cap[tot] = c;
  flow[tot] = 0;
  cost[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
  swap(u, v);
  to[tot] = v;
  cap[tot] = 0;
  flow[tot] = 0;
  cost[tot] = -w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
struct QUEUE {
  int que[maxn];
  int front, rear;
  void init() { front = rear = 0; }
  void push(int x) { que[rear++] = x; }
  int pop() { return que[front++]; }
  bool empty() { return front == rear; }
} que;
int n, m, s, t;
bool vis[maxn];
long long pre[maxn], dis[maxn];
bool spfa() {
  que.init();
  memset(vis, 0, sizeof vis);
  memset(pre, -1, sizeof pre);
  memset(dis, 0x3f, sizeof dis);
  que.push(s);
  vis[s] = 1;
  dis[s] = 0;
  while (!que.empty()) {
    int u = que.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = nxt[i]) {
      long long v = to[i], c = cap[i], f = flow[i], w = cost[i];
      if (c > f && dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        pre[v] = i;
        if (!vis[v]) {
          que.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  if (dis[t] == oo)
    return 0;
  else
    return 1;
}
long long mcmf() {
  long long mc = 0, mf = 0;
  while (spfa()) {
    long long tf = oo + 1;
    for (int i = pre[t]; ~i; i = pre[to[i ^ 1]]) {
      tf = min(tf, cap[i] - flow[i]);
    }
    mf += tf;
    for (int i = pre[t]; ~i; i = pre[to[i ^ 1]]) {
      flow[i] += tf;
      flow[i ^ 1] -= tf;
    }
    mc += dis[t] * tf;
  }
  return mc;
}
int a[MAXN], b[MAXN];
bool type[MAXN];
char str[MAXN];
int main() {
  int A, B;
  while (cin >> A >> B) {
    for (int i = 1; i <= A; i++) {
      scanf("%s", str + 1);
      a[i] = read();
      if (str[1] == 'A')
        type[i] = 1;
      else
        type[i] = 0;
    }
    for (int i = 1; i <= B; i++) b[i] = read();
    long long mx = 0;
    init();
    s = 2 * A + B + 1;
    t = s + 1;
    int ss = t + 1;
    n = ss;
    for (int j = 1; j <= B; j++) add(ss, j, 1, 0);
    for (int j = 1; j <= A; j++) add(B + j, B + A + j, 1, -2ll * ooo);
    for (int j = 1; j <= A; j++) add(B + A + j, t, 1, 0);
    for (int j = 1; j <= B; j++) {
      for (int k = 1; k <= A; k++) {
        if (type[k] == 0 && b[j] > a[k])
          add(j, B + k, 1, ooo);
        else if (type[k] == 1 && b[j] >= a[k])
          add(j, B + k, 1, ooo - (b[j] - a[k]));
      }
    }
    for (int j = 1; j <= B; j++) add(j, t, 1, ooo - b[j]);
    add(s, ss, 666, 0);
    for (int i = 1; i <= B; i++) {
      for (int i = 0; i <= tot - 1; i++) flow[i] = 0;
      cap[tot - 2] = i;
      long long mc = mcmf();
      if (i <= A) {
        mc += ooo * i;
        mc = -mc;
      } else {
        mc += ooo * A;
        mc -= ooo * (i - A);
        mc = -mc;
      }
      mx = max(mx, mc);
    }
    printf("%lld\n", (long long)(mx));
  }
  return 0;
}
