#include <bits/stdc++.h>
using namespace std;
int A[10];
int a, b, n, ans = 6;
vector<int> G[10];
void dfs(int pos) {
  if (pos == 6) {
    int tmp = 0;
    for (int i = 1; i <= 6; i++) {
      int sum = 0;
      for (int j = 0; j < G[i].size(); j++) {
        sum += G[i][j];
      }
      if (sum > n) {
        tmp = 8;
        break;
      }
      if (G[i].size() != 0) tmp++;
    }
    ans = min(ans, tmp);
    return;
  }
  for (int i = 1; i <= 6; i++) {
    G[i].push_back(A[pos]);
    dfs(pos + 1);
    G[i].erase(G[i].end() - 1);
  }
}
int main() {
  cin >> n >> a >> b;
  for (int i = 0; i < 4; i++) A[i] = a;
  for (int i = 4; i < 6; i++) A[i] = b;
  dfs(0);
  cout << ans << endl;
  return 0;
}
