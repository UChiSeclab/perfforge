#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int x, y;
  cin >> x >> y;
  int a = 0, b = 1;
  if (y == 0) {
    cout << "No";
    return 0;
  }
  while (1) {
    if (b < y) {
      a++;
      b++;
    } else if (a < x && a > 0) {
      a += 2;
    } else
      break;
  }
  if (a == x && y == b)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
