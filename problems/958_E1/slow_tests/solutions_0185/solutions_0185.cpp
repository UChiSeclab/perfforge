#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
int R, B;
struct Point {
  int x, y;
  void read() { scanf("%d%d", &x, &y); }
  Point operator-(const Point &o) const { return (Point){x - o.x, y - o.y}; }
  int operator*(const Point &o) const { return x * o.y - y * o.x; }
} RP[maxn], BP[maxn];
bool intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
  if (((c - b) * (d - b)) * ((c - a) * (d - a)) > 0) return false;
  if (((a - c) * (b - c)) * ((a - d) * (b - d)) > 0) return false;
  return true;
}
int M[maxn];
bool used[maxn];
bool check(int p) {
  for (int i = 0; i < p; ++i)
    if (intersect(RP[i], BP[M[i]], RP[p], BP[M[p]])) return false;
  return true;
}
void dfs(int p) {
  if (p >= R) {
    throw 1;
  }
  for (int i = 0; i < R; ++i)
    if (!used[i]) {
      M[p] = i;
      used[i] = true;
      if (check(p)) {
        dfs(p + 1);
      }
      used[i] = false;
    }
}
int main() {
  scanf("%d%d", &R, &B);
  for (int i = 0; i < R; ++i) RP[i].read();
  for (int i = 0; i < B; ++i) BP[i].read();
  if (R != B) {
    printf("No\n");
    return 0;
  }
  try {
    dfs(0);
  } catch (int) {
    printf("Yes\n");
    return 0;
  }
  printf("No\n");
}
