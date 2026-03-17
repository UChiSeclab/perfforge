#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, P;
  scanf("%d%d", &N, &P);
  for (int i = 0; i <= 1000100; i++) {
    int t = N - P * i;
    int cnt = 0;
    while (t) {
      cnt += t % 2;
      t /= 2;
    }
    if (cnt <= i && i <= N - P * i) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("-1\n");
}
