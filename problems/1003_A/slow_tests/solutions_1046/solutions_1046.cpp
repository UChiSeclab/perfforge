#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, val;
  bool test;
  vector<int> v;
  vector<set<int>> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val;
    v.push_back(val);
  }
  for (int i = 0; i < n; i++) {
    test = false;
    for (auto& a : s) {
      if (a.count(v[i])) {
      } else {
        test = true;
        a.insert(v[i]);
        break;
      }
    }
    if (!test) {
      set<int> ss;
      ss.insert(v[i]);
      s.push_back(ss);
    }
  }
  cout << s.size() << endl;
  return 0;
}
