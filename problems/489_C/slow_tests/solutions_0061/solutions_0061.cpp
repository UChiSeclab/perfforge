#include <bits/stdc++.h>
using namespace std;
class pair_hasher {
 public:
  int operator()(pair<int, int> p) const { return p.first ^ p.second; }
};
string dp(int i, int j, int m, int s, vector<vector<string>> &table,
          const string &digits) {
  if (i < 0 || j < 0) {
    return "-1";
  }
  if (i == 0) {
    if (j == 0) {
      return "";
    } else {
      return "-1";
    }
  }
  if (table[i][j] == "") {
    table[i][j] = "-1";
    for (auto digit : digits) {
      auto result = dp(i - 1, j - digit + '0', m, s, table, digits);
      if (result != "-1") {
        table[i][j] = (digit + result);
        break;
      }
    }
  }
  return table[i][j];
}
int main() {
  int m, s;
  scanf("%d %d", &m, &s);
  if (m == 1 && s == 0) {
    printf("0 0 \n");
    return 0;
  }
  string digits = "0123456789";
  vector<vector<string>> min_dp(m, vector<string>(s, ""));
  string min_answer = "-1";
  for (int i = 1; i < digits.size(); i++) {
    string result = dp(m - 1, s - digits[i] + '0', m, s, min_dp, digits);
    if (result != "-1") {
      min_answer = digits[i] + result;
      break;
    }
  }
  reverse(digits.begin(), digits.end());
  string max_answer = "-1";
  for (int i = 0; i < digits.size() - 1; i++) {
    string result = dp(m - 1, s - digits[i] + '0', m, s, min_dp, digits);
    if (result != "-1") {
      max_answer = digits[i] + result;
      break;
    }
  }
  printf("%s %s\n", min_answer.c_str(), max_answer.c_str());
  return 0;
}
