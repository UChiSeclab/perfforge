#include <bits/stdc++.h>
using namespace std;
int a, b, k;
int sum[1000050];
bool isPrime(int x) {
  if (x < 2) return 0;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
bool check(int x) {
  for (int i = a + x - 1; i <= b; i++)
    if (sum[i] - sum[i - x] < k) return 0;
  return 1;
}
int main() {
  scanf("%d%d%d", &a, &b, &k);
  sum[a - 1] = 0;
  for (int i = a; i <= b; i++)
    if (isPrime(i))
      sum[i] = sum[i - 1] + 1;
    else
      sum[i] = sum[i - 1];
  if (sum[b] - sum[a - 1] < k) {
    printf("-1\n");
    return 0;
  }
  int l = 0, r = b - a + 1, m;
  while (r - l > 1) {
    m = (l + r) >> 1;
    if (check(m))
      r = m;
    else
      l = m;
  }
  printf("%d\n", r);
  return 0;
}
