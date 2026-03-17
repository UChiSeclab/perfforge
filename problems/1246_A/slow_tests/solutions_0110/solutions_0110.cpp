#include <bits/stdc++.h>
using namespace std;
long long N, P;
int main() {
  scanf("%lld %lld", &N, &P);
  for (long long k = 1; k <= 5000000; k++) {
    long long R = N - k * P;
    long long L = __builtin_popcount(R);
    if (L <= k && k <= R) {
      printf("%lld\n", k);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
