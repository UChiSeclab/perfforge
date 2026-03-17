#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, piece = 0, i, j, k;
  cin >> n >> a >> b >> c;
  if (a == 1 || b == 1 || c == 1)
    piece = n;
  else {
    for (i = 0; i <= n / a; i++) {
      for (j = 0; j <= (n - i * a) / b; j++) {
        for (k = 0; k <= (n - i * a - j * b) / c; k++) {
          if (i * a + j * b + k * c == n) piece = max(piece, i + j + k);
        }
      }
    }
  }
  cout << piece;
  return 0;
}
