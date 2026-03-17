#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, b;
  cin >> m >> b;
  long long c = b * m;
  long long ans = 0;
  for (long long i = 0; i <= c; i++) {
    long long y = b - ceil(i * 1.0 / m);
    long long cur = i * (i + 1) / 2 * (y + 1) + y * (y + 1) / 2 * (i + 1);
    ans = max(ans, cur);
  }
  cout << ans << endl;
}
