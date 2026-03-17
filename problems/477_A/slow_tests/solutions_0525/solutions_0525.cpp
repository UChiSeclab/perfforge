#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, p, d, num, sum;
  cin >> a >> b;
  long long i;
  sum = 0;
  for (i = 1; i < b; i++) {
    long long k = (i * b + i) * 2;
    int flag = 0;
    if (a % 2 == 0) {
      p = a / 2;
      flag = 1;
    } else {
      p = a;
    }
    if (flag == 0) {
      k = k / 2;
      num = (a - 1) / 2;
      flag = 1;
    } else {
      num = (a - 1);
    }
    d = (k + ((((num)*b) % 1000000007) * i) % 1000000007) % 1000000007;
    sum += (p * d) % 1000000007;
    sum = sum % 1000000007;
  }
  cout << sum << endl;
  return 0;
}
