#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  while (~scanf("%d%d%d", &a, &b, &c)) {
    int i, j;
    int isok = 0;
    for (i = 0; i < 10000; ++i) {
      for (j = 0; j < 10000; ++j) {
        int fuck = a * i + b * j;
        if (i == 0 && j == 0) continue;
        if (fuck > c) continue;
        if (c % fuck == 0) {
          isok = 1;
          goto c;
        }
      }
    }
  c:;
    if (isok)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
