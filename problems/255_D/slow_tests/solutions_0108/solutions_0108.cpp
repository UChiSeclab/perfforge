#include <bits/stdc++.h>
using namespace std;
long long ans;
long long x, y, n, t;
long long geit(long long u) {
  long long total = 2 * (u + 1) * u + 1;
  if (u > x - 1) {
    total -= (u + 1 - x) * (u + 1 - x);
    if (u > n + x - y) total += (u - n - x + y + 1) * (u - n - x + y) / 2;
  }
  if (u > y - 1) {
    total -= (u + 1 - y) * (u + 1 - y);
    if (u > x + y - 1) total += (u - x - y + 2) * (u - x - y + 1) / 2;
  }
  if (u > n - x) {
    total -= (u + x - n) * (u + x - n);
    if (u > n - x + y) total += (u - n + x - y) * (u - n + x - y + 1) / 2;
  }
  if (u > n - y) {
    total -= (u + y - n) * (u + y - n);
    if (u > 2 * n - x - y + 1)
      total += (u - 2 * n + x + y) * (u - 2 * n + x + y - 1) / 2;
  }
  return total;
}
int main() {
  while (cin >> n >> x >> y >> t) {
    long long mid = 0;
    while (geit(mid) < t) mid++;
    cout << mid << endl;
  }
  return 0;
}
