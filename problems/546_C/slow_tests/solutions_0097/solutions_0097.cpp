#include <bits/stdc++.h>
using namespace std;
long long mod = 9223372036854775807;
long long fastPow(long long b, long long e) {
  long long r = 1;
  while (e) {
    if (e % 2 == 1) {
      r *= b;
      r %= mod;
    }
    b *= b;
    b %= mod;
    e /= 2;
  }
  return r;
}
long long pgcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return pgcd(b, a % b);
}
long long sign(long long a) {
  if (a < 0) {
    return -1;
  }
  if (a == 0) {
    return 0;
  }
  if (a > 0) {
    return 1;
  }
}
bool isPrime(long long a) {
  if (a == 1) {
    return false;
  }
  long long f = sqrt(a);
  for (long long i = 2; i <= f; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}
long long toInt(string s) {
  long long tot = 0;
  for (long long i = s.size() - 1; i >= 0; i--) {
    tot += ((s[i] - '0') % mod) * fastPow(10, i);
    tot %= mod;
  }
  return tot;
}
string toString(long long a) {
  string s = "";
  while (a) {
    s = (char)('0' + a % 10) + s;
    a /= 10;
  }
  return s;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  deque<long long> a;
  deque<long long> b;
  long long c;
  cin >> c;
  for (long long i = 0; i < c; i++) {
    long long d;
    cin >> d;
    a.push_back(d);
  }
  long long d;
  cin >> d;
  for (long long i = 0; i < d; i++) {
    long long e;
    cin >> e;
    b.push_back(e);
  }
  long long tot = 0;
  while (!a.empty() && !b.empty()) {
    long long e = a.front();
    long long f = b.front();
    a.pop_front();
    b.pop_front();
    if (e > f) {
      a.push_back(f);
      a.push_back(e);
    } else {
      b.push_back(e);
      b.push_back(f);
    }
    tot++;
    if (tot >= 10000000) break;
  }
  if (tot >= 10000000) {
    cout << -1 << endl;
    return 0;
  } else
    cout << tot << ' ';
  if (a.empty()) {
    cout << 2 << endl;
  } else {
    cout << 1 << endl;
  }
}
