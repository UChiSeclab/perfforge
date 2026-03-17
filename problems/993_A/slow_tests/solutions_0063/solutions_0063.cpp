#include <bits/stdc++.h>
using namespace std;
struct thing {
  int x;
  int y;
  bool operator<(const thing &th) const {
    if (y < th.y) return true;
    if (y == th.y && x < th.x) return true;
    return false;
  }
} m[5], n[5];
int at(int x, int y, int a, int b, int c, int d) {
  long double K = 1.0 * (d - b) / (c - a);
  long double B = 1.0 * (c * b - a * d) / (c - a);
  if (fabs(K * x + B - y) <= 0.000001) return 0;
  if (K * x + B > y) return 1;
  if (K * x + B < y) return -1;
}
bool okn(int x, int y) {
  if (x >= m[1].x)
    if (y >= m[1].y)
      if (x <= m[4].x)
        if (y <= m[4].y) return true;
  return false;
}
bool okm(int x, int y) {
  if (x + y >= n[1].x + n[1].y)
    if (x + y <= n[4].x + n[4].y)
      if (y - x >= n[1].y - n[1].x)
        if (y - x <= n[4].y - n[4].x) return true;
  return false;
}
int main() {
  for (int i = 1; i <= 4; i++) cin >> m[i].x >> m[i].y;
  for (int i = 1; i <= 4; i++) cin >> n[i].x >> n[i].y;
  sort(m + 1, m + 5);
  sort(n + 1, n + 5);
  for (int i = 1; i <= 4; i++)
    if (okn(n[i].x, n[i].y)) {
      cout << "YES";
      return 0;
    }
  for (int i = 1; i <= 4; i++)
    if (okm(m[i].x, m[i].y)) {
      cout << "YES";
      return 0;
    }
  for (int i = -100; i <= 100; i++)
    for (int j = -100; j <= 100; j++)
      if (okm(i, j) && okn(i, j)) {
        cout << "YES";
        return 0;
      }
  cout << "NO";
  return 0;
}
