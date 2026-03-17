#include <bits/stdc++.h>
using namespace std;
bool visited[100005 + 1];
vector<long long int> adj[100005 + 1];
long long int level[100005 + 1];
long long int ans = 0;
void initialize() {
  for (long long int i = 0; i <= 100005; i++) {
    visited[i] = false;
  }
}
void dfs(long long int i) {
  visited[i] = true;
  for (auto it : adj[i]) {
    if (visited[it] == false) {
      dfs(it);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long int n, m, x, y;
  cin >> n >> m;
  if (m != n - 1) {
    cout << "no" << endl;
    return 0;
  }
  for (long long int i = 1; i <= m; i++) {
    cin >> x >> y;
    adj[y].push_back(x);
    adj[x].push_back(y);
  }
  long long int c = 0;
  initialize();
  for (long long int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      dfs(1);
      c++;
      if (c > 1) {
        cout << "no" << endl;
        return 0;
      }
    }
  }
  cout << "yes" << endl;
}
