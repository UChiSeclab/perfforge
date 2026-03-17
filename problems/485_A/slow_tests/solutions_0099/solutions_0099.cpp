#include <bits/stdc++.h>
using std::cin;
using std::cout;
int main() {
  int a, m;
  cin >> a >> m;
  a %= m;
  bool can = false;
  for (int i = 0; i < 1e7; i++) {
    a *= 2;
    if (a >= m) a -= m;
    if (a == 0) {
      can = true;
      break;
    }
  }
  if (can)
    cout << "Yes";
  else
    cout << "No";
  cout << '\n';
  return 0;
}
