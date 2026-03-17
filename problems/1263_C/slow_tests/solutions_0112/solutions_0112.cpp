#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    if (n == 1) {
      cout << 2 << endl;
      cout << 0 << " " << 1 << endl;
      continue;
    }
    set<int> s;
    set<int>::iterator it;
    for (i = 1; i <= sqrt(n) + 1; i++) {
      if (s.find(n / i) == s.end()) {
        s.insert(i);
        if (i != n / i) s.insert(n / i);
      }
    }
    s.insert(0);
    cout << s.size() << endl;
    for (it = s.begin(); it != s.end(); it++) cout << *it << " ";
    cout << endl;
  }
  return 0;
}
