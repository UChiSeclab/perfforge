#include <bits/stdc++.h>
using namespace std;
int main() {
  long double e = 1, a, b, c, d, p, s;
  cin >> a >> b >> c >> d;
  s = (1 - a / b) * (1 - c / d);
  p = s;
  while (e > 0.000000000001) {
    long double h = p;
    p = p * s + s;
    e = p - h;
  }
  cout << (p + 1) * (a / b) << endl;
  return 0;
}
