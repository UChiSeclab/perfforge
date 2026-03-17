#include <bits/stdc++.h>
using namespace std;
unordered_map<int, set<int> > mm;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    set<int> fact;
    int r = i - y, ans = 0;
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        fact.insert(j);
        if (x / j != j) fact.insert(x / j);
      }
    }
    if (y == 0)
      cout << (int)fact.size() << '\n';
    else {
      int ans = 0;
      for (auto m : fact) {
        int r = i - y;
        auto it = mm[m].lower_bound(r);
        if (it != mm[m].end() && *it >= r) continue;
        ans++;
      }
      cout << ans << '\n';
    }
    for (auto m : fact) mm[m].insert(i);
  }
  return 0;
}
