#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int sum = 0, sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      sum += k;
      if (k == 100) {
        sum1++;
      } else {
        sum2++;
      }
    }
    if (n == 1) {
      puts("NO");
      continue;
    }
    if (sum % 2 != 0) {
      puts("NO");
      continue;
    }
    int k = sum / 2;
    int flag = 0;
    for (int i = 0; i <= sum1; i++) {
      for (int j = 0; j <= sum2; j++) {
        if (i * 100 + j * 200 == k) {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (flag) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
