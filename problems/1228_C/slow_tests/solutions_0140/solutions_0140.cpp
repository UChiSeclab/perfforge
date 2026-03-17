#include <bits/stdc++.h>
using namespace std;
long long powmod(long long p, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1) return (p * powmod(p, n - 1)) % 1000000007;
  long long z = powmod(p, n / 2);
  return (z * z) % 1000000007;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x, n;
  cin >> x >> n;
  set<long long> P;
  for (long long i = 2; i < 100000 && x > 1; ++i) {
    while (x % i == 0) {
      P.insert(i);
      x /= i;
    }
  }
  if (x > 1) P.insert(x);
  long long ans = 1;
  for (long long p : P) {
    long long a = 0;
    long long b = n;
    while (b) {
      b /= p;
      a += b;
      a %= (1000000007 - 1);
    }
    ans *= powmod(p, a);
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
