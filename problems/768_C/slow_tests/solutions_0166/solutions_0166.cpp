#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const long long INF = 1LL * inf * inf;
const double eps = 1e-9;
const long long md = 1e9 + 7;
const double EPS = 1e-5;
const long long maxll = std::numeric_limits<long long>::max();
template <typename name>
inline name sqr(name x) {
  return x * x;
}
long double log(long double base, long double n) { return log(n) / log(base); }
inline long long multmod(long long a, long long b, long long md) {
  if (!a) return 0;
  if (a % 2 == 1)
    return (multmod(a - 1, b, md) + b) % md;
  else
    return sqr(multmod(a / 2, b, md)) % md;
}
template <typename name>
inline name bpow(name base, long long exp, long long md = maxll) {
  if (exp == 0) return 1;
  if (exp % 2 == 1)
    return (base * bpow(base, exp - 1, md)) % md;
  else {
    name k = bpow(base, exp / 2, md);
    return (k * k) % md;
  }
}
unsigned char ccc;
inline void read(int &n) {
  n = 0;
  bool _minus = false;
  while (true) {
    ccc = getchar();
    if (ccc == ' ' || ccc == '\n') break;
    if (ccc == '-') {
      _minus = true;
      continue;
    }
    n = n * 10 + ccc - '0';
  }
  if (_minus) n *= -1;
}
inline void read(int &n, int &m) {
  read(n);
  read(m);
}
inline void read(int &n, int &m, int &k) {
  read(n);
  read(m);
  read(k);
}
inline void read(std::string &s) {
  s = "";
  while (true) {
    ccc = getchar();
    if (ccc == ' ' || ccc == '\n') break;
    s += ccc;
  }
}
const int MAXN = 3000;
int n, k, x, flag, mx, mn, new_cnt[MAXN], cnt[MAXN];
int main() {
  scanf("%d%d%d", &n, &k, &x);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  for (int i = 0; i < k; i++) {
    int cur = 0;
    for (int j = 0; j < MAXN; j++) {
      if (cur == 0) {
        new_cnt[j ^ x] += (cnt[j] + 1) / 2;
        new_cnt[j] += cnt[j] / 2;
      } else {
        new_cnt[j ^ x] += cnt[j] / 2;
        new_cnt[j] += (cnt[j] + 1) / 2;
      }
      cur = (cur + cnt[j]) % 2;
    }
    for (int j = 0; j < MAXN; j++) {
      cnt[j] = new_cnt[j];
      new_cnt[j] = 0;
    }
  }
  for (int i = 0; i < MAXN; i++) {
    if (cnt[i]) mx = i;
    if (cnt[i] && !flag) mn = i, flag = 1;
  }
  cout << mx << " " << mn;
}
