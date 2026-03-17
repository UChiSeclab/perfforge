#include <bits/stdc++.h>
using namespace std;
double const EPS = 1.0E-9;
int const MOD = (int)1e9 + 7;
inline void read(char* s) { scanf("%s", s); }
inline void read(int& x) { scanf("%d", &(x)); }
inline void read(long long& x) { scanf("%lld", &x); }
inline void read(double& x) { scanf("%lf", &x); }
inline void writeln(int x) { printf("%d\n", x); }
inline void writeln(long long x) { printf("%lld\n", x); }
inline void writeln(double x) { printf("%.12f\n", x); }
template <typename... T>
void read(T&... args) {
  using swallow = int[];
  swallow w = {0, (read(args), 0)...};
}
inline long long gcd(long long x, long long y) {
  return y == 0 ? x : gcd(y, x % y);
}
inline long long lcm(long long x, long long y) {
  return x == 0 && y == 0 ? 0 : x / gcd(x, y) * y;
}
inline long long powmod(long long x, long long n, long long m = MOD) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * x) % m;
    x = (x * x) % m;
    n /= 2;
  }
  return r;
}
static int leap(int y) { return y % 4 == 0 && y % 100 != 0 || y % 400 == 0; }
static int const month[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
static const int N = 1 << 18;
static const int M = 1 << 20;
int freq[N];
int n, k;
int f[N];
int h[12];
int hw[5012][512];
static int solve() {
  read(n, k);
  for (int i = 1; i <= n * k; ++i) {
    int a;
    read(a);
    freq[a]++;
  }
  for (int i = 1; i <= n; ++i) {
    int x;
    read(x);
    f[x]++;
  }
  for (int i = 1; i <= k; ++i) {
    read(h[i]);
  }
  for (int i = 0; i < 5012; ++i) {
    for (int j = 0; j < 512; ++j) {
      if (i == 0 || j == 0) {
        hw[i][j] = 0;
      } else {
        hw[i][j] = 0;
        for (int l = 0; l <= k && l <= i; ++l) {
          hw[i][j] = std::max(hw[i][j], hw[i - l][j - 1] + h[l]);
        }
      }
    }
  }
  long long ans = 0;
  for (int i = (0), vzq_b = (N); i < vzq_b; ++i) {
    int fa = f[i];
    ans += hw[freq[i]][fa];
  }
  writeln(ans);
  return 0;
}
int main(int argc, char* argv[]) {
  solve();
  return 0;
}
