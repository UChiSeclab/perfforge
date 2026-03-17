#include <bits/stdc++.h>
using namespace std;
void dfs(map<int, vector<int>> &mp, int &s, vector<bool> &visited,
         long long int &c2, long long int &count) {
  stack<int> stack;
  stack.push(s);
  while (!stack.empty()) {
    s = stack.top();
    stack.pop();
    if (!visited[s]) {
      c2++;
      count += mp[s].size();
      visited[s] = true;
      for (int i = 0; i < mp[s].size(); i++) {
        if (!visited[mp[s][i]]) stack.push(mp[s][i]);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, n, m, j, x, y;
  scanf("%d%d", &n, &m);
  map<int, vector<int>> mp;
  for (i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    mp[x].push_back(y);
    mp[y].push_back(x);
  }
  int f = 0;
  vector<bool> visited(n + 1, 0);
  for (i = 1; i <= n; i++) {
    if (!visited[i]) {
      long long int c2 = 0, count = 0;
      dfs(mp, i, visited, c2, count);
      if (count != (c2 * (c2 - 1))) {
        puts("NO");
        f = 1;
        break;
      }
    }
  }
  if (f == 0) {
    puts("YES");
  }
  return 0;
}
