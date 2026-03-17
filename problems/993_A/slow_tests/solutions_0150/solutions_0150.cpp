#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using namespace std;
using f64 = double;
f64 sq_norm[2][4], sq_tilt[2][4];
f64 area_norm, area_tilt;
static f64 tri_area(f64 ax, f64 ay, f64 bx, f64 by, f64 cx, f64 cy) {
  return abs((ax - bx) * (cy - by) - (ay - by) * (cx - bx)) / 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  f64 an, at;
  for (int i = 0; i < 4; ++i) cin >> sq_norm[0][i] >> sq_norm[1][i];
  for (int i = 0; i < 4; ++i) cin >> sq_tilt[0][i] >> sq_tilt[1][i];
  area_tilt = tri_area(sq_tilt[0][0], sq_tilt[1][0], sq_tilt[0][1],
                       sq_tilt[1][1], sq_tilt[0][2], sq_tilt[1][2]);
  area_tilt += tri_area(sq_tilt[0][0], sq_tilt[1][0], sq_tilt[0][3],
                        sq_tilt[1][3], sq_tilt[0][2], sq_tilt[1][2]);
  area_norm += tri_area(sq_norm[0][0], sq_norm[1][0], sq_norm[0][1],
                        sq_norm[1][1], sq_norm[0][2], sq_norm[1][2]);
  area_norm += tri_area(sq_norm[0][0], sq_norm[1][0], sq_norm[0][3],
                        sq_norm[1][3], sq_norm[0][2], sq_norm[1][2]);
  for (f64 x = -100; x <= 100; x += 0.25)
    for (f64 y = -100; y <= 100; y += 0.25) {
      an = at = 0;
      for (int i = 0; i < 4; ++i) {
        an += tri_area(x, y, sq_norm[0][i], sq_norm[1][i],
                       sq_norm[0][(i + 1) % 4], sq_norm[1][(i + 1) % 4]);
        at += tri_area(x, y, sq_tilt[0][i], sq_tilt[1][i],
                       sq_tilt[0][(i + 1) % 4], sq_tilt[1][(i + 1) % 4]);
      }
      if (abs(an - area_norm) < 1e-9 && abs(at - area_tilt) < 1e-9) {
        cout << "YES" << endl;
        return 0;
      }
    }
  cout << "NO" << endl;
  return 0;
}
