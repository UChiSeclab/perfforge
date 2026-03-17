#include <bits/stdc++.h>
using namespace std;
string digits[10];
bool dp[2005][2005];
void init() {
  digits[0] = "1110111";
  digits[1] = "0010010";
  digits[2] = "1011101";
  digits[3] = "1011011";
  digits[4] = "0111010";
  digits[5] = "1101011";
  digits[6] = "1101111";
  digits[7] = "1010010";
  digits[8] = "1111111";
  digits[9] = "1111011";
  dp[0][0] = true;
}
void rewrite(vector<pair<int, int> > &oks, int index) {
  for (int i = 0; i <= 2000; i++) {
    for (auto &it : oks) {
      int value = it.second;
      if (i - value >= 0 && dp[index - 1][i - value]) {
        dp[index][i] = true;
        break;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int n, k;
  cin >> n >> k;
  string s[n];
  vector<pair<int, int> > oks[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 10; j++) {
      bool mark = true;
      int value = 0;
      for (int q = 0; q < 7; q++) {
        if (s[i][q] == '1' && digits[j][q] == '0') {
          mark = false;
          break;
        }
        if (s[i][q] != digits[j][q]) {
          value++;
        }
      }
      if (mark) {
        oks[i].emplace_back(j, value);
      }
    }
    sort(oks[i].begin(), oks[i].end());
    reverse(oks[i].begin(), oks[i].end());
    rewrite(oks[i], n - i);
  }
  if (!dp[n][k]) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = n; i > 0; i--) {
    for (auto &it : oks[n - i]) {
      int a = it.first;
      int b = it.second;
      if (dp[i - 1][k - b]) {
        cout << a;
        k -= b;
        break;
      }
    }
  }
  return 0;
}
