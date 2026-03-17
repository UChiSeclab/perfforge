#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long m, b;
  long long ans = 0;
  cin >> m >> b;
  for (long long i = 0; i <= m * b; i++) {
    long long maxx = floor(-i * 1.0 / m) + b;
    ans = max(ans,
              (maxx + 1) * i * (i + 1) / 2 + maxx * (maxx + 1) * (i + 1) / 2);
  }
  cout << ans << endl;
  return 0;
}
