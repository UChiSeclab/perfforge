#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int powe(long long int n, long long int m) {
  if (m == 0) return 1;
  long long int t = powe(n, m / 2);
  if (m % 2 == 0) return (t * t);
  return (((t * t)) * n);
}
long long int mpowe(long long int n, long long int m) {
  if (m == 0) return 1;
  long long int t = powe(n, m / 2);
  t %= 15000000;
  if (m % 2 == 0) return (t * t) % 15000000;
  return (((t * t) % 15000000) * n) % 15000000;
}
long long int logtwo(long long int n) {
  if (n == 1) return 0;
  return logtwo(n / 2) + 1;
}
long long int binpow(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int A[100005];
long long int dp[10000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, i, j, f = 0;
  cin >> n;
  long long int sum = 0, ans = 1e18, temp, x;
  double y;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  ;
  sort(a, a + n);
  if (n >= 63)
    x = 1;
  else {
    y = 18.0000 / (n - 1);
    y = pow(10, y);
    x = (int)y;
    if (n == 3) x = 10000000;
  }
  for (i = 1; i <= x; i++) {
    sum = 0;
    for (j = 0; j < n; j++) {
      sum += abs(a[j] - powe(i, j));
    }
    ans = min(ans, sum);
  }
  cout << ans;
  return 0;
}
