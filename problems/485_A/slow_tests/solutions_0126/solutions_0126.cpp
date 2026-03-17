#include <bits/stdc++.h>
using namespace std;
int a, m;
int main() {
  cin >> a >> m;
  while (a <= 10000000) {
    a += a % m;
    if (a % m == 0) {
      printf("Yes");
      return 0;
    }
  }
  printf("No");
  return 0;
}
