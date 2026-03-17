#include <bits/stdc++.h>
using namespace std;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
const int OO = (int)1e6;
pair<long long, pair<long long, long long> > extendedEuclid(long long a,
                                                            long long b) {
  if (a == 0) return make_pair(b, make_pair(0, 1));
  pair<long long, pair<long long, long long> > p;
  p = extendedEuclid(b % a, a);
  return make_pair(
      p.first,
      make_pair(p.second.second - p.second.first * (b / a), p.second.first));
}
long long modInverse(long long a, long long m) {
  return (extendedEuclid(a, m).second.first + m) % m;
}
long long powmod(long long base, long long pw, long long mod) {
  long long ret = 1;
  while (pw) {
    if (pw & 1) ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
long long LCM(long long a, long long b) { return (a / GCD(a, b)) * b; }
long long Bigmod(long long x, long long y, long long m) {
  if (y == 0) return 1 % m;
  if (y % 2 == 0) {
    long long temp = Bigmod(x, y / 2, m);
    return (temp * temp) % m;
  }
  return (x % m * Bigmod(x, y - 1, m)) % m;
}
const int MAX_N = 1000000;
vector<int> primes;
bool is_prime[MAX_N];
void sieve() {
  for (int i = 0; i < MAX_N; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < MAX_N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i + i; j < MAX_N; j += i) is_prime[j] = false;
    }
  }
}
vector<int> prime_Factors(long long N) {
  vector<int> factors;
  long long PF_idx = 0, PF = primes[PF_idx];
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) {
      N /= PF;
      factors.push_back(PF);
    }
    PF = primes[++PF_idx];
  }
  if (N != 1) factors.push_back(N);
  return factors;
}
long long numPF(long long N) {
  long long PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) {
      N /= PF;
      ans++;
    }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}
long long numDiv(long long N) {
  long long PF_idx = 0, PF = primes[PF_idx], ans = 1;
  while (N != 1 && (PF * PF <= N)) {
    long long power = 0;
    while (N % PF == 0) {
      N /= PF;
      power++;
    }
    ans *= (power + 1);
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;
  return ans;
}
long long sumDiv(long long N) {
  long long PF_idx = 0, PF = primes[PF_idx], ans = 1;
  while (N != 1 && (PF * PF <= N)) {
    long long power = 0;
    while (N % PF == 0) {
      N /= PF;
      power++;
    }
    ans *= ((long long)pow((double)PF, power + 1.0) - 1) / (PF - 1);
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= ((long long)pow((double)N, 2.0) - 1) / (N - 1);
  return ans;
}
long long modulo(long long m, long long n) {
  return m >= 0 ? m % n : (n - abs(m % n)) % n;
}
bool cmp(const pair<int, pair<int, int> >& a,
         const pair<int, pair<int, int> >& b) {
  if (a.first < b.first) return true;
  if (a.first == b.first)
    if (a.second.first < b.second.first) return true;
  return false;
}
int main() {
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, pair<int, int> > > > v(n + 1);
  for (int i = 0; i < m; i++) {
    int l, r, t, c;
    cin >> l >> r >> t >> c;
    for (int j = l; j <= r; j++) {
      v[j].push_back(make_pair(t, make_pair(i + 1, c)));
    }
  }
  for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end(), cmp);
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i].size()) res += v[i][0].second.second;
  }
  cout << res;
  return 0;
}
