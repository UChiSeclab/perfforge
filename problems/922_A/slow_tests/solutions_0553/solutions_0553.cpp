#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, cp, k, i, org;
  cin >> a >> b;
  if (b == 0) {
    cout << "No" << endl;
    return 0;
  }
  org = b;
  cp = b - 1;
  while (cp > 0 && cp < a) {
    cp += 2;
  }
  if (a == cp && b == org) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
