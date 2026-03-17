#include <bits/stdc++.h>
using namespace std;
map<long long, long long> m;
long long a, b, k, ans;
vector<long long> v;
bool ckprm(long long x) {
  if (x < 2)
    return false;
  else if (x == 2 or x == 3)
    return true;
  for (long long j = 2; j * j <= x; j++) {
    if (x % j == 0) return false;
  }
  return true;
}
int main() {
  cin >> a >> b >> k;
  v.push_back(a - 1);
  for (long long i = a; i <= b; i++) {
    if (ckprm(i)) {
      v.push_back(i);
    }
  }
  v.push_back(b + 1);
  if (v.size() - 2 < k)
    cout << -1;
  else {
    for (long long i = 0; i <= v.size() - 1 - k; i++) {
      ans = max(ans, v[i + k] - v[i]);
    }
    cout << ans;
  }
}
