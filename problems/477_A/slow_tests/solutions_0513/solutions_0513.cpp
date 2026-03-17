#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  while (scanf("%lld%lld", &a, &b) != -1) {
    long long t, t1;
    long long sum = 0;
    long long k1, k2;
    for (t1 = 1; t1 < b; t1++) {
      if (a % 2 == 0) {
        k1 = a / 2;
        k2 = (a * t1 + t1);
      } else {
        k1 = (a * t1 + t1) / 2;
        k2 = a;
      }
      long long p = ((((((k1 % 1000000007) * (k2 % 1000000007)) % 1000000007) %
                       1000000007) *
                      (b % 1000000007)) %
                         1000000007 +
                     (((a % 1000000007) * (t1 % 1000000007)) % 1000000007)) %
                    1000000007;
      sum = sum % 1000000007;
      sum = (p + sum) % 1000000007;
    }
    cout << sum << endl;
  }
}
