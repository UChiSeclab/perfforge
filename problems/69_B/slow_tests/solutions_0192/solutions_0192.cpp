#include <bits/stdc++.h>
using namespace std;
long long int maxx(long long int a, long long int b) { return a > b ? a : b; }
long long int n, m;
long long int bs(long long int lo, long long int hi) {
  long long int lolo = lo;
  long long int hihi = hi;
  long long int ans = 0;
  while (lolo <= hihi) {
    long long int mid = (lolo + hihi) / 2;
    if (m * mid <= n - mid + 1) {
      ans = mid;
      lolo = mid + 1;
    } else
      hihi = mid - 1;
  }
  return ans;
}
vector<pair<pair<int, int>, int> > v[101];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r, t, c;
    cin >> l >> r >> t >> c;
    for (int j = l; j <= r; j++) v[j].push_back({{t, i}, c});
  }
  for (int i = 1; i <= 100; i++) sort(v[i].begin(), v[i].end());
  int ans = 0;
  for (int i = 1; i <= 100; i++)
    if (v[i].size() > 0) ans += v[i][0].second;
  cout << ans << endl;
}
int main() { solve(); }
