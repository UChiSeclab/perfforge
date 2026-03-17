#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18;
const int MOD = 1e9 + 9;
const long double PI = atan(1.0) * 4L;
const int MAXINT = 1e5 + 1;
long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long sum = 0, GCD = 0;
  for (int i = 1; i < n; i++)
    sum += a[i] - a[i - 1], GCD = gcd(GCD, a[i] - a[i - 1]);
  long long ans = INFLL;
  for (int i = 1; i < sqrtl(GCD) + 1; i++)
    if (GCD % i == 0) {
      int p = i;
      ans = min(ans, sum / p - (n - 1));
      p = GCD / i;
      ans = min(ans, sum / p - (n - 1));
    }
  cout << ans << '\n';
  return 0;
}
