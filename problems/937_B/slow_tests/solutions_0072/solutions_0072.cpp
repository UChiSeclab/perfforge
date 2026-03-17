#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long p, y;
  cin >> p >> y;
  long long lim = min(p, (long long)sqrt(y));
  long long limi = min(1000LL, y - 1);
  for (long long i = 0; i < limi; i++) {
    bool ok = 1;
    if (y - i <= p) ok = 0;
    for (long long j = 2; j <= lim; j++) {
      if ((y - i) % j == 0) ok = 0;
    }
    if (ok) {
      cout << y - i;
      return 0;
    }
  }
  cout << -1 << endl;
}
