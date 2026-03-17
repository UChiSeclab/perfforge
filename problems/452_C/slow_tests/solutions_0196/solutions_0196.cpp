#include <bits/stdc++.h>
using namespace std;
double pr(double a, double n, double m) {
  double u = 1.0;
  for (int i = 0; i < a; i++) u *= (m - i) / (m * n - i);
  for (int i = 0; i < n - a; i++) u *= (m * n - m - i) / (m * n - a - i);
  for (int i = 0; i < a; i++) {
    u *= (n - i) / (a - i);
  }
  return u;
}
int main() {
  double n;
  double m;
  cin >> n >> m;
  double p = 0;
  for (double i = 1; i <= m; i++) {
    p += i * i / n * pr(i, n, m);
  }
  cout << p;
  return 0;
}
