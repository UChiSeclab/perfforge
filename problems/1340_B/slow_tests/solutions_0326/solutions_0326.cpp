#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 100;
int dist[2006][15], ans[2005];
vector<int> v[2005];
int dp[2006][2005], pre[2005][2006], num[2005][2005];
char arr[2005][15];
char str[15][15] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                    "1101011", "1101111", "1010010", "1111111", "1111011"};
int calc(char a[], char b[]) {
  int ret = 0;
  for (int i = 0; i < 7; i++) {
    if (a[i] == '0' && b[i] == '1')
      ret++;
    else if (a[i] == b[i])
      ;
    else {
      ret = 0x3f3f3f3f;
      break;
    }
  }
  return ret;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%s", arr[i]);
  for (int i = 0; i < n; i++) {
    int now = 0x3f3f3f3f;
    for (int j = 0; j <= 9; j++) dist[i][j] = calc(arr[i], str[j]);
  }
  memset(pre, -1, sizeof(pre));
  dp[n][0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 2000; j >= 0; j--) {
      for (int k = 0; k <= 9; k++) {
        if (j - dist[i][k] >= 0 && dp[i + 1][j - dist[i][k]]) {
          dp[i][j] = 1, pre[i][j] = j - dist[i][k], num[i][j] = k;
        }
      }
    }
  }
  if (dp[0][k]) {
    int tot = 0;
    int nowa = 0, nowb = k;
    while (nowa < n) {
      ans[++tot] = num[nowa][nowb];
      nowb = pre[nowa][nowb];
      nowa++;
    }
    for (int i = 1; i <= tot; i++) printf("%d", ans[i]);
    printf("\n");
  } else
    printf("-1\n");
  return 0;
}
