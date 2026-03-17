#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  unsigned long long b, m, ans, x, tmp, tmp1, kq;
  cin >> m >> b;
  if (b == 1) {
    cout << (m * (m + 1)) / 2;
  } else {
    x = m;
    ans = 0;
    while (true) {
      if (x / m == b) {
        unsigned long long a = ((x * (x + 1)) / 2) % 1000000000000000000;
        ans = max(ans, a);
        ans %= 1000000000000000000;
        break;
      }
      tmp = x;
      tmp1 = b - (tmp / m);
      kq = 0;
      for (int i = tmp1; i >= 0; i--) {
        kq = (kq + (tmp * (tmp + 1)) / 2 + (tmp * i)) % 1000000000000000000;
      }
      kq = (kq + (tmp1 * (tmp1 + 1)) / 2) % 1000000000000000000;
      ans = max(ans, kq);
      ans %= 1000000000000000000;
      x += m;
    }
    cout << (ans + 1000000000000000000) % 1000000000000000000;
  }
}
