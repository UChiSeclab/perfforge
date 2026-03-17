#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long x, y;
  cin >> x >> y;
  multiset<long long> v;
  for (long long i = 0; i < n; i++) {
    long long xx;
    cin >> xx;
    if (xx <= x) {
      v.insert(xx);
    }
  }
  if (x > y) {
    cout << n;
    return 0;
  }
  long long ans = 0;
  while (v.size() > 0) {
    auto it = v.end();
    it--;
    v.erase(it);
    ans++;
    if (v.size() == 0) {
      break;
    }
    it = v.end();
    it--;
    if (*it + y <= x) {
      long long q = *it;
      v.erase(it);
      v.insert(q + y);
    } else {
      v.erase(it);
    }
  }
  cout << ans;
}
