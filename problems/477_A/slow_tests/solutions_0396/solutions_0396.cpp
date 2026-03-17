#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x;
  long long y;
};
long long gcd(long long a, long long b) {
  return b == 0 ? a : a > b ? gcd(b, a % b) : gcd(a, b % a);
}
bool myfunc(struct node a, struct node b) {
  if (a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}
long long pow(long long a, long long b, long long int MOD) {
  int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > MOD) x %= MOD;
    }
    y = (y * y);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}
long long modInverse(long long a, long long int m) { return pow(a, m - 2, m); }
long long inverseArray(long long n, long long m) {
  vector<long long int> modInverse(n + 1, 0);
  modInverse[1] = 1;
  for (long long int i = 2; i <= n; i++) {
    modInverse[i] = (-(m / i) * modInverse[m % i]) % m + m;
  }
  return modInverse[n];
}
int main() {
  long long aa, b;
  cin >> aa >> b;
  long long i;
  long long mod = 1000000007;
  long long sum = 0;
  for (i = 1; i < b; i++) {
    long long first = ((i * b) % mod + i) % mod;
    long long k1 = (aa * first) % mod;
    long long p, d;
    long long m = (i * b) % mod;
    if (aa % 2 == 0) {
      p = aa / 2;
      p = (p * (aa - 1)) % mod;
      d = (p * m) % mod;
    } else {
      p = (aa - 1) / 2;
      p = (p * (aa)) % mod;
      d = (p * m) % mod;
    }
    long long s = (k1 + d) % mod;
    sum = (sum + s) % mod;
  }
  cout << sum << "\n";
  return 0;
}
