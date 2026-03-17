#include <bits/stdc++.h>
using namespace std;
int n, k;
map<int, int> m1;
map<int, int> m2;
int a[101], b[101], c[101], d[101];
int dp1[100001], dp2[100001];
int main() {
  memset(dp1, -0x3f3f3f3f, sizeof(dp1));
  memset(dp2, -0x3f3f3f3f, sizeof(dp2));
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int l1 = 1, l2 = 1;
  int max1 = 0, max2 = 0;
  for (int i = 1; i <= n; i++) {
    int x = a[i] - k * b[i];
    if (x >= 0) {
      m1[l1] = i;
      max1 += x;
      c[l1] = x;
      l1++;
    } else if (x < 0) {
      m2[l2] = i;
      max2 += -x;
      d[l2] = -x;
      l2++;
    }
  }
  dp1[0] = 0;
  dp2[0] = 0;
  for (int i = 1; i < l1; i++) {
    for (int j = max1; j >= c[i]; j--) {
      dp1[j] = max(dp1[j], dp1[j - c[i]] + a[m1[i]]);
    }
  }
  for (int i = 1; i < l2; i++) {
    for (int j = max2; j >= d[i]; j--) {
      dp2[j] = max(dp2[j], dp2[j - d[i]] + a[m2[i]]);
    }
  }
  int ans = -1;
  for (int i = 1; i <= max(max1, max2); i++) {
    ans = max(ans, dp1[i] + dp2[i]);
  }
  if (dp1[0] != 0) ans = max(ans, dp1[0]);
  cout << ans << endl;
}
