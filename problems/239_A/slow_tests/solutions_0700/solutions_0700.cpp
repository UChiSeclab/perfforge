#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int main() {
  int y, k, n;
  cin >> y >> k >> n;
  vector<int> ans;
  for (int i = 0; i <= n / k; i++) {
    int num = i * k;
    if (num <= y) continue;
    ans.push_back(num - y);
  }
  if ((int)ans.size() == 0)
    cout << -1 << endl;
  else {
    for (int x : ans) cout << x << ' ';
    cout << endl;
  }
  return 0;
}
