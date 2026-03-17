#include <bits/stdc++.h>
using namespace std;
long long gauss(long long n) {
  if (n % 2 == 0)
    return n / 2 * (n + 1);
  else
    return n * (n + 1) / 2;
}
long long cb(int x, int y) { return (x + 1) * gauss(y) + (y + 1) * gauss(x); }
int main() {
  long long m, b;
  cin >> m >> b;
  long long X = m * b;
  long long res = 0;
  for (int i = 0; i <= X; i++) {
    int y = floor(((double)i / m) * (-1) + b);
    res = max(res, cb(i, y));
  }
  cout << res << endl;
}
