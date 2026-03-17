#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c;
  int i, j;
  for (i = 0; i <= 10000; i++) {
    for (j = 0; j <= 10000; j++) {
      if (((i * a) + (j * b)) == c) {
        printf("Yes\n");
        return 0;
      }
    }
  }
  printf("No\n");
  return 0;
}
