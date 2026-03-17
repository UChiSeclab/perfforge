#include <bits/stdc++.h>
using namespace std;
const int N = (int)100 + 5;
const int inf = 0x3f3f3f3f;
long long dp[N][N][2][N];
long long ans[N][N];
char s[N];
int a[N];
long long calcAns(int l, int r);
inline long long calcDp(int l, int r, int dig, int cnt) {
  long long& ret = dp[l][r][dig][cnt];
  if (ret != -1) {
    return ret;
  }
  if (cnt == 0) {
    return ret = calcAns(l, r);
  }
  ret = -(long long)1e15;
  for (int mid = l; mid <= r; mid++) {
    if (s[mid] - '0' == dig) {
      ret = max(ret, calcAns(l, mid - 1) + calcDp(mid + 1, r, dig, cnt - 1));
    }
  }
  return ret;
}
inline long long calcAns(int l, int r) {
  long long& ret = ans[l][r];
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  for (int cnt = 1; cnt <= r - l + 1; cnt++) {
    ret = max(ret, a[cnt] + calcDp(l, r, 0, cnt));
    ret = max(ret, a[cnt] + calcDp(l, r, 1, cnt));
  }
  return ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  memset(ans, -1, sizeof(ans));
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  printf("%lld\n", calcAns(1, n));
  return 0;
}
