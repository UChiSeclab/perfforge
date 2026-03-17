#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  int n, m;
  cin >> n >> m;
  vector<set<int>> G(n);
  vector<bool> B(n, true);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  set<pair<int, int>> S;
  set<int> L;
  for (int i = 0; i < n; ++i) {
    L.insert(i);
  }
  for (int i = 0; i < n; ++i) {
    S.insert(make_pair(G[i].size(), i));
  }
  int result = -1;
  for (auto s : S) {
    if (B[s.second]) {
      result++;
      L.erase(s.second);
      queue<int> Q;
      Q.push(s.second);
      B[s.second] = false;
      while (!Q.empty()) {
        int q = Q.front();
        Q.pop();
        vector<int> R;
        for (int l : L) {
          if (G[q].find(l) == G[q].end()) {
            R.push_back(l);
            Q.push(l);
            B[l] = false;
          }
        }
        for (int r : R) {
          L.erase(r);
        }
      }
    }
  }
  cout << result << endl;
  return 0;
}
