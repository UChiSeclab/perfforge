#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int m, b, i, j;
  cin >> m >> b;
  long long int max = 0, ans = 0;
  for (i = 0; i <= (m * b); i = i + m) {
    ans = 0;
    long long int y = ((-i) / m) + b;
    for (j = 0; j <= y; j++) {
      ans += (i * (i + 1)) / 2;
      ans += j * (i + 1);
    }
    if (ans > max) {
      max = ans;
    }
  }
  cout << max << endl;
  return 0;
}
