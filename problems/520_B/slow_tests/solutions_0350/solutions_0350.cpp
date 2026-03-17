#include <bits/stdc++.h>
using namespace std;
int n, m, v[300000];
int dfs(int x, int y) {
  if (x == m) {
    return y;
  } else if (x < 0 || x >= 30005 || v[x] && v[x] < y) {
    return 30005;
  }
  v[x] = y;
  return min(dfs(2 * x, y + 1), dfs(x - 1, y + 1));
}
int main(int argc, char** argv) {
  cin >> n >> m;
  cout << dfs(n, 0) << endl;
  return 0;
}
