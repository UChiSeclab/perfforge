#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k = 0, l = 0;
  vector<vector<int> > x;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int w, y;
    vector<int> tmp;
    cin >> w >> y;
    tmp.push_back(y);
    tmp.push_back(w);
    x.push_back(tmp);
  }
  sort(x.begin(), x.end());
  for (int i = m - 1; i >= 0; i--) {
    while (k < n && x[i][1] > 0) {
      k += 1;
      x[i][1] -= 1;
      l += x[i][0];
    }
  }
  cout << l;
}
