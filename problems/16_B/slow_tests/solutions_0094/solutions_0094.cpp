#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int total = 0;
  int mark = 0;
  vector<pair<int, int>> containers;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    containers.push_back({-b, a});
  }
  sort(containers.begin(), containers.end());
  for (int i = 0; i < containers.size(); i++) {
    for (int j = 0; j < containers[i].second; j++) {
      n--;
      total -= containers[i].first;
      if (n == 0) {
        mark = 1;
        break;
      }
    }
    if (mark) break;
  }
  cout << total;
}
