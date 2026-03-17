#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  unordered_map<int, unordered_set<int>> deg;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    deg[a].insert(b);
    deg[b].insert(a);
  }
  int levels = 1;
  while (levels <= 11) {
    unordered_map<int, unordered_set<int>> parents;
    for (auto& p : deg) {
      int size = p.second.size();
      if (size == 1) {
        int parent = *p.second.begin();
        parents[parent].insert(p.first);
      }
    }
    if (parents.size() == 1 && parents.begin()->second.size() > 2 &&
        parents.begin()->second.size() + 1 == deg.size()) {
      cout << ((levels == k) ? "Yes" : "No") << endl;
      return 0;
    }
    for (auto& p : parents) {
      int size = p.second.size();
      if (size < 3) {
        cout << "No" << endl;
        return 0;
      }
      for (auto& child : p.second) {
        deg.erase(child);
        deg[p.first].erase(child);
      }
    }
    ++levels;
  }
  cout << ((levels == k) ? "Yes" : "No") << endl;
  return 0;
}
