#include <bits/stdc++.h>
using namespace std;
long long p = 1000000007;
long long fac[100000];
long long coeff[5005][5005];
long long power(long long x, long long y, long long p) {
  p = 1000000007;
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) {
  p = 1000000007;
  return power(n, p - 2, p);
}
long long nCrModPFermat(long long n, long long r, long long p) {
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  long long n, k;
  cin >> n >> k;
  p = 1000000007;
  long long fuck = 0;
  coeff[0][0] = 1;
  if (n < k) {
    long long aaa = 0;
    for (long long i = 0; i < n + 1; i++) {
      aaa = (aaa + (nCrModPFermat(n, i, p) * power(i, k, p)) % 1000000007) %
            1000000007;
    }
    cout << aaa;
    return 0;
  }
  for (long long i = 1; i < k + 5; i++) {
    for (long long j = 1; j < i + 1; j++) {
      coeff[i][j] = max(1LL, coeff[i][j]);
      coeff[i][j] = (coeff[i - 1][j] * j + coeff[i - 1][j - 1]) % 1000000007;
    }
  }
  for (long long i = 2; i < k + 1; i++) {
    long long temp = coeff[k][i];
    temp = (temp * power(2, n - i, p)) % 1000000007;
    for (long long j = 1; j < i; j++) {
      temp = (temp * (n - j) + 1000000007) % 1000000007;
    }
    fuck = (fuck + temp) % 1000000007;
  }
  fuck = (fuck + power(2, n - 1, p)) % 1000000007;
  fuck = (fuck * n) % 1000000007;
  cout << fuck << '\n';
}
