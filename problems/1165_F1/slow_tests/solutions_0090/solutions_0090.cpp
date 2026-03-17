#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> k;
vector<pair<int, int>> q(1001);
bool can(int day) {
  vector<int> lst(n, -1);
  for (int i = 0; i < m; ++i) {
    if (q[i].first <= day) {
      lst[q[i].second] = max(lst[q[i].second], q[i].first);
    }
  }
  vector<vector<int>> off(1001);
  for (int i = 0; i < n; ++i) {
    if (lst[i] != -1) {
      off[lst[i]].push_back(i);
    }
  }
  vector<int> need = k;
  int money = 0;
  for (int i = 0; i <= day; ++i) {
    ++money;
    if (i > 1000) continue;
    for (auto it : off[i]) {
      if (money >= need[it]) {
        money -= need[it];
        need[it] = 0;
      } else {
        need[it] -= money;
        money = 0;
        break;
      }
    }
  }
  return accumulate(need.begin(), need.end(), 0) * 2 <= money;
}
int main() {
  cin >> n >> m;
  k = vector<int>(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> q[i].first >> q[i].second;
    --q[i].first;
    --q[i].second;
  }
  for (int j = 0; j <= 2000; ++j) {
    if (can(j)) {
      cout << j + 1 << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
