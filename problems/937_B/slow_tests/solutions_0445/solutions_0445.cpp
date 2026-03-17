#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long p, y;
  cin >> p >> y;
  long long ans = -1;
  for (long long i = y; i >= 2; i--) {
    if (i <= p or y - i > 300) break;
    long long cnt = 0;
    for (long long j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        if ((j >= 2 and j <= p) or (i / j >= 2 and i / j <= p)) cnt++;
      }
    }
    if (cnt == 0) {
      ans = max(i, ans);
    }
  }
  cout << ans;
  return 0;
}
