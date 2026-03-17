#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > grass;
int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int p, y, i, q;
  cin >> p >> y;
  if (p == y) {
    cout << -1;
    return 0;
  }
  for (i = 2; i * i <= y && i <= p; i++) {
    grass[(y / i) * i].push_back(i);
  }
  for (i = y; i > p; i--) {
    if (grass.find(i) != grass.end()) {
      for (int k : grass[i]) {
        grass[i - k].push_back(k);
      }
    } else {
      cout << i << "\n";
      return 0;
    }
  }
  cout << -1;
}
