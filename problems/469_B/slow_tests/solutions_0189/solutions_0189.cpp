#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);
  int p, q, l, r, a, b;
  cin >> p >> q >> l >> r;
  map<int, bool> m;
  for (int i = 0; i < (int)(p); ++i) {
    cin >> a >> b;
    for (int i = (int)(a); i <= (int)(b); ++i) m[i] = true;
  }
  set<int> res;
  for (int i = 0; i < (int)(q); ++i) {
    cin >> a >> b;
    for (int j = (int)(l); j <= (int)(r); ++j) {
      for (int k = (int)(a + j); k <= (int)(b + j); ++k) {
        if (m[k]) res.insert(j);
      }
    }
  }
  cout << res.size() << endl;
  return 0;
}
