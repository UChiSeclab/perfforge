#include <bits/stdc++.h>
using namespace std;
int a, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> m;
  for (int i = 1; i <= 10000000; i++) {
    a = (a + a) % m;
    if (a == 0) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}
