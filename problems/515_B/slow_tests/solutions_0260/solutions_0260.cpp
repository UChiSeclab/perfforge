#include <bits/stdc++.h>
using namespace std;
int hbb[109], hgg[109];
int main() {
  int n, m, a, b, hb, hg, i;
  scanf("%d %d", &n, &m);
  scanf("%d", &hb);
  memset(hbb, 0, sizeof(hbb));
  for (i = 0; i < hb; i++) {
    scanf("%d", &a);
    hbb[a] = 1;
  }
  scanf("%d", &hg);
  memset(hgg, 0, sizeof(hgg));
  for (i = 0; i < hg; i++) {
    scanf("%d", &a);
    hgg[a] = 1;
  }
  int flag = 1;
  for (i = 0; i <= 1000000; i++) {
    if (hg == m && hb == n) {
      flag = 0;
      break;
    }
    a = i % n;
    b = i % m;
    if (hbb[a]) {
      if (hgg[b] == 0) {
        hgg[b] = 1;
        hg++;
      }
    } else if (hgg[b]) {
      if (hbb[a] == 0) {
        hbb[a] = 1;
        hb++;
      }
    }
  }
  printf("%s\n", flag ? "No" : "Yes");
  return 0;
}
