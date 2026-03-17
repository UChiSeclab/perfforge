#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, q, l, r;
  cin >> p >> q >> l >> r;
  set<int> a, b, tmp;
  int t1, t2;
  for (int i = 0; i < p; i++) {
    cin >> t1 >> t2;
    for (; t1 <= t2; t1++) a.insert(t1);
  }
  for (int i = 0; i < q; i++) {
    cin >> t1 >> t2;
    for (; t1 <= t2; t1++) {
      b.insert(t1);
    }
  }
  int ans = 0;
  for (; l <= r; l++) {
    tmp.clear();
    for (set<int>::iterator it = b.begin(); it != b.end(); it++) {
      tmp.insert(*it + l);
    }
    vector<int> c(min(a.size(), tmp.size()));
    vector<int>::iterator it;
    it =
        set_intersection(a.begin(), a.end(), tmp.begin(), tmp.end(), c.begin());
    c.resize(it - c.begin());
    ans += c.size() > 0;
  }
  cout << ans << "\n";
  return 0;
}
