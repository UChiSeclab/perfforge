#include <bits/stdc++.h>
using namespace std;
int count_bit(long long x) {
  if (x < 0) {
    return -1;
  }
  int ans = 0;
  while (x) {
    ans += (x & 1);
    x >>= 1;
  }
  return ans;
}
int main() {
  long long n, p;
  cin >> n >> p;
  for (int x = 1; x < 5000000; ++x) {
    long long m = n - p * x;
    if (m >= x && count_bit(m) <= x) {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
