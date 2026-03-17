#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long powmod(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = powmod(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long modif(long long x, long long m) { return (powmod(x, m - 2, m)); }
bool fa(vector<long long> &x, vector<long long> &y) { return x[0] < y[0]; }
bool fa1(vector<long long> &x, vector<long long> &y) { return x[1] < y[1]; }
bool f1(pair<long long, long long> &x, pair<long long, long long> &y) {
  return x.second > y.second;
}
bool f2(pair<long long, long long> &x, pair<long long, long long> &y) {
  return x.first < y.first;
}
bool f3(long long &x, long long &y) { return abs(x) > abs(y); }
long long mxn = 1e6;
vector<long long> b;
vector<long long> ch(mxn, 0ll);
long long tr;
long long m, n, k;
bool meow(long long x, vector<array<long long, 3> > &c) {
  if (x == 0) return true;
  long long yo = 0;
  for (int i = 0; i < mxn; i++) ch[i] = 0;
  long long y = b[b.size() - x];
  for (int i = 0; i < k; i++) {
    if (c[i][2] > y) {
      ch[c[i][0]]++;
      ch[c[i][1] + 1]--;
    }
  }
  long long l = 0;
  for (int i = 0; i < n + 1; i++) {
    l += ch[i];
    yo += 1;
    if (l > 0) yo += 2;
  }
  return yo <= tr;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m >> n >> k >> tr;
  for (int i = 0; i < m; i++) {
    long long x;
    cin >> x;
    b.push_back(x);
  }
  sort(b.begin(), b.end());
  vector<array<long long, 3> > c(k);
  for (int i = 0; i < k; i++) {
    cin >> c[i][0] >> c[i][1] >> c[i][2];
  }
  long long l = 0, r = m;
  long long it = 0;
  while (l < r) {
    if (it > 100) {
      cout << "meow";
      break;
    }
    long long mid = (l + r + 1) / 2;
    if (meow(mid, c))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l;
  return 0;
}
