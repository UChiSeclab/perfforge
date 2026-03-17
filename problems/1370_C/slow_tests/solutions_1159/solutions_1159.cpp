#include <bits/stdc++.h>
using namespace std;
int Divisors(long long n) {
  vector<long long> v;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        v.push_back(i);
      } else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  int c = 0, i;
  for (i = 0; i < v.size(); i++) {
    if (v[i] % 2 == 1 && v[i] != (n / 2) && v[i] != 1) {
      return 1;
    }
  }
  return 2;
}
long long power(long long base, long long pow, long long mo) {
  long long res = 1;
  while (pow) {
    if (pow & 1) res = (res * base) % mo;
    base = (base * base) % mo;
    pow /= 2;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, k, mini, l1, l2, l3, r1, r2, c, d, maxi, x, y, l, m, r,
      ans, last, flag, lastind;
  t = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1) {
      cout << "FastestFinger"
           << "\n";
    } else if (n % 2 == 1) {
      cout << "Ashishgup"
           << "\n";
    } else if (n == 2) {
      cout << "Ashishgup"
           << "\n";
    } else {
      x = Divisors(n);
      if (x == 1) {
        cout << "Ashishgup"
             << "\n";
      } else {
        cout << "FastestFinger"
             << "\n";
      }
    }
  }
}
