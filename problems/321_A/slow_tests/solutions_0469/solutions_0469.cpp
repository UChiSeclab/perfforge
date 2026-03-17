#include <bits/stdc++.h>
using namespace std;
long long int i, j, n, t, m, a, b, cof, k, arr[1000000], dx, dy, p, xx, yy;
string s, s2;
int main() {
  cin >> a >> b;
  cin >> s;
  n = s.length();
  for (i = 0; i < n; i++) {
    if (s[i] == 'U') dy++;
    if (s[i] == 'D') dy--;
    if (s[i] == 'R') dx++;
    if (s[i] == 'L') dx--;
  }
  if (dx != 0)
    k = a / dx;
  else
    k = 1000000000000;
  if (k < 0) k = 0;
  k++;
  if (dy != 0)
    p = b / dy;
  else
    p = 1000000000000;
  if (p < 0) p = 0;
  p++;
  m = min(k, p);
  if (m < 1000) m = 1000;
  xx = dx * m;
  yy = dy * m;
  for (i = 0; i < 1000; i++)
    for (j = n - 1; j >= 0; j--) {
      if ((xx == a) && (yy == b)) {
        cout << "Yes";
        return 0;
      }
      if (s[j] == 'U') yy--;
      if (s[j] == 'D') yy++;
      if (s[j] == 'R') xx--;
      if (s[j] == 'L') xx++;
      if ((xx == a) && (yy == b)) {
        cout << "Yes";
        return 0;
      }
    }
  cout << "No";
}
