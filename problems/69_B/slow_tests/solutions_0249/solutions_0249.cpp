#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct item {
  int c, t, num;
};
bool boolf(item p, item p1) {
  return p.t < p1.t || (p.t == p1.t && p.num < p1.num);
}
int main() {
  int n, m, i, j;
  cin >> n >> m;
  vector<item> a[200];
  for (int i = 0; i < m; i++) {
    int l, r, t, c;
    cin >> l >> r >> t >> c;
    item tt;
    tt.num = i;
    tt.t = t;
    tt.c = c;
    for (j = l; j <= r; j++) a[j].push_back(tt);
  }
  int ans = 0;
  for (i = 1; i <= n; i++) {
    if (a[i].empty()) continue;
    sort(a[i].begin(), a[i].end(), boolf);
    item anst = a[i][0];
    ans += anst.c;
  }
  cout << ans;
  return 0;
}
