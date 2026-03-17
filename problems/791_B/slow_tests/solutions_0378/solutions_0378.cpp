#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, a, b, n, m;
  cin >> n >> m;
  vector<int> v[n + 1];
  for (i = 1; i <= n; i++) {
    v[i].push_back(i);
  }
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (i = 1; i <= n; i++) {
    sort(v[i].begin(), v[i].end());
  }
  int flag = 1, count = 0;
  ;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < v[i].size(); j++) {
      if (!equal(v[i].begin(), v[i].end(), v[v[i][j]].begin())) {
        flag = 0;
        break;
      }
    }
    if (flag == 0) {
      cout << "NO";
      break;
    }
  }
  if (flag == 1) {
    cout << "YES";
  }
}
