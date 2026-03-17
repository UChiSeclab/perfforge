#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, b;
  cin >> m >> b;
  long long y = b;
  long long x = b * m;
  long long max1 = 0;
  for (long long iy = b; iy >= 0; iy--) {
    long long ix = m * (b - iy);
    long long sum = 0;
    long long sumx = (ix * (ix + 1)) / 2;
    for (long long j = iy; j >= 0; j--) {
      long long sumy = (ix + 1) * j;
      sum += sumx + sumy;
    }
    if (max1 < sum) max1 = sum;
  }
  cout << max1 << endl;
  return 0;
}
