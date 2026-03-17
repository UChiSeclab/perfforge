#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, p;
  cin >> n >> p;
  long long ans = 5 * 5000000;
  for (long long i = 1; i <= 5000000; i++) {
    long long left = n - p * i;
    if (left < 1)
      continue;
    else {
      long long k = __builtin_popcount(left);
      if (k <= i and left >= i) {
        cout << i;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
