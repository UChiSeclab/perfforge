#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, ans = 0;
  cin >> a >> b >> c >> d;
  while (true) {
    if (a != 0 and c != 0 and d != 0) {
      ans += 256;
      a--;
      c--;
      d--;
    } else if (a != 0 and b != 0) {
      ans += 32;
      a--;
      b--;
    } else {
      break;
    }
  }
  cout << ans;
}
