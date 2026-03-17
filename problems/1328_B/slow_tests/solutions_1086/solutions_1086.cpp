#include <bits/stdc++.h>
using namespace std;
long long test;
int32_t main() {
  std::cin >> test;
  while (test--) {
    long long n, k;
    std::cin >> n >> k;
    string str(n, 'a');
    for (long long i = n - 2; i >= 0; i--) {
      if (k <= n - i - 1) {
        str[i] = 'b';
        str[n - k] = 'b';
        break;
      } else
        k -= (n - i - 1);
    }
    std::cout << str << '\n';
  }
  return 0;
}
