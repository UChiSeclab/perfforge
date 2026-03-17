#include <bits/stdc++.h>
using namespace std;
const int MAX = 205;
int a[MAX];
bool dp[MAX];
int main() {
  int n;
  scanf("%d", &n);
  int odd = 0;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i] /= 100;
    sum += a[i];
  }
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 200; j >= 1; --j) {
      if (dp[j - a[i]]) dp[j] = 1;
    }
  }
  if (sum % 2 || !dp[sum / 2])
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
