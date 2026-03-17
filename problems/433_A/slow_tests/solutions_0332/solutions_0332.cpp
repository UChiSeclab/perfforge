#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, tmp;
  bool flag = false;
  cin >> n;
  int apple[n];
  for (int i = 0; i < n; i++) cin >> apple[i];
  x = apple[0];
  for (int i = 1; i < n; i++) {
    y = apple[i];
    for (int j = 1; j < n; j++) {
      if (j == i) continue;
      tmp = apple[j];
      if (x <= y)
        x += tmp;
      else
        y += tmp;
    }
    if (x == y) {
      cout << "YES" << endl;
      flag = true;
      break;
    } else {
      x = apple[0];
      flag = false;
    }
  }
  if (!flag) cout << "NO" << endl;
  return 0;
}
