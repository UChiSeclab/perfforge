#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x1, y1, x2, y2, r1, R1, r2, R2;
  cin >> x1 >> y1 >> r1 >> R1;
  cin >> x2 >> y2 >> r2 >> R2;
  x1 *= 10000;
  x2 *= 10000;
  y1 *= 10000;
  y2 *= 10000;
  r1 *= 10000;
  r2 *= 10000;
  R1 *= 10000;
  R2 *= 10000;
  vector<bool> good(4, true);
  long long dis = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
  for (long long int rad = r1; rad <= R1; ++rad) {
    if ((dis < (rad + r2) * (rad + r2)) && (dis > (rad - r2) * (rad - r2))) {
      good[2] = false;
    }
    if ((dis < (rad + R2) * (rad + R2)) && (dis > (rad - R2) * (rad - R2))) {
      good[3] = false;
    }
  }
  for (long long int rad = r2; rad <= R2; ++rad) {
    if ((dis < (rad + r1) * (rad + r1)) && (dis > (rad - r1) * (rad - r1))) {
      good[1] = false;
    }
    if ((dis < (rad + R1) * (rad + R1)) && (dis > (rad - R1) * (rad - R1))) {
      good[0] = false;
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; ++i) {
    if (good[i]) {
      ++ans;
    }
  }
  cout << ans;
  return 0;
}
