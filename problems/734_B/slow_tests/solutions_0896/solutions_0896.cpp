#include <bits/stdc++.h>
using namespace std;
int k2, k3, k5, k6, s;
int f256(int suma) {
  k2--;
  k5--;
  k6--;
  return suma + 256;
}
int f32(int suma) {
  k2--;
  k3--;
  return suma + 32;
}
int main() {
  cin >> k2 >> k3 >> k5 >> k6;
  while (true) {
    if (k2 > 0 && k5 > 0 && k6 > 0) s = f256(s);
    if ((k5 == 0 || k6 == 0) && k2 > 0 && k3 > 0) s = f32(s);
    if (((k5 == 0 || k6 == 0) && k3 == 0) || k2 == 0) {
      cout << s;
      break;
    }
  }
  return 0;
}
