#include <bits/stdc++.h>
using namespace std;
class Adj {
 public:
  set<int> list;
  int id;
};
int main() {
  int n, k;
  cin >> n >> k;
  if (k > 13) {
    cout << "No" << endl;
    return 0;
  }
  Adj adj[n + 1];
  adj[n].id = n;
  for (int x, y, i = 1; i < n; i++) {
    adj[i].id = i;
    cin >> x >> y;
    adj[x].list.insert(y);
    adj[y].list.insert(x);
  }
  int i = 1, depth = 0;
  bool flag = true;
  while (i < n) {
    sort(adj + i, adj + n + 1,
         [](Adj &lhs, Adj &rhs) { return lhs.list.size() < rhs.list.size(); });
    map<int, int> ref;
    for (int j = i; j <= n; j++) {
      ref[adj[j].id] = j;
    }
    int j = i;
    while (adj[i].list.size() == 1) i++;
    map<int, int> mp;
    for (; j < i; j++) {
      int x = adj[j].id;
      int y = *(adj[j].list.begin());
      mp[y]++;
      adj[ref[y]].list.erase(x);
    }
    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second < 3) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
    depth++;
  }
  if (flag && depth == k && i == n)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
