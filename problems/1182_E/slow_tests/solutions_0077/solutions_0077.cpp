#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long p) {
  if (a == 0) return (a);
  long long t = 1;
  while (p > 0) {
    if (p & 1) t = (a * t) % 1000000007;
    a = (a * a) % 1000000007;
    p >>= 1;
  }
  return (t);
}
void mul(unsigned long long a[3][3], unsigned long long b[3][3]) {
  unsigned long long temp[3][3];
  int i, j, k;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      unsigned long long val = 0;
      for (k = 0; k < 3; ++k) {
        val += (a[i][k] * b[k][j]) % (1000000007 - 1);
        val %= (1000000007 - 1);
      }
      temp[i][j] = val;
    }
  }
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      a[i][j] = temp[i][j];
    }
  }
}
void powmat(unsigned long long a[3][3], long long p) {
  unsigned long long t[3][3] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  while (p > 0) {
    if (p & 1) mul(t, a);
    mul(a, a);
    p >>= 1;
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) a[i][j] = t[i][j];
  }
}
set<long long> s;
void mwork(map<long long, long long>& m, long long n) {
  long long i;
  long long c = 0, f = 1, k;
  k = n;
  while ((!(n & 1)) && n > 1) {
    n = n / 2;
    c++;
  }
  m[2] = c;
  s.insert(2);
  for (i = 3; n > 1 && i <= n; ++i) {
    c = 0;
    while (n % i == 0 && n > 1) {
      n /= i;
      c++;
    }
    m[i] = c;
    s.insert(i);
    if (c == 0 && i * i >= n) {
      m[n] = 1;
      s.insert(n);
      break;
    }
  }
  if (k == n && k != 1) {
    m[n] = 1;
    s.insert(n);
  }
}
int main() {
  long long n, f1, f2, f3, c;
  cin >> n >> f1 >> f2 >> f3 >> c;
  unsigned long long mat[3][3] = {0, 1, 0, 0, 0, 1, 1, 1, 1};
  powmat(mat, n - 3);
  map<long long, long long> p1, p2, p3, pc;
  mwork(p1, f1);
  mwork(p2, f2);
  mwork(p3, f3);
  mwork(pc, c);
  long long ans = 1, i;
  for (auto p : s) {
    long long c1 = (p1[p] + pc[p]);
    long long c2 = (p2[p] + 2 * pc[p]);
    long long c3 = (p3[p] + 3 * pc[p]);
    ans *= ((power(power(p, mat[2][0]), c1) * power(power(p, mat[2][1]), c2)) %
            1000000007 * power(power(p, mat[2][2]), c3)) %
           1000000007;
    ans %= 1000000007;
  }
  ans = (ans * power(power(c, n), 1000000007 - 2)) % 1000000007;
  cout << ans;
}
