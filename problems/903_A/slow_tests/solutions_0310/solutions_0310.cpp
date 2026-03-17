#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  vector<int> X(n);
  for (int i = 0; i < n; i++) {
    cin >> x;
    X[i] = x;
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
    flag = false;
    int num = X[i];
    for (int j = 0; j <= 100; j++) {
      for (int z = 0; z <= 100; z++) {
        if ((j * 3 + z * 7) == num) {
          flag = true;
          break;
        }
      }
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
