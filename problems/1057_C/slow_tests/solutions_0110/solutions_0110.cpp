#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, k, d[N];
char c[N];
struct dt {
  int x, pre;
  inline __attribute__((always_inline)) dt(int x = 0, int pre = 0)
      : x(x), pre(pre) {}
};
queue<dt> q1, q2;
struct memt {
  int d[N][N];
  inline __attribute__((always_inline)) int& operator[](const dt u) {
    return d[u.x][u.pre];
  }
  inline __attribute__((always_inline)) void clear() {
    memset(d, 255, sizeof(d));
  }
} r[2];
inline __attribute__((always_inline)) void upd(dt u, int v, int a) {
  if (r[a][u] == -1) q2.push(u);
  if (v > r[a][u]) r[a][u] = v;
}
bool ex[N];
int main() {
  int s;
  scanf("%d%d%d", &n, &s, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &d[i]), ex[d[i]] = 1;
  if (d[s] >= k) return puts("0"), 0;
  scanf("%s", c + 1);
  for (int i = 1; i <= n; ++i) {
    if (c[i] == 'R')
      c[i] = 1;
    else if (c[i] == 'G')
      c[i] = 2;
    else if (c[i] == 'B')
      c[i] = 3;
    else
      exit(1);
  }
  c[0] = 0;
  int ans = 0;
  r[0].clear(), r[1].clear();
  upd(dt(s, 0), 0, 0), upd(dt(s, s), d[s], 0);
  q1.swap(q2);
  for (; ans <= n * n; ++ans) {
    int a = ans & 1;
    while (!q1.empty()) {
      dt u = q1.front();
      q1.pop();
      int v = r[a][u];
      if (v >= k) goto ed;
      if (u.x + 1 <= n) {
        dt nu = u;
        ++nu.x;
        upd(nu, v, a ^ 1);
        if (d[u.pre] < d[nu.x] && c[u.pre] != c[nu.x]) {
          nu.pre = nu.x;
          upd(nu, v + d[nu.x], a ^ 1);
        }
      }
      if (1 <= u.x - 1) {
        dt nu = u;
        --nu.x;
        upd(nu, v, a ^ 1);
        if (d[u.pre] < d[nu.x] && c[u.pre] != c[nu.x]) {
          nu.pre = nu.x;
          upd(nu, v + d[nu.x], a ^ 1);
        }
      }
    }
    q1.swap(q2);
    r[a].clear();
  }
ed:
  printf("%d\n", ans > n * n ? -1 : ans);
  return 0;
}
