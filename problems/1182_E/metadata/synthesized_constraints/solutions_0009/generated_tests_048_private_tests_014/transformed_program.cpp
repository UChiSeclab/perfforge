#include <bits/stdc++.h>
using namespace std;

struct matrix {
  int n;
  long long p[7][7];
  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) p[i][j] = 0;
  }
};

long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

matrix multiply(matrix a, matrix b) {
  matrix c;
  c.init(a.n);
  int n = a.n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        c.p[i][j] =
            (c.p[i][j] + 1ll * a.p[i][k] * b.p[k][j] % (1000000007 - 1)) %
            (1000000007 - 1);
  return c;
}

long long Pow(long long a, long long n, long long m = 1000000007) {
  long long t = 1;
  for (; n; n >>= 1, (a *= a) %= m)
    if (n & 1) (t *= a) %= m;
  return t;
}

void check_exbsgs_invariant(long long m, long long iterations) {
    if (iterations > m * m) { // Check if iterations exceed expected search space
        cerr << "Warning: Performance bottleneck condition triggered in exbsgs - large search space!" << endl;
        abort();
    }
}

void check_pow_invariant(long long ret) {
    if (ret > 1e9) { // Example threshold based on ret's size
        cerr << "Warning: Performance bottleneck condition triggered in power calculation - excessive iterations!" << endl;
        abort();
    }
}

long long exbsgs(long long a, long long b, long long p) {
  if (b == 1LL) return 0;
  long long t, d = 1, k = 0;
  while ((t = gcd(a, p)) != 1) {
    if (b % t) return -1;
    ++k, b /= t, p /= t, d = d * (a / t) % p;
    if (b == d) return k;
  }
  unordered_map<long long, long long> dic;
  long long m = ceil(sqrt(p));
  long long a_m = Pow(a, m, p), mul = b;
  long long iterations = 0;
  for (long long j = 1; j <= m; ++j) {
    mul = mul * a % p;
    dic[mul] = j;
  }
  for (long long i = 1; i <= m; ++i) {
    d = d * a_m % p;
    iterations++;
    if (dic[d]) return i * m - dic[d] + k;
  }
  check_exbsgs_invariant(m, iterations); // Check for performance bottleneck
  return -1;
}

int main() {
  long long n, f1, f2, f3, c;
  cin >> n >> f1 >> f2 >> f3 >> c;
  c = exbsgs(5, c, 1000000007);
  f1 = exbsgs(5, f1, 1000000007);
  f2 = exbsgs(5, f2, 1000000007);
  f3 = exbsgs(5, f3, 1000000007);
  n -= 3;
  matrix X;
  X.init(5);
  X.p[0][0] = 1;
  X.p[0][1] = 1;
  X.p[0][2] = 1;
  X.p[0][3] = c * 2 % (1000000007 - 1);
  X.p[0][4] = (-c * 6 % (1000000007 - 1) + (1000000007 - 1)) % (1000000007 - 1);
  X.p[1][0] = 1;
  X.p[2][1] = 1;
  X.p[3][3] = 1;
  X.p[3][4] = 1;
  X.p[4][4] = 1;
  matrix base;
  base.init(5);
  for (int i = 0; i < 5; i++) base.p[i][i] = 1;
  while (n) {
    if (n & 1) base = multiply(base, X);
    X = multiply(X, X);
    n >>= 1;
  }
  long long ret = 0;
  (ret += 1ll * base.p[0][0] * f3) %= (1000000007 - 1);
  (ret += 1ll * base.p[0][1] * f2) %= (1000000007 - 1);
  (ret += 1ll * base.p[0][2] * f1) %= (1000000007 - 1);
  (ret += 1ll * base.p[0][3] * 4ll) %= (1000000007 - 1);
  (ret += 1ll * base.p[0][4]) %= (1000000007 - 1);

  check_pow_invariant(ret); // Check for performance issue in exponentiation

  long long ans = 1;
  long long x = 5;
  while (ret) {
    if (ret & 1) ans = ans * x % 1000000007;
    x = x * x % 1000000007;
    ret >>= 1;
  }
  cout << ans << endl;
}