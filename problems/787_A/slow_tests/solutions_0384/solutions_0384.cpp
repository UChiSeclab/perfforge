#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for (i = 0; i < 10000; i++) {
    for (j = 0; j < 10000; j++) {
      if (b + a * i == d + c * j) {
        cout << b + a * i << endl;
        return 0;
      }
    }
  }
  cout << "-1" << endl;
  return 0;
}
