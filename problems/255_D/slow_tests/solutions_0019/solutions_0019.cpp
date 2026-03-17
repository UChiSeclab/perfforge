#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, c;
  while (cin >> n >> x >> y >> c) {
    long long r[4] = {y - 1, x - 1, n - y, n - x};
    long long t = 0;
    long long cnt = 1;
    for (;;) {
      for (int i = 0; i < 4; i++) {
        cnt +=
            t - min(max(0LL, t - r[i]) + max(0LL, t - 1 - r[(i + 1) % 4]), t);
      }
      if (cnt >= c) break;
      ++t;
    }
    cout << t << endl;
  }
}
