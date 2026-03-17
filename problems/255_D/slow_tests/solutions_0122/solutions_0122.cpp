#include <bits/stdc++.h>
using namespace std;
long long n, x, y, ans = -1;
long long c;
long long maxx, maxy, minx, miny;
long long s;
int main() {
  cin >> n >> x >> y >> c;
  while (s < c) {
    ans++;
    maxx = x + ans;
    maxy = y + ans;
    minx = x - ans;
    miny = y - ans;
    s = 2 * ans * ans + (ans * 2 + 1);
    long long t1, t2, t3, t4;
    t1 = max(maxx - n, 0LL);
    t2 = max(maxy - n, 0LL);
    t3 = max(1 - minx, 0LL);
    t4 = max(1 - miny, 0LL);
    s -= t1 * t1;
    s -= t2 * t2;
    s -= t3 * t3;
    s -= t4 * t4;
    long long tt1, tt2, tt3, tt4;
    tt1 = max(t1 - (n + 1 - y), 0LL);
    tt2 = max(t1 - y, 0LL);
    tt3 = max(t3 - y, 0LL);
    tt4 = max(t3 - (n + 1 - y), 0LL);
    s += tt1 * (tt1 + 1LL) / 2LL;
    s += tt2 * (tt2 + 1LL) / 2LL;
    s += tt3 * (tt3 + 1LL) / 2LL;
    s += tt4 * (tt4 + 1LL) / 2LL;
  }
  cout << ans;
  return 0;
}
