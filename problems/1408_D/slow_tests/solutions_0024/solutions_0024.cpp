#include <bits/stdc++.h>
using namespace std;
const long long int inf = (long long int)2e18;
const int mod = 1e9 + 7;
bool overflow(long long int a, long long int b) {
  if (a <= (inf + b - 1) / b) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > robber(n), light(m);
  for (int i = 0; i < n; i++) {
    cin >> robber[i].first >> robber[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> light[i].first >> light[i].second;
  }
  sort(light.begin(), light.end());
  sort(robber.begin(), robber.end());
  int sufmax[m + 1];
  sufmax[m] = 0;
  for (int i = m - 1; i >= 0; i--)
    sufmax[i] = max(sufmax[i + 1], light[i].second);
  int mini = 1e9;
  for (int i = 0; i < 1e6 + 2; i++) {
    int req = 0, k = 0, j;
    for (j = 0; j < n; j++) {
      while (k < m && light[k].first < robber[j].first + i) k++;
      if (k == m) break;
      req = max(req, sufmax[k] - robber[j].second + 1);
    }
    mini = min(mini, req + i);
    if (j == 0 || i > mini) break;
  }
  cout << mini << "\n";
}
