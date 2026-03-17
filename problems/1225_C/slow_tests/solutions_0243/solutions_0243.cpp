#include <bits/stdc++.h>
using namespace std;
const long long P = 1e8;
long long n, p;
long long deg(long long k) {
  long long a = 0;
  while (k > 0) {
    a += k % 2;
    k /= 2;
  }
  return a;
}
int main() {
  cin >> n >> p;
  long long ans = -1;
  for (long long i = 1; i <= P; i++) {
    long long k = n - i * p;
    if (k <= 0 || k < i) {
      continue;
    }
    long long cnt = deg(k);
    if (cnt <= i) {
      ans = i;
      break;
    }
  }
  cout << ans;
  return 0;
}
