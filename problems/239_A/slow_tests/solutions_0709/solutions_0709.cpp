#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, i = 1, j, t = 0, s = 0;
  int x[1000];
  cin >> n >> m >> a;
  while (i * m <= n) i++;
  while (i * m + t <= a) {
    cout << i * m - n + t << " ";
    s = 1;
    t += m;
  }
  if (s == 0) cout << -1;
  return 0;
}
