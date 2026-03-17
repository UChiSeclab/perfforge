#include <bits/stdc++.h>
struct node {
  int t = INT_MAX, idx = 0, c = 0;
};
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  map<int, deque<node> > mappy;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r, t, c;
    cin >> l >> r >> t >> c;
    node obj;
    obj.t = t;
    obj.idx = i;
    obj.c = c;
    for (int j = l; j <= r; j++) mappy[j].push_back(obj);
  }
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    node curr;
    while (!mappy[i].empty()) {
      node obj = mappy[i].front();
      if (obj.t < curr.t)
        curr = obj;
      else if (obj.t == curr.t && obj.idx < curr.idx)
        curr = obj;
      mappy[i].pop_front();
    }
    ans += curr.c;
  }
  cout << ans;
  return 0;
}
