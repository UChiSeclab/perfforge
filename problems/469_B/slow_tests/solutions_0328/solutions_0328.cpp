#include <bits/stdc++.h>
using namespace std;
const int modo = 10000007, LL = 1e-9;
int main() {
  ios_base::sync_with_stdio(0);
  int p, q, r, l;
  cin >> p >> q >> l >> r;
  vector<pair<int, int> > v(p), v1(q);
  for (int i = 0; i < p; i++) cin >> v[i].first >> v[i].second;
  for (int i = 0; i < q; i++) cin >> v1[i].first >> v1[i].second;
  set<int> s;
  int ans = 0;
  for (int i = l; i <= r; i++) {
    bool ok = 0;
    for (int j = 0; j < p; j++) {
      for (int k = 0; k < q; k++) {
        int a = v1[k].first + i;
        int b = v1[k].second + i;
        for (int u = a; u <= b; u++)
          if (u >= v[j].first && u <= v[j].second) s.insert(i);
      }
    }
  }
  cout << s.size() << endl;
}
