#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, n1, a;
    cin >> n;
    set<long long> s;
    n1 = n;
    if (n > 1000000) {
      n1 = 1000000;
      a = n / pow(10, 6);
      for (long long i = 1; i < a + 1; i++) s.insert(i);
    }
    for (long long i = 1; i < n1 + 1; i++) {
      s.insert(n / i);
    }
    s.insert(0);
    cout << s.size() << endl;
    for (auto i = s.begin(); i != s.end(); i++) cout << *i << " ";
    cout << endl;
  }
}
