#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, i, j;
  cin >> a >> b >> c;
  bool flag = true;
  for (i = 0; i <= 10000 && flag == true; i++) {
    for (j = 0; j <= 10000 && flag == true; j++) {
      if ((i * a + j * b) == c) {
        cout << "Yes" << endl;
        flag = false;
      }
    }
  }
  if (flag == true) cout << "No" << endl;
  return 0;
}
