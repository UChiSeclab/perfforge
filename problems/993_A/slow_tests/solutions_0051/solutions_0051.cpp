#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  void in() { scanf("%lf%lf", &x, &y); }
  bool operator<(const Point &X) const { return x == X.x ? y < X.y : x < X.x; }
};
Point operator-(const Point &X, const Point &Y) {
  return Point(X.x - Y.x, X.y - Y.y);
}
double det(Point X, Point Y) { return X.x * Y.y - X.y * Y.x; }
struct Node {
  Point P[4];
  void in() {
    for (signed i = 0; i < 4; i++) P[i].in();
    sort(P, P + 4);
  }
} T1, T2;
bool cross(Point X, Point Y, Point Z) { return det(Y - X, Z - X) <= 1e-6; }
bool c(double x, double y) {
  bool ta = 1;
  ta &= (T1.P[0].x <= x && x <= T1.P[3].x && T1.P[0].y <= y && y <= T1.P[3].y);
  Point X = Point(x, y);
  ta &= (cross(T2.P[0], T2.P[2], X) && cross(T2.P[0], X, T2.P[1]) &&
         cross(X, T2.P[2], T2.P[3]) && cross(X, T2.P[3], T2.P[1]));
  return ta;
}
signed main() {
  T1.in();
  T2.in();
  c(2, 5);
  for (double i = -100; i <= 100; i += 0.25)
    for (double j = -100; j <= 100; j += 0.25) {
      if (c(i, j)) {
        puts("YES");
        return 0;
      }
    }
  return puts("NO"), 0;
}
