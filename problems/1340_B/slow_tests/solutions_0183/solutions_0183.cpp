#include <bits/stdc++.h>
using namespace std;
vector<string> lista;
vector<string> pingo = {"1110111", "0010010", "1011101", "1011011", "0111010",
                        "1101011", "1101111", "1010010", "1111111", "1111011"};
int reachable(string s, int j) {
  string target = pingo[j];
  int ans = 0;
  for (int i = 0; i < 7; i++) {
    if (target[i] == '0' && s[i] == '1')
      return -1;
    else if (target[i] == '1' && s[i] == '0')
      ans++;
  }
  return ans;
}
int dp[2005][2005];
bool doable(int pos, int k) {
  if (dp[pos][k] != -1)
    return dp[pos][k];
  else {
    bool ans = false;
    for (int j = 0; j <= 9; j++) {
      int val = reachable(lista[pos], j);
      if (val >= 0 && val <= k) {
        ans = ans || doable(pos + 1, k - val);
      }
    }
    dp[pos][k] = ans;
    return ans;
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n, kk;
  scanf("%d %d", &n, &kk);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    lista.push_back(s);
  }
  dp[n][0] = 1;
  for (int i = 1; i < 2005; i++) {
    dp[n][i] = 0;
  }
  string ans;
  for (int i = 0; i < n; i++) {
    string s = lista[i];
    for (int j = 9; j >= 0; j--) {
      int val = reachable(s, j);
      if (val >= 0 && val <= kk && doable(i + 1, kk - val) != 0) {
        kk -= val;
        ans.push_back('0' + j);
        break;
      }
    }
  }
  if (ans.size() != n)
    puts("-1");
  else
    cout << ans << '\n';
  return 0;
}
