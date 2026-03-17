#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 3e6 + 9;
long long n, k;
long long two(long long x) {
  long long base = 1, ans = 0;
  while (base * x <= n) {
    long long f = min(n, base * (x + 1) - 1);
    ans += f - base * x + 1;
    base *= 2;
  }
  return ans;
}
long long one(long long x) {
  if (x % 2 == 0) return two(x + 1) + two(x);
  return two(x);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) {
    cin >> n >> k;
    long long N = n, ans = 1;
    while (N) {
      for (long long i = 0; i <= 10; i++) {
        if (i >= N) break;
        if (one(N - i) >= k) ans = max(ans, N - i);
      }
      N /= 2;
    }
    cout << ans << endl;
  }
  return 0;
}
