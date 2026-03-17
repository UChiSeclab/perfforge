#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int m, b, i, x, curr, ma = 0, tot, j;
  cin >> m >> b;
  for (i = 0; i <= b; i++) {
    x = m * (b - i);
    tot = 0;
    for (j = i; j >= 0; j--) {
      curr = x * (x + 1);
      curr /= 2;
      curr += (x + 1) * j;
      tot += curr;
    }
    ma = max(tot, ma);
  }
  cout << ma;
  return 0;
}
