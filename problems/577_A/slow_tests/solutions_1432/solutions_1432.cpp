#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  int k = 0;
  for (int i = 1; i <= pow(x, 0.5); i++) {
    if (x % i == 0 && i != pow(x, 0.5) && x / i <= n)
      k = k + 2;
    else if (x % i == 0 && i == pow(x, 0.5) && x / i <= n)
      k = k + 1;
  }
  printf("%d\n", k);
  ;
  return 0;
}
