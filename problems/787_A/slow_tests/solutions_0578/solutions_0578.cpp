#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long c, d;
  cin >> c >> d;
  for (long long i = 0; i <= 1e4; i++) {
    for (long long j = 0; j <= 1e4; j++) {
      if (b + a * i == d + c * j) {
        cout << b + a * i << "\n";
        return 0;
      }
    }
  }
  cout << -1 << "\n";
}
