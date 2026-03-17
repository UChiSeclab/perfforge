#include <bits/stdc++.h>
using namespace std;
vector<long long> divisors(long long n) {
  vector<long long> res;
  for (long long i = 1; i * i <= n; i++) {
    long long one = i;
    if (n % one == 0) {
      res.push_back(one);
      if (one != n / one) res.push_back(n / one);
    }
  }
  for (long long i = 0; i < res.size(); i++) {
    res[i]--;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> diff;
  for (long long i = 0; i < (long long)a.size() - 1; i++) {
    diff.push_back(a[i + 1] - a[i] - 1);
  }
  sort(diff.begin(), diff.end());
  map<long long, long long> res;
  map<long long, long long> cando;
  for (long long i = 0; i < diff.size(); i++) {
    vector<long long> temp = divisors(diff[i] + 1);
    for (long long j = 0; j < temp.size(); j++) {
      long long pp = (diff[i] - temp[j]) / (temp[j] + 1);
      res[pp] += temp[j];
      cando[pp]++;
    }
  }
  long long ans = 1e12;
  for (auto x : res) {
    if (cando[x.first] == diff.size()) ans = min(ans, x.second);
  }
  cout << ans << '\n';
  return 0;
}
