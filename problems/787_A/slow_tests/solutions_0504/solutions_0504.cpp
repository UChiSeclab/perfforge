#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < 10000; j++) {
      if (j * c == b - d + i * a) {
        cout << b + a * i;
        return 0;
      }
    }
  }
  cout << "-1" << endl;
  return 0;
}
