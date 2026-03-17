#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e5 + 55;
const int MOD = (int)1e9 + 7;
const double PI = 2 * acos(0.0);
const double EPS = 1e-7;
const int N = (int)1e5 + 5;
const long long INF = (long long)1e18;
int a[N];
int n;
bool overFlow(long long a, long long b) { return INF / a < b; }
long long f(long long x) {
  long long val = 1;
  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += abs(a[i] - val);
    if (overFlow(val, x)) return LLONG_MAX;
    val *= x;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  long long ans = LLONG_MAX;
  if (n <= 32) {
    for (int i = 1; i <= (int)1e5; ++i) {
      ans = min(ans, f(i));
    }
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) res += a[i] - 1;
  ans = min(ans, res);
  cout << ans;
  return 0;
}
