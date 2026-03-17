#include <bits/stdc++.h>
using namespace std;
int rt, bucket[100010], a[100010], d[100], N, D[100], k, n;
int div(int x) {
  int res = 0;
  for (int i = 2; i <= x; i++) {
    int cnt = 0;
    while (x % i == 0) {
      cnt++;
      x /= i;
    }
    if (cnt % k) D[++res] = i, d[res] = cnt % k;
  }
  return res;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    N = div(a[i]);
    int qwq = 1;
    int qaq = 1;
    int flag = 1;
    for (int j = 1; j <= N; j++) {
      for (int l = 1; l <= d[j]; l++) {
        qwq *= D[j];
      }
      for (int l = d[j]; l < k; l++) {
        qaq *= D[j];
        if (qaq < 0 || qaq > 100000) flag = 0;
      }
    }
    if (flag) ans += bucket[qaq];
    bucket[qwq]++;
  }
  cout << ans << endl;
  return 0;
}
