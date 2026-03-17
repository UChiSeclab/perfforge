#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int dp[N][2];
int arr[10];
string ans;
void build(int l) {
  if (dp[l][1] == -1) {
    cout << -1 << endl;
    return;
  }
  while (dp[l][1] != -1) {
    cout << dp[l][1] + 1;
    l -= arr[dp[l][1]];
  }
}
int rec(int l) {
  if (dp[l][0] != -1) return dp[l][0];
  for (int i = 8; i >= 0; i--) {
    if (l >= arr[i]) {
      int k = rec(l - arr[i]) + 1;
      if (k > dp[l][0]) dp[l][0] = k, dp[l][1] = i;
    }
  }
  if (dp[l][0] == -1) return 0;
  return dp[l][0];
}
int main() {
  int l;
  cin >> l;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < 9; i++) cin >> arr[i];
  rec(l), build(l);
}
