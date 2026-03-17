#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, m;
  cin >> a >> m;
  while (a <= 1e8) {
    a += a % m;
    if (a % m == 0) cout << "Yes", exit(0);
  }
  cout << "No" << endl;
}
