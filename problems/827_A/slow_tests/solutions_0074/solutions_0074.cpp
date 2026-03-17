#include <bits/stdc++.h>
using namespace std;
void solve() {
  set<int> pos;
  string ans;
  int n;
  scanf("%d\n", &n);
  for (int i(0), _l((int)(n)-1); i <= _l; ++i) {
    string s;
    getline(cin, s, ' ');
    int k;
    scanf("%d", &k);
    for (int j(0), _l((int)(k)-1); j <= _l; ++j) {
      int x;
      scanf("%d", &x);
      x -= 1;
      while (x + ((int)s.size()) > ((int)ans.size())) {
        pos.insert(((int)ans.size()));
        ans += 'a';
      }
      int now(x);
      while (true) {
        auto it(pos.lower_bound(now));
        if (it == pos.end()) {
          break;
        }
        int nxt(*it);
        if (nxt - x + 1 > ((int)s.size())) {
          break;
        }
        ans[nxt] = s[nxt - x];
        pos.erase(nxt);
      }
    }
    scanf("\n");
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
