#include <bits/stdc++.h>
using namespace std;
double a, b, c, d, p1, np1, p2, np2, ans;
double prob_n(int n) { return powl(np1, n - 1) * powl(np2, n - 1) * p1; }
int main() {
  cin >> a >> b >> c >> d;
  p1 = a / b;
  p2 = c / d;
  np1 = 1.0 - p1;
  np2 = 1.0 - p2;
  a = prob_n(1);
  b = prob_n(2);
  ans += a + b;
  int j = 3;
  while (abs(a - b) > 0.0000000000001) {
    a = prob_n(j);
    ans += a;
    j++;
    swap(a, b);
  }
  cout << fixed << setprecision(12) << ans;
  return 0;
}
