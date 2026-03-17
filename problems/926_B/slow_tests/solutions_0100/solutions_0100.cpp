#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i_ = 0; i_ < v.size(); i_++) {
    cin >> v[i_];
  };
  sort(v.begin(), v.end());
  map<long long, long long> cnt, can;
  for (int i = 0; i < n - 1; i++) {
    long long len = v[i + 1] - v[i];
    set<long long> v;
    for (long long x = 1; x * x <= len; x++) {
      if (len % x == 0) {
        long long a = len / x;
        long long b = x;
        v.insert(a);
        v.insert(b);
      }
    }
    for (auto x : v) {
      long long now = len / x - 1;
      can[x]++;
      cnt[x] += now;
    }
  }
  long long answ = 1e18;
  for (auto i : can) {
    if (i.second == n - 1) {
      answ = min(answ, cnt[i.first]);
    }
  }
  cout << answ;
}
