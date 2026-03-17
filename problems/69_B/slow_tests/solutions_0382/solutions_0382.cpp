#include <bits/stdc++.h>
using namespace std;
using namespace std;
struct par {
  int time;
  int id;
  int profit;
};
bool comp(const par &p1, const par &p2) {
  if (p1.time < p2.time) return true;
  if (p1.time == p2.time) {
    return p1.id < p2.id;
  }
  return false;
}
int main() {
  vector<par> v[120];
  par p;
  int n, m;
  int l, r, t, c;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> l >> r >> t >> c;
    p.id = i;
    p.time = t;
    p.profit = c;
    for (int j = l; j <= r; ++j) {
      v[j].push_back(p);
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    sort((v[i]).begin(), (v[i]).end(), comp);
    if (v[i].size() > 0) {
      res += v[i][0].profit;
    }
  }
  cout << res << endl;
  return 0;
}
