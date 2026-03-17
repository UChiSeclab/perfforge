#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  string s;
  cin >> a >> b >> s;
  int dx = 0, dy = 0;
  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == 'R') {
      dx++;
    } else if (s[i] == 'L') {
      dx--;
    } else if (s[i] == 'U') {
      dy++;
    } else if (s[i] == 'D') {
      dy--;
    }
  }
  int k = 0;
  if (dx != 0 && dy != 0) {
    int n1 = a / dx;
    int n2 = b / dy;
    k = max(n1, n2);
  }
  if (dx == 0 && dy != 0) {
    k = max(0, b / dy);
  }
  if (dy == 0 && dx != 0) {
    k = max(a / dx, 0);
  }
  k = max(0, k - 21000);
  a -= k * dx;
  b -= k * dy;
  dx = 0, dy = 0;
  for (int i = 1; i <= 32000; i++) {
    for (int i = 0; i < (int)s.length(); i++) {
      if (dx == a && dy == b) {
        cout << "Yes"
             << "\n";
        return 0;
      }
      if (s[i] == 'R') {
        dx++;
      } else if (s[i] == 'L') {
        dx--;
      } else if (s[i] == 'U') {
        dy++;
      } else if (s[i] == 'D') {
        dy--;
      }
      if (dx == a && dy == b) {
        cout << "Yes"
             << "\n";
        return 0;
      }
    }
  }
  cout << "No"
       << "\n";
}
