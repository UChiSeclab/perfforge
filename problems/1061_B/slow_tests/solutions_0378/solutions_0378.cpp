#include <bits/stdc++.h>
using namespace std;
long long int a[100001];
int main() {
  long long int n, m, i, Ans = 0, sum = 0, cnt;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    sum += a[i];
  }
  if (n == 1) {
    cout << 0;
    return 0;
  }
  sort(a, a + n);
  cnt = 1;
  Ans = 1;
  for (i = 1; i < n; i++) {
    if (a[i] == cnt)
      Ans++;
    else if (a[i] > cnt && i == n - 1)
      Ans += a[i] - cnt;
    else if (a[i] > cnt && i < n - 1) {
      Ans++;
      cnt++;
    }
  }
  cout << sum - Ans << endl;
  return 0;
}
