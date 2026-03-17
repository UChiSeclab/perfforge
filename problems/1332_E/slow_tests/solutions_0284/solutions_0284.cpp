#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353LL;
int kent, zuyg;
long long Solve1(int m);
long long Solve0(int m) {
  if (m == 1) return zuyg;
  static map<int, long long> cache;
  auto it = cache.find(m);
  if (it != cache.end()) return it->second;
  long long ans = 0;
  if (m % 2) {
    ans += (Solve0(1) * Solve0(m - 1)) % mod;
    ans += Solve1(1) * Solve1(m - 1);
  } else {
    ans += (Solve0(m / 2) * Solve0(m / 2)) % mod;
    ans += Solve1(m / 2) * Solve1(m / 2);
  }
  return cache[m] = (ans % mod);
}
long long Solve1(int m) {
  if (m == 1) return kent;
  static map<int, long long> cache;
  auto it = cache.find(m);
  if (it != cache.end()) return it->second;
  long long ans = 0;
  if (m % 2) {
    ans += (Solve0(1) * Solve1(m - 1)) % mod;
    ans += Solve1(1) * Solve0(m - 1);
  } else {
    ans += (Solve1(m / 2) * Solve0(m / 2)) % mod;
    ans += Solve0(m / 2) * Solve1(m / 2);
  }
  return cache[m] = (ans % mod);
}
long long Solve1(int n, int m);
long long Solve0(int n, int m) {
  static map<pair<int, int>, long long> cache;
  auto it = cache.find({n, m});
  if (it != cache.end()) return it->second;
  if (n == 1) return cache[{n, m}] = Solve0(m);
  int n1, n2;
  if (n % 2) {
    n1 = 1;
    n2 = n - 1;
  } else
    n1 = n2 = n / 2;
  long long ans = (Solve0(n1, m) * Solve0(n2, m)) % mod;
  ans += (Solve1(n1, m) * Solve1(n2, m)) % mod;
  return cache[{n, m}] = (ans % mod);
}
long long Solve1(int n, int m) {
  static map<pair<int, int>, long long> cache;
  auto it = cache.find({n, m});
  if (it != cache.end()) return it->second;
  if (n == 1) return cache[{n, m}] = Solve1(m);
  int n1, n2;
  if (n % 2) {
    n1 = 1;
    n2 = n - 1;
  } else
    n1 = n2 = n / 2;
  long long ans = (Solve0(n1, m) * Solve1(n2, m)) % mod;
  ans += (Solve1(n1, m) * Solve0(n2, m)) % mod;
  return cache[{n, m}] = (ans % mod);
}
long long Pow(long long a, long long p) {
  a %= mod;
  if (p == 0) return 1;
  if (p % 2) return (a * Pow(a, p - 1)) % mod;
  return Pow(a * a, p / 2);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  kent = (r + 1) / 2 - l / 2;
  zuyg = (r - l + 1) - kent;
  long long N = (n * (long long)m);
  if (N % 2LL == 0LL) {
    cout << (Pow(r - l + 1, N) - Solve1(n, m) + mod) % mod;
    return 0;
  }
  cout << Pow(r - l + 1, N);
}
