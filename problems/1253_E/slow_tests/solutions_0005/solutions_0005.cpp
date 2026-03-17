#include <bits/stdc++.h>
using namespace std;
const long long INFL = 1LL << 60;
const long long INF = INFL;
long long MOD = 1000000007;
vector<long long> dy = {0, -1, 0, 1, 1, 1, -1, -1, 0};
vector<long long> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};
void pres(double A) { cout << fixed << setprecision(10) << A << endl; }
void BinarySay(long long x, long long y = 60) {
  for (long long i = 0; i < (y); i++) cout << (x >> (y - 1 - i) & 1);
  cout << endl;
}
long long get_bit(long long x) { return __builtin_popcountll(x); }
long long pow_long(long long x, long long k) {
  long long res = 1;
  while (k > 0) {
    if (k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}
long long pow_mod(long long x, long long k) {
  long long res = 1;
  while (k > 0) {
    if (k % 2) {
      res *= x;
      res %= MOD;
    }
    x *= x;
    x %= MOD;
    k /= 2;
  }
  return res;
}
long long inverse(long long x) { return pow_mod(x, MOD - 2); };
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; };
long long kai_mod(long long x) {
  if (x == 0) return 1;
  return x * kai_mod(x - 1) % MOD;
}
vector<long long> divisor(long long n) {
  vector<long long> res(0);
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}
vector<long long> MakePrimeList(long long x) {
  vector<long long> res;
  for (long long k = 2; k * k <= x; k++) {
    if (x % k == 0) {
      res.push_back(k);
      while (x % k == 0) x /= k;
    }
  }
  if (x > 1) res.push_back(x);
  return res;
}
const int MAXcomb = 200010;
long long fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAXcomb; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
long long comb(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * finv[k] % MOD * finv[n - k] % MOD;
}
const long long N_ = (1 << 18);
long long seg[2 * N_ - 1];
void init_seg() {
  for (long long i = 0; i < (2 * N_ - 1); i++) {
    seg[i] = INFL;
  }
}
void update(long long k, long long x) {
  k += N_ - 1;
  seg[k] = min(x, seg[k]);
  while (k > 0) {
    k = (k - 1) / 2;
    seg[k] = min(seg[k], min(seg[2 * k + 1], seg[2 * k + 2]));
  }
}
long long getminimum(long long x, long long y, long long k = 0,
                     long long left = 0, long long right = N_) {
  if (right <= x || y <= left) return INFL;
  if (x <= left && right <= y) return seg[k];
  long long mid = (left + right) / 2;
  long long l = getminimum(x, y, 2 * k + 1, left, mid);
  long long r = getminimum(x, y, 2 * k + 2, mid, right);
  return min(l, r);
}
void solve() {
  long long N, M;
  cin >> N >> M;
  vector<pair<long long, long long>> l(N);
  for (long long i = 0; i < (N); i++) {
    cin >> l[i].first >> l[i].second;
    l[i].first;
  }
  sort(l.begin(), l.end());
  reverse(l.begin(), l.end());
  init_seg();
  update(0, 0);
  for (long long t = 1; t <= M; t++) {
    long long x = getminimum(t - 1, N_);
    if (t != 1) {
      update(t, x + 1);
    }
    for (long long i = 0; i < (N); i++) {
      if (t > l[i].first - l[i].second && t != 1) break;
      if (t >= l[i].first - l[i].second) {
        update(l[i].first + l[i].second, x);
      } else {
        update(l[i].first * 2 - t, x + l[i].first - l[i].second - t);
      }
    }
  }
  long long ans = getminimum(M, N_);
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
