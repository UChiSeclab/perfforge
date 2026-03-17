#include <bits/stdc++.h>
using namespace std;
const signed long long Infinity = 1000000100;
const long double Epsilon = 1e-9;
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  for (int(i) = (0); (i) <= (10000); (i)++)
    for (int(j) = (0); (j) <= (10000); (j)++) {
      if (a * i + b * j == c) {
        printf("Yes\n");
        return 0;
      }
    }
  printf("No\n");
  return 0;
}
