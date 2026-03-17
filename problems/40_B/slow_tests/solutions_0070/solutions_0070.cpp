#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed;
  cout.precision(9);
  int n, m, x;
  cin >> n >> m >> x;
  n -= 2 * (x - 1);
  m -= 2 * (x - 1);
  if (n <= 0 || m <= 0) {
    cout << 0 << "\n";
  } else {
    int r = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
          if ((i + j) % 2 == 0) {
            r++;
          }
        }
    cout << r << "\n";
  }
  return 0;
}
