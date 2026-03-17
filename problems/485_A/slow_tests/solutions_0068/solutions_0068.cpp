#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, m;
  cin >> a >> m;
  long long MAX = a + 9999997;
  long long cnt = 0;
  while (cnt <= MAX) {
    long long x = a % m;
    if ((x + a) % m == 0) {
      cout << "Yes" << endl;
      return 0;
    } else
      a += x;
    cnt++;
  }
  cout << "No" << endl;
  return 0;
}
