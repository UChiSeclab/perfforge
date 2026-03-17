#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e6 + 10;
int a[N];
const int inf = 0x3f3f3f3f;
int dis[10010][1000];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + m);
  int g, r;
  scanf("%d %d", &g, &r);
  if (a[0] > g) {
    puts("-1");
  }
  memset(dis, 0x3f, sizeof dis);
  priority_queue<pii, vector<pii>, greater<pii> > q;
  q.push(pii(a[0] == g, a[0] % g));
  dis[0][a[0] % g] = (a[0] == g);
  register int u, d, first, tim, dst;
  for (; !q.empty();) {
    dst = q.top().first;
    first = q.top().second;
    q.pop();
    u = first / g;
    d = first % g;
    if (dis[u][d] > dst) {
      continue;
    }
    if (u > 0) {
      tim = d + a[u] - a[u - 1];
      if (tim == g) {
        if (dis[u - 1][0] > dst + 1) {
          dis[u - 1][0] = dst + 1;
          q.push(pii(dst + 1, (u - 1) * g));
        }
      }
      if (tim < g) {
        if (dis[u - 1][tim] > dst) {
          dis[u - 1][tim] = dst;
          q.push(pii(dst, (u - 1) * g + tim));
        }
      }
    }
    if (u + 1 < m) {
      tim = d + a[u + 1] - a[u];
      if (tim == g) {
        if (dis[u + 1][0] > dst + 1) {
          dis[u + 1][0] = dst + 1;
          q.push(pii(dst + 1, (u + 1) * g));
        }
      }
      if (tim < g) {
        if (dis[u + 1][tim] > dst) {
          dis[u + 1][tim] = dst;
          q.push(pii(dst, (u + 1) * g + tim));
        }
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < m; i++) {
    if (dis[i][0] != inf && n - a[i] <= g) {
      ans = min(ans, dis[i][0] * (g + r) + n - a[i]);
    }
  }
  if (ans == inf) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
