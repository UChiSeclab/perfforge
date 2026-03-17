#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i = 0;
  double a, b, c, d;
  double r, o, ans = 0;
  cin >> a >> b >> c >> d;
  r = (a) / b;
  o = (c) / d;
  for (i = 0;; i++) {
    if ((pow((1 - r), i) * pow((1 - o), i)) < pow(10, -6))
      goto out;
    else
      ans += r * pow((1 - r), i) * pow((1 - o), i);
  }
out:
  printf("%.12lf\n", ans);
  return 0;
}
