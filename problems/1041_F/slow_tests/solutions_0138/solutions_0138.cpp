#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int solve(int d) {
  int dd = d + d;
  map<int, int> fa, fb;
  for (int x : a) fa[x % dd]++;
  for (int x : b) fb[x % dd]++;
  int ans = 0;
  for (auto it : fa) {
    int i = it.first;
    int tmp = fb[(i + d) % dd] + it.second;
    ans = max(ans, tmp);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, y1;
  cin >> n >> y1;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int m, y2;
  cin >> m >> y2;
  b.resize(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  int ans = 2;
  for (int i = 0; i < 31; i++) ans = max(ans, solve(1 << i));
  swap(a, b);
  for (int i = 0; i < 31; i++) ans = max(ans, solve(1 << i));
  cout << ans << endl;
  return 0;
}
