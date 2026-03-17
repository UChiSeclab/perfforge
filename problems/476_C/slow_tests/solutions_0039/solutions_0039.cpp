#include <bits/stdc++.h>
using namespace std;
long long int powmod(long long int a, int b, int n) {
  long long int rm = 1;
  while (b) {
    if (b % 2) {
      rm = (rm * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return rm;
}
int main() {
  long long int a, b, k, tsum = 0, sum2 = 0;
  cin >> a >> b;
  for (long long int i = 1; i < b; ++i) {
    sum2 = (a * (a + 1)) / 2;
    sum2 %= int(1e9 + 7);
    sum2 = (sum2 * i) % int(1e9 + 7);
    sum2 = (sum2 * b) % int(1e9 + 7);
    sum2 = (sum2 + (i * a) % int(1e9 + 7)) % int(1e9 + 7);
    tsum = (tsum + sum2) % int(1e9 + 7);
  }
  cout << tsum << endl;
  return 0;
}
