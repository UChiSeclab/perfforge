#include <bits/stdc++.h>
using namespace std;
int countBits(long long mask) {
  int res = 0;
  while (mask) mask &= (mask - 1), ++res;
  return res;
}
string toString(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
long long toNumber(string s) {
  stringstream ss;
  long long n;
  ss << s;
  ss >> n;
  return n;
}
void nCr(int n, int k, vector<long double> &foo2, vector<long double> &ta7t) {
  for (int i = (int)(1), _m = (int)(k + 1); i < _m; ++i) ta7t.push_back(i);
  for (int i = (int)(n), _m = (int)(n - k + 1); i >= _m; --i) foo2.push_back(i);
}
long double solve(int n, int m, int m2) {
  vector<long double> foo2, ta7t;
  nCr(n * m - m, n - m2, foo2, ta7t);
  nCr(n * m, n, ta7t, foo2);
  nCr(m, m2, foo2, ta7t);
  foo2.push_back(m2), foo2.push_back(m2);
  ta7t.push_back(n);
  sort(foo2.rbegin(), foo2.rend()), sort(ta7t.rbegin(), ta7t.rend());
  int common = min((int)foo2.size(), (int)ta7t.size());
  long double res = 1;
  for (int i = (int)(0), _m = (int)(common); i < _m; ++i)
    res *= foo2[i] / ta7t[i];
  for (int i = (int)(common), _m = (int)(foo2.size()); i < _m; ++i)
    res *= foo2[i];
  for (int i = (int)(common), _m = (int)(ta7t.size()); i < _m; ++i)
    res /= ta7t[i];
  return res;
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    long double res = 0;
    for (int m2 = (int)(1), _m = (int)(min(n, m) + 1); m2 < _m; ++m2)
      res += solve(n, m, m2);
    cout.precision(8);
    cout << fixed << res << endl;
  }
  return 0;
}
