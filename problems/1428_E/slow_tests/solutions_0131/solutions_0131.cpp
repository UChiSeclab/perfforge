#include <bits/stdc++.h>
using namespace std;
template <class T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (T &i : arr) {
    in >> i;
  }
  return in;
}
template <class T>
ostream &operator<<(ostream &in, vector<T> &arr) {
  for (T &i : arr) {
    in << i << " ";
  }
  return in;
}
long long debb = 1;
long long next(vector<long long> &t) {
  long long c = (t[1] / t[2] + 1) * (t[1] / t[2] + 1) * (t[1] % t[2]);
  long long u = (t[1] / t[2]) * (t[1] / t[2]) * (t[2] - (t[1] % t[2]));
  long long su = c + u;
  t[2] += 1;
  c = (t[1] / t[2] + 1) * (t[1] / t[2] + 1) * (t[1] % t[2]);
  u = (t[1] / t[2]) * (t[1] / t[2]) * (t[2] - (t[1] % t[2]));
  long long su1 = c + u;
  t[2] -= 1;
  return su - su1;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  long long co = k - n;
  multiset<vector<long long>, greater<vector<long long>>> u;
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    vector<long long> k = {x, x, 1};
    long long ra = next(k);
    u.insert({ra, x, x, 1});
  }
  for (int i = 0; i < co; ++i) {
    vector<long long> r = *(u.begin());
    u.erase(u.begin());
    vector<long long> o = {r[1], r[2], r[3]};
    o[2] += 1;
    o[0] = o[1] / o[2] + min(o[1] % o[2], 1ll);
    long long ra = next(o);
    u.insert({ra, o[0], o[1], o[2]});
  }
  long long ans = 0;
  for (auto r : u) {
    vector<long long> t = {r[1], r[2], r[3]};
    for (int i = 0; i < t[2]; ++i) {
      long long c = t[1] / t[2] + max(min(t[1] % t[2] - i, 1ll), 0ll);
      ans += c * c;
    }
  }
  cout << ans << '\n';
}
