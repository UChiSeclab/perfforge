#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ld = long double;
const ld PI = acos(-1.0);
struct pnt {
  int x, y;
  bool read() {
    if (!(cin >> x >> y)) {
      return 0;
    }
    return 1;
  }
  int operator*(const pnt& p) const { return x * p.x + y * p.y; }
  int operator%(const pnt& p) const { return x * p.y - y * p.x; }
  pnt operator-(const pnt& p) const { return pnt{x - p.x, y - p.y}; }
  bool operator==(const pnt& p) const { return x == p.x && y == p.y; }
};
struct sq {
  vector<pnt> ps;
  bool read() {
    ps.resize(4);
    for (auto& p : ps) {
      if (!p.read()) {
        return 0;
      }
    }
    return 1;
  }
  bool inside(const pnt& p) const {
    ld sum = 0;
    for (int i = 0; i < int(int((ps).size())); ++i) {
      if (ps[i] == p) {
        return 1;
      }
      auto p1 = ps[i];
      auto p2 = ps[(i + 1) % int((ps).size())];
      p1 = p1 - p;
      p2 = p2 - p;
      if ((p1 % p2) == 0 && (p1 * p2) <= 0) {
        return 1;
      }
      ld ang = atan2(p1 % p2, p1 * p2);
      sum += ang;
    }
    sum = fabs(sum);
    return sum > PI;
  }
};
sq s1, s2;
bool read() {
  if (!s1.read()) {
    return 0;
  }
  s2.read();
  return 1;
}
bool solve() {
  for (int x = -100; x <= 100; ++x) {
    for (int y = -100; y <= 100; ++y) {
      if (s1.inside(pnt{x, y}) && s2.inside(pnt{x, y})) {
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  while (read()) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
