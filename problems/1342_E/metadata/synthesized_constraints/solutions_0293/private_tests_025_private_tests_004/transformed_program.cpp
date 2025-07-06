#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

template <int p>
struct mod_int {
  long long pow(long long b, long long e) {
    if (e == 0) return 1;
    long long r = pow(b * b % p, e / 2);
    if (e % 2 == 1) r = (r * b) % p;
    return r;
  }
  long long inv(long long b) { return pow(b, p - 2); }
  using m = mod_int;
  long long v;
  mod_int() {}
  mod_int(long long v_) : v(v_) {
    if (v >= p || v <= -p) v %= p;
    if (v < 0) v += p;
  }
  m &operator+=(const m &a) {
    v += a.v;
    if (v >= p) v -= p;
    return *this;
  }
  m &operator-=(const m &a) {
    v -= a.v;
    if (v < 0) v += p;
    return *this;
  }
  m &operator*=(const m &a) {
    v = (v * a.v) % p;
    return *this;
  }
  m &operator/=(const m &a) {
    v = (v * inv(a.v)) % p;
    return *this;
  }
  m operator-() { return m(-v); }
  m &operator^=(long long e) {
    if (e < 0) {
      v = inv(v);
      e = -e;
    }
    v = pow(v, e % (p - 1));
    return *this;
  }
  bool operator==(const m &a) { return v == a.v; }
  bool operator!=(const m &a) { return v != a.v; }
  friend istream &operator>>(istream &in, m &a) {
    long long val;
    in >> val;
    a = m(val);
    return in;
  }
  friend ostream &operator<<(ostream &out, m a) { return out << a.v; }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend m operator^(m a, long long e) { return a ^= e; }
};

vector<mod_int<998244353> > fatt;
mod_int<998244353> fat(int n) {
  if (n < fatt.size()) return fatt[n];
  if (!n)
    fatt.push_back(1);
  else
    fatt.push_back(n * fat(n - 1));
  return fatt.back();
}

const int MAX = 2e5 + 10;
mod_int<998244353> C(int n, int k) { return fat(n) / fat(k) / fat(n - k); }

// Checkers
void check_early_exit_condition(int k, int n) {
    if (k >= n) {
        cerr << "Warning: Early exit condition triggered!" << endl;
        abort();
    }
}

void check_combinatorial_complexity(int k, int n) {
    int threshold = n / 2; // Example threshold
    if (k < threshold) {
        cerr << "Warning: High combinatorial complexity due to large n with small k!" << endl;
        abort();
    }
}

void check_factorial_computation(int n) {
    int threshold = 100000; // Threshold for factorial computation
    if (n > threshold) {
        cerr << "Warning: Large factorial computation!" << endl;
        abort();
    }
}

void check_power_computation(int n, int i) {
    int threshold = 100000; // Threshold for power computation
    if (n > threshold && i > threshold) {
        cerr << "Warning: Expensive power computation!" << endl;
        abort();
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;

  // Insert checkers after reading inputs
  check_early_exit_condition(k, n);
  check_combinatorial_complexity(k, n);
  check_factorial_computation(n);

  if (k >= n) return cout << 0 << '\n', 0;

  mod_int<998244353> ans = 0;

  for (int i = n - k; i + 1; i--) {
    check_power_computation(n, i); // Power computation check inside loop
    mod_int<998244353> add = C(n - k, i) * (mod_int<998244353>(i) ^ n);
    if (i % 2 == (n - k) % 2)
      ans += add;
    else
      ans -= add;
  }

  if (k) ans *= 2;
  cout << ans * C(n, n - k) << '\n';
  exit(0);
}