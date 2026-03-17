#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  vector<set<int> > pockets;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    bool done = false;
    for (int j = 0; j < pockets.size(); j++) {
      int sb = pockets[j].size();
      pockets[j].insert(a);
      if (sb != pockets[j].size()) {
        done = true;
        break;
      }
    }
    if (!done) {
      set<int> temp;
      temp.insert(a);
      pockets.push_back(temp);
    }
  }
  cout << pockets.size() << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
