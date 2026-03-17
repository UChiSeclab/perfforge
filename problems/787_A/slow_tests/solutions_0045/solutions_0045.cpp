#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for (int i = 0; i < 9999; i++) {
    for (int j = 0; j < 9999; j++) {
      if (b + (a * i) == d + (c * j)) {
        cout << b + (a * i);
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
