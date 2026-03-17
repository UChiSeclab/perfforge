#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
set<int> st;
int main() {
  int p, q, l, r, x, y;
  cin >> p >> q >> l >> r;
  for (int i = 0; i < p; i++) {
    cin >> x >> y;
    for (int j = x; j <= y; j++) {
      mp[j] = 1;
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    for (int j = l; j <= r; j++)
      for (int z = x + j; z <= y + j; z++)
        if (mp[z]) {
          st.insert(j);
        }
  }
  cout << st.size() << endl;
  return 0;
}
