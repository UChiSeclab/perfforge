#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, m, n;
  cin >> y >> m >> n;
  bool f = true;
  int x = 1;
  vector<int> a;
  for (int i = m - y; i <= n - y; i += m) {
    if ((i + y) % m == 0 && i > 0) {
      a.push_back(i);
    }
  }
  if (a.empty())
    cout << -1 << endl;
  else {
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  }
}
