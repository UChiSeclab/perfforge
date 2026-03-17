#include <bits/stdc++.h>
using namespace std;
int i;
int main() {
  int n, a, b, c, best = 0;
  cin >> n >> a >> b >> c;
  for (i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int x, y, z;
      x = a * i, y = j * b, z = n - x - y;
      if (z % c == 0 && z > 0) {
        best = max(best, i + j + (z / c));
      }
      if ((a * i + b * j) == n) best = max(best, i + j);
    }
  }
  cout << best;
}
