#include <bits/stdc++.h>
using namespace std;
int tests;
long long high(long long n) { return (n * (3 * n + 1)) / 2; }
int main() {
  tests = 1;
  cin >> tests;
  while (tests--) {
    long long n;
    cin >> n;
    long long ans = 0;
    for (int i = 100000; i > 0; i--) {
      long long x = high(i);
      while (x <= n) {
        ans++;
        n = n - x;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
