#include <bits/stdc++.h>
using namespace std;
int m, s;
bool dp[1001][200], dp2[1001][200];
string solve(string curAns, int curSum, int curPos) {
  if (curSum > s) return "-1";
  if (dp[curSum][curPos]) return "-1";
  dp[curSum][curPos] = true;
  if (curPos == m) {
    if (curSum == s) return curAns;
    return "-1";
  }
  for (int i = 9; i >= 0; i--) {
    if (curPos == 0 && m > 1 && i == 0) continue;
    char num = i + '0';
    string ret = solve(curAns + num, curSum + i, curPos + 1);
    if (ret != "-1") return ret;
  }
  return "-1";
}
string solve2(string curAns, int curSum, int curPos) {
  if (curSum > s) return "-1";
  if (dp2[curSum][curPos]) return "-1";
  dp2[curSum][curPos] = true;
  if (curPos == m) {
    if (curSum == s) return curAns;
    return "-1";
  }
  for (int i = 0; i <= 9; i++) {
    if (i == 0 && curPos == 0 && m > 1) continue;
    char num = i + '0';
    string ret = solve2(curAns + num, curSum + i, curPos + 1);
    if (ret != "-1") return ret;
  }
  return "-1";
}
int main() {
  cin >> m >> s;
  cout << solve2("", 0, 0) << " " << solve("", 0, 0) << endl;
  return 0;
}
