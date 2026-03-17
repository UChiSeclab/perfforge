#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int d = mod / 2 + 1;
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (long long int)a * b % mod; }
int main() {
  long long int a, b;
  scanf("%lld%lld", &a, &b);
  long long int ans = 0;
  for (long long int m = 1; m < b; m++) {
    long long int sum_t = mul(mul(mul(m, a + 1), a), d);
    long long int cur_add = mul(b, sum_t) + mul(m, a);
    cur_add %= mod;
    ans = add(ans, cur_add);
  }
  printf("%lld\n", ans);
  return 0;
}
