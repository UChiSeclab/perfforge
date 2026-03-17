#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
struct P {
  int x, y;
} point[41];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, maxx = INT_MIN, maxy = INT_MIN, minx = INT_MAX, miny = INT_MAX;
  cin >> n;
  for (auto i = (0); i < (4 * n + 1); ++i) {
    cin >> point[i].x >> point[i].y;
    maxx = max(maxx, point[i].x);
    maxy = max(maxy, point[i].y);
    minx = min(minx, point[i].x);
    miny = min(miny, point[i].y);
  }
  for (auto i1 = (minx); i1 < (maxx + 1); ++i1)
    for (auto i2 = (i1); i2 < (maxx + 1); ++i2)
      for (auto j1 = (miny); j1 < (maxy + 1); ++j1)
        for (auto j2 = (j1); j2 < (maxy + 1); ++j2) {
          P tmp;
          int cnt = 0;
          for (int k = 0; cnt <= 1 && k < 4 * n + 1; ++k)
            if ((i1 != point[k].x && i2 != point[k].x && j1 != point[k].y &&
                 j2 != point[k].y) ||
                i1 > point[k].x || i2 < point[k].x || j1 > point[k].y ||
                j2 < point[k].y) {
              tmp = point[k];
              ++cnt;
            }
          if (cnt == 1) {
            cout << tmp.x << ' ' << tmp.y;
            return 0;
          }
        }
}
