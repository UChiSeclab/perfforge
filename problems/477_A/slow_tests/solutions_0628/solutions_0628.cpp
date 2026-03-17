#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
long long mul(long long a, long long b) {
  a %= mod, b %= mod;
  return a * b % mod;
}
long long add(long long a, long long b) {
  a %= mod, b %= mod;
  a += b, a %= mod;
  return a;
}
int main(int argc, char const *argv[]) {
  long long a, b;
  cin >> a >> b;
  long long res = 0;
  for (int(q) = (1); (q) < (int)(b); ++(q)) {
    res = add(res, mul(mul(q, b), a * (a + 1) / 2));
    res = add(res, a * q);
  }
  cout << res << endl;
  return 0;
}
