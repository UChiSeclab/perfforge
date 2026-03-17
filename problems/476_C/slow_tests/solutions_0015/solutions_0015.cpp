#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
int main() {
  long long int a, b, re, sum = 0;
  scanf("%lld", &a);
  scanf("%lld", &b);
  long long int ff = (a * (a + 1)) / 2;
  ff %= 1000000007;
  for (long long int i = 1; i < b; i++) {
    sum += i * a + ((i * b) % 1000000007 * ff) % 1000000007;
    sum %= 1000000007;
  }
  printf("%lld ", sum);
  printf("\n");
}
