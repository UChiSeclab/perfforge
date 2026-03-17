#include <bits/stdc++.h>
using namespace std;
int main() {
  int k2, k3, k5, k6;
  int r = 0;
  cin >> k2 >> k3 >> k5 >> k6;
  while (1) {
    if (k2 != 0 && k5 != 0 && k6 != 0) {
      r = r + 256;
      k2--;
      k5--;
      k6--;
    }
    if (k2 != 0 && k3 != 0 && k5 == 0 || k2 != 0 && k3 != 0 && k6 == 0) {
      r = r + 32;
      k2--;
      k3--;
    }
    if (k2 == 0 || k3 == 0 && k5 == 0 || k3 == 0 && k6 == 0) break;
  }
  cout << r << endl;
}
