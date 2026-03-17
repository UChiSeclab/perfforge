#include <bits/stdc++.h>
const int N = 1e6 + 5;
int lowbit(int x) { return x & -x; }
struct Fenwick {
  int c[N];
  void update(int x, int y) {
    for (; x < N; x += lowbit(x)) c[x] += y;
  }
  int query(int x) {
    int answer = 0;
    for (; x > 0; x ^= lowbit(x)) answer += c[x];
    return answer;
  }
} bit;
int n, m;
std::vector<std::pair<int, int>> v[N];
struct que {
  int x, l, r;
} q[N];
bool cmp(que x, que y) { return x.x < y.x; }
int main() {
  int64_t answer = 1;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x, l, r;
    scanf("%d %d %d", &x, &l, &r);
    if (l == 0 && r == 1e6) ++answer;
    v[l].emplace_back(x, 1);
    v[r + 1].emplace_back(x, -1);
  }
  for (int i = 1; i <= m; i++) {
    int x, l, r;
    scanf("%d %d %d", &x, &l, &r);
    if (l == 0 && r == 1e6) ++answer;
    q[i] = {x, l, r};
  }
  std::sort(q + 1, q + m + 1, cmp);
  int cur = 0;
  for (int i = 1; i <= m; i++) {
    while (cur <= q[i].x) {
      for (auto j : v[cur]) {
        bit.update(j.first, j.second);
      }
      ++cur;
    }
    answer += bit.query(q[i].r) - bit.query(q[i].l - 1);
  }
  printf("%lld\n", answer);
  return 0;
}
