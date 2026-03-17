#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b, c = 10000000;
  bool found = false;
  cin >> a >> b;
  while (c--) {
    if (a % b == 0) {
      found = true;
      break;
    }
    a += (a % b);
  }
  if (found)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
