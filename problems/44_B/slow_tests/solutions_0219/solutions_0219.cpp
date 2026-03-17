#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int a, b, c;
  int ways;
} state;
int main() {
  int N, a, b, c;
  scanf("%d %d %d %d", &N, &a, &b, &c);
  int ways = 0;
  for (int cc = 0; cc <= min(N / 2, c); cc++) {
    if (cc * 2 > N) break;
    for (int bb = 0; bb <= min(N - cc * 2, b); bb++) {
      if (cc * 2 + bb > N) break;
      if ((N - cc * 2 - bb) * 2 <= a) ways++;
    }
  }
  printf("%d", ways);
  return 0;
}
