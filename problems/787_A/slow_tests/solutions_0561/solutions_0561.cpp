#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = 0, y = 0, p = 0;
  for (int i = 0; i < 10e7; i++) {
    if (b + a * x == d + c * y) {
      p = 1;
      break;
    } else if (b + a * x > d + c * y)
      y++;
    else if (b + a * x < d + c * y)
      x++;
  }
  if (p == 1)
    cout << b + a * x << endl;
  else
    cout << -1 << endl;
}
