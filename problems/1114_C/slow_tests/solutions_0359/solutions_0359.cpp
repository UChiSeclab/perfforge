#include <bits/stdc++.h>
using namespace std;
long long n, b, key, k, num[10005][2], ans, cnt, step;
int main() {
  while (cin >> n >> b) {
    memset(num, 0, sizeof(num));
    key = b;
    k = 0;
    int flag;
    for (long long i = 2; i <= sqrt(b); i++) {
      flag = 0;
      while (key % i == 0) {
        num[k][0] = i;
        num[k][1]++;
        key = key / i;
        flag = 1;
      }
      if (flag) {
        k++;
      }
    }
    if (key != 1) {
      num[k][0] = key;
      num[k][1] = 1;
      k++;
    }
    ans = 1;
    ans = ans << 60;
    for (long long i = 0; i < k; i++) {
      step = n;
      cnt = 0;
      while (step) {
        step = step / num[i][0];
        cnt = cnt + step;
      }
      ans = min(ans, cnt / num[i][1]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
