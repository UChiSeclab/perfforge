#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main(void) {
  std::ios::sync_with_stdio(false);
  long long a2, a3, a5, a6;
  cin >> a2 >> a3 >> a5 >> a6;
  long long sum = 0;
  while (1) {
    if (a2 >= 1 && a5 >= 1 && a6 >= 1) {
      sum += 256;
      a2--, a5--, a6--;
    } else if (a2 >= 1 && a3 >= 1) {
      sum += 32;
      a2--, a3--;
    } else
      break;
  }
  cout << sum << endl;
  return 0;
}
