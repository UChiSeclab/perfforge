#include <bits/stdc++.h>
using namespace std;
long long m = 1000000007;
long long binpow(long long a, long long n) {
  if (n == 1) return a;
  if (n == 0) return 1;
  long long b = binpow(a, n / 2);
  return (((b * b) % m) * (binpow(a, n % 2))) % m;
}
signed main() {
  long long n, x;
  cin >> x >> n;
  vector<long long> pr;
  long long x1 = x;
  for (long long i = 2; i <= (long long)sqrt(x); ++i) {
    if (x1 % i != 0) continue;
    pr.push_back(i);
    while (x1 % i == 0) {
      x1 /= i;
    }
  }
  long long ans = 1;
  if (x1 != 1) pr.push_back(x1);
  for (auto p : pr) {
    long long n1 = n;
    while (n1 >= p) {
      n1 /= p;
      ans = (ans * (binpow(p, n1))) % m;
    }
  }
  cout << ans;
}
