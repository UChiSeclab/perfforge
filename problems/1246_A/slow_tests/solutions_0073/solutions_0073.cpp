#include <bits/stdc++.h>
using namespace std;
int power(int a, int b, int c, int ans = 1) {
  for (; b; b >>= 1, a = (long long)a * a % c)
    if (b & 1) ans = (long long)ans * a % c;
  return ans;
}
int main() {
  long long n, p;
  cin >> n >> p;
  for (int i = 1; i < 1e7; i++) {
    long long m = n - p * i;
    if (m >= i && __builtin_popcountll(m) <= i) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
