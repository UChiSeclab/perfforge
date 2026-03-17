#include <bits/stdc++.h>
using namespace std;
long long f(long long n) {
  for (int i = 2; i <= n; i++) {
    if (n % i == 0) {
      return i;
    }
  }
  return n;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  long long n, k;
  while (t--) {
    cin >> n >> k;
    long long ans = n;
    while (k--) {
      long long d = f(n);
      ans += f(n);
      n = ans;
      if (d == 2) {
        ans += k * 2ll;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
