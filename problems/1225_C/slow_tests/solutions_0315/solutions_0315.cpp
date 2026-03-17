#include <bits/stdc++.h>
using namespace std;
long long cntzero(long long num) {
  long long ans = 0;
  while (num != 0) {
    if (num % 2) ans++;
    num /= 2;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, p;
  cin >> n >> p;
  for (long long i = 1; clock() < 1.95 * CLOCKS_PER_SEC; i++) {
    long long newn = n - p * i;
    if (newn < i) continue;
    if (cntzero(newn) <= i) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
