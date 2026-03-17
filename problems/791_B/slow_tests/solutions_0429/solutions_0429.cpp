#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1000000000;
const long long int MOD = 1000000007;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  register long long int i, j, x, y, m, n, t, k, sum = 0, max, min, count = 0,
                                                 temp, w, q, f = 0;
  cin >> n >> m;
  vector<set<long long int> > v(n + 1);
  vector<bool> visited(n + 1, false);
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].insert(y);
    v[y].insert(x);
  }
  for (i = 1; i <= n; i++) {
    v[i].insert(i);
  }
  for (i = 1; i <= n; i++) {
    if (!visited[i]) {
      for (auto &it : v[i]) {
        visited[it] = true;
        if (v[it] != v[i]) {
          f = 1;
          break;
        }
      }
    }
    if (f) {
      break;
    }
  }
  if (f)
    cout << "NO";
  else
    cout << "YES";
}
