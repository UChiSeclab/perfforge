#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  int max = 0;
  cin >> n >> a >> b >> c;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int k = (n - (i * a + j * b)) / c;
      if ((k * c + i * a + j * b) == n && k >= 0) {
        int m = i + j + k;
        if (m > max) max = m;
      }
    }
  }
  cout << max;
  return 0;
}
