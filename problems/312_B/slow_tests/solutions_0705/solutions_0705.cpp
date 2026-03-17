#include <bits/stdc++.h>
using namespace std;
int main() {
  float a, b, c, d;
  cin >> a >> b >> c >> d;
  double ps = a / b, pz = c / d, pw = 0;
  double nps = 1 - ps, npz = 1 - pz;
  for (int i = 0;; i++) {
    double k = pow(nps, i) * pow(npz, i) * ps;
    pw += k;
    if (k < 0.0000000000001) break;
  }
  printf("%.12f", pw);
}
