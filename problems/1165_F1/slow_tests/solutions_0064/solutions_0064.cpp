#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
vector<pair<int, int> > b;
bool can(int d1) {
  vector<int> c(n, -1);
  for (int i = 0; i < m; i++) {
    if (b[i].first <= d1) c[b[i].second] = max(c[b[i].second], b[i].first);
  }
  vector<int> d[2005];
  for (int i = 0; i < n; i++) {
    if (c[i] != -1) d[c[i]].push_back(i);
  }
  vector<int> e = a;
  int k = 0;
  for (int i = 0; i <= d1; i++) {
    k++;
    for (int j = 0; j < d[i].size() && k; j++) {
      if (k >= e[d[i][j]]) {
        k -= e[d[i][j]];
        e[d[i][j]] = 0;
      } else {
        e[d[i][j]] -= k;
        k = 0;
      }
    }
  }
  int l = 0;
  for (int i = 0; i < n; i++) l += e[i];
  return l * 2 <= k;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a.push_back(t);
  }
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    b.push_back(make_pair(v1 - 1, v2 - 1));
  }
  int i = 0;
  while (!can(i)) i++;
  cout << i + 1;
  return 0;
}
