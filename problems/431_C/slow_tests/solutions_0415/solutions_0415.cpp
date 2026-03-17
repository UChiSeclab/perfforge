#include <bits/stdc++.h>
using namespace std;
int n, k, d;
long long arr[101][101][2];
long long dp(long long sum, int num, int Bool) {
  if (sum > n) return 0;
  long long &ret = arr[sum][num][Bool];
  if (ret != -1) return ret;
  if (num >= d) Bool = 1;
  if (sum == n && Bool == 0)
    return 0;
  else if (sum == n && Bool == 1)
    return 1;
  long long temp = 0;
  for (int i = 1; i <= k; i++) {
    temp = ((dp(sum + i, i, Bool) % 1000000007) + temp) % 1000000007;
    ;
  }
  return ret = temp;
}
int main() {
  cin >> n >> k >> d;
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      for (int k = 0; k < 2; k++) {
        arr[i][j][k] = -1;
      }
    }
  }
  cout << dp(0, 1, 0) << endl;
  return 0;
}
