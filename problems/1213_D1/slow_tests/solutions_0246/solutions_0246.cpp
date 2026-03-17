#include <bits/stdc++.h>
using namespace std;
long long power(long long x, unsigned long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long modpow(long long x, unsigned int y, long long p) {
  long long res = 1;
  x = x % p;
  if (y == 0) return 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long exponentMod(long long A, long long B, long long C) {
  if (B == 0) return 1;
  if (A == 0) return 0;
  long long y;
  if (B % 2 == 0) {
    y = exponentMod(A, B / 2, C);
    y = (y * y) % C;
  } else {
    y = A % C;
    y = (y * exponentMod(A, B - 1, C) % C) % C;
  }
  return (long long)((y + C) % C);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
void modInverse(int a, int m) {
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    cout << "Inverse doesn't exist";
  else {
    int res = (x % m + m) % m;
    cout << "Modular multiplicative inverse is " << res;
  }
}
void SieveOfEratosthenes(int n) {
  bool sieve[n + 1];
  long long cnt = 0;
  memset(sieve, 0, sizeof(sieve));
  for (int p = 2; p * p <= n; p++) {
    if (!sieve[p]) {
      for (int i = 2 * p; i <= n; i += p) sieve[i] = p;
    }
  }
  for (int p = 2; p <= n; p++) {
    if (sieve[p]) cnt++;
  }
  cout << cnt;
}
int phi(unsigned int n) {
  float result = n;
  for (int p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      while (n % p == 0) n /= p;
      result *= (1.0 - (1.0 / (float)p));
    }
  }
  if (n > 1) result *= (1.0 - (1.0 / (float)n));
  return (int)result;
}
void start() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  start();
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long x = a[i];
    while (x > 0) {
      v.push_back(x);
      x /= 2;
    }
  }
  long long ans = LLONG_MAX;
  for (auto res : v) {
    vector<long long> cnt;
    for (long long i = 0; i < n; i++) {
      long long x = a[i];
      long long cur = 0;
      while (x > res) {
        x /= 2;
        cur++;
      }
      if (x == res) {
        cnt.push_back(cur);
      }
    }
    if (cnt.size() < k) {
      continue;
    }
    sort(cnt.begin(), cnt.end());
    long long sum = 0;
    for (long long i = 0; i < k; i++) sum += cnt[i];
    ans = min(ans, sum);
  }
  cout << ans << "\n";
}
