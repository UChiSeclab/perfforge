#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, n, k, ki;
  cin >> y >> k >> n;
  ki = k;
  while (k - y <= 0) k += ki;
  x = k - y;
  if (x + y > n) {
    cout << "-1" << endl;
    return 0;
  }
  while (x + y <= n) {
    cout << x << " ";
    k += ki;
    x = k - y;
  }
  cout << endl;
  return 0;
}
