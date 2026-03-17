#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  map<long long, bool> mp;
  for (int i = 0; i <= 1000000; i++) {
    int p = b + (a * i), q = d + (i * c);
    if (mp[p]) {
      cout << p << endl;
      return 0;
    }
    mp[p] = 1;
    if (mp[q]) {
      cout << q << endl;
      return 0;
    }
    mp[q] = 1;
  }
  cout << "-1";
  return 0;
}
