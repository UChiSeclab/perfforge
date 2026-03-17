#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
double calcArea(int a, int b, int c) {
  const double p = static_cast<double>(a + b + c) / 2.0;
  try {
    return sqrt(p * (p - a) * (p - b) * (p - c));
  } catch (exception& e) {
    return 0;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, inc = 0;
  cin >> a >> b >> c;
  if (calcArea(a, b, c) == 0) {
    inc = 100 * 3;
    for (int ai = a; ai <= 100; ai++) {
      for (int bi = b; bi <= 100; bi++) {
        for (int ci = c; ci <= 100; ci++) {
          if (calcArea(ai, bi, ci) > 0)
            inc = min(inc, (ai - a) + (bi - b) + (ci - c));
        }
      }
    }
  }
  cout << inc;
}
