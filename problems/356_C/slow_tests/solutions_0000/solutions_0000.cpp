#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
signed main() {
  long long N;
  cin >> N;
  vector<long long> cnt(5);
  long long sum = 0;
  for (long long i = 0; i < (N); i++) {
    long long c;
    cin >> c;
    cnt[c]++;
    sum += c;
  }
  long long ans = LLONG_MAX;
  for (long long x = 0; x * 3 <= sum; x++) {
    if ((sum - 3 * x) % 4) continue;
    long long y = (sum - 3 * x) / 4;
    vector<long long> a = cnt;
    long long val = 0;
    if (a[4] >= y) {
      long long t = a[4] - y;
      val += t;
      a[3] += t;
      if (x - a[3] <= a[2])
        val += (a[2] - (x - a[3])) * 2 + a[1];
      else
        val += max(0ll, a[1] - (x - a[3] - a[2]));
    } else {
      if (a[4] + a[3] >= x + y) {
        val = a[1] + a[2] * 2 + (a[4] + a[3] - x - y) * 3;
      } else if (a[4] + a[3] + a[2] >= x + y)
        val = a[1] + (a[4] + a[3] + a[2] - x - y) * 2;
      else
        val = a[4] + a[3] + a[2] + a[1] - x - y;
    }
    chmin(ans, val);
  }
  if (ans == LLONG_MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
