#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
int main() {
  cin >> a >> b >> c >> d;
  double res = 0.0;
  int x;
  double lst = 2.0;
  int i = 0;
  while (!(abs(lst - res) < 1e-12)) {
    lst = res;
    res +=
        pow(1.0 - (a / b), i) * pow(1.0 * (a / b), 1) * pow(1.0 - (c / d), i);
    i++;
  }
  printf("%.12f\n", res);
  return 0;
}
