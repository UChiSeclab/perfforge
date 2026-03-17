#include <bits/stdc++.h>
using namespace std;
int main() {
  long int a2, a3, a5, a6, s = 0;
  cin >> a2 >> a3 >> a5 >> a6;
  while (1) {
    if (a2 > 0 and a5 > 0 and a6 > 0) {
      a2--;
      a5--;
      a6--;
      s += 256;
    } else
      break;
  }
  int mi1 = min(a2, a3);
  s += 32 * mi1;
  cout << s << endl;
  return 0;
}
