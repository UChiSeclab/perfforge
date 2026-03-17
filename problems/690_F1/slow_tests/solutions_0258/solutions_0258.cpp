#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e4 + 200;
long long n, ans;
vector<long long> adj[MAXN];
bool mark[MAXN];
void dfs(long long x, long long cnt) {
  if (cnt == 2) {
    ans++;
    return;
  }
  mark[x] = 1;
  for (int i = 0; i < (long long)adj[x].size(); i++) {
    if (mark[adj[x][i]] == 0) {
      dfs(adj[x][i], cnt + 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (long long i = 1; i <= n; i++) {
    dfs(i, 0);
    fill(mark, mark + MAXN, 0);
  }
  cout << ans / 2 << endl;
}
