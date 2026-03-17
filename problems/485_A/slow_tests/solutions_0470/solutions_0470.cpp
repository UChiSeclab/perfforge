#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, m;
  cin >> a >> m;
  int t = 10000000;
  while (t--) {
    if (a % m == 0) {
      cout << "Yes" << endl;
      return 0;
    }
    a += (a % m);
  }
  cout << "No" << endl;
  return 0;
}
