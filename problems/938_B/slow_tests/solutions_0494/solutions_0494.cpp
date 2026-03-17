#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  set<int> s;
  cin >> n;
  long long g;
  long long a, b;
  a = 1;
  b = 1000000;
  for (int c = 0; c < n; c++) {
    cin >> g;
    s.insert(g);
  }
  long long p = 0;
  long long c = 0;
  for (c;; c++) {
    if (s.find(a) != s.end()) p++;
    if (s.find(b) != s.end()) p++;
    a++;
    b--;
    if (p == n) break;
  }
  cout << c;
  return 0;
}
