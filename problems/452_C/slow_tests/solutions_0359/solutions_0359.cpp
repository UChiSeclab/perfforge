#include <bits/stdc++.h>
using namespace std;
double cr(int n, int m) {
  double res = 0;
  for (int i = 1; i < m + 1; i++) {
    res += -log(i) + log(n - i + 1);
  }
  return res;
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    int mi = min(n, m);
    double ans = 0;
    for (int i = 1; i < mi + 1; i++) {
      double tem = 2 * (log(i) - log(n)) + log(n) + cr(m, i) +
                   cr((n - 1) * m, n - i) - cr(n * m, n);
      ans += exp(tem);
    }
    printf("%.9f\n", ans);
  }
  return 0;
}
